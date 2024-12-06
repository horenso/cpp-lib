
#include <utility>
#include <iostream>

template <typename T>
class MyUniquePtr
{
private:
    T *m_ptr{nullptr};

public:
    template <typename... Args>
    explicit MyUniquePtr(Args &&...args)
        : m_ptr(new T(std::forward<Args>(args)...)) {}

    ~MyUniquePtr() { delete m_ptr; }
    // copy
    explicit MyUniquePtr(const MyUniquePtr &other) = delete;
    // move
    explicit MyUniquePtr(MyUniquePtr &&other)
    {
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }

    MyUniquePtr &operator=(MyUniquePtr &other) = delete;
    MyUniquePtr &operator=(MyUniquePtr &&other)
    {
        if (m_ptr != other.m_ptr)
        {
            delete m_ptr;
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
        }
        return *this;
    }

    T *get()
    {
        return m_ptr;
    }

    explicit operator bool() const
    {
        return m_ptr != nullptr;
    }
};

struct MyStruct
{
    int a;
    int b;

    MyStruct(int a, int b) : a(a), b(b)
    {
        std::cout << "MyStruct constructor.\n";
    }
};

int main()
{
    using UniqueIntPtr = MyUniquePtr<int>;

    UniqueIntPtr a(54);
    UniqueIntPtr b(54);

    UniqueIntPtr c(static_cast<UniqueIntPtr &&>(a));
    a = static_cast<UniqueIntPtr &&>(b);
    a = static_cast<UniqueIntPtr &&>(a);

    std::cout << "value: " << *c.get() << "\n";

    MyStruct my_struct{1, 2};
    MyUniquePtr<MyStruct>(1, 2);
}
