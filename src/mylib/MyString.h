#include <stdlib.h>

class MyString
{
public:
    MyString(const char *buffer = "") noexcept;
    explicit MyString(size_t reserve) noexcept;
    explicit MyString(const MyString &other) = delete;
    explicit MyString(MyString &&other) noexcept;
    MyString &operator=(const MyString &other) = delete;
    MyString &operator=(MyString &&other) noexcept;
    virtual ~MyString() noexcept;

    size_t size() const noexcept
    {
        return m_size;
    }

    static MyString clone(const MyString &other) noexcept;

private:
    size_t m_size{0};
    size_t m_capacity{0};
    char *m_buffer{nullptr};
};
