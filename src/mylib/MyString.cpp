#include "MyString.h"

#include <memory>

#include <cstring>
#include <cassert>

MyString::MyString(const char *buffer) noexcept
{
    assert(buffer != nullptr);
    m_size = std::strlen(buffer);
    m_capacity = m_size + 1;
    m_buffer = new char[m_capacity];
    std::memcpy(m_buffer, buffer, m_capacity);
}

MyString::MyString(size_t reserve) noexcept : m_size(0), m_capacity(reserve), m_buffer(new char[reserve])
{
}

MyString::MyString(MyString &&other) noexcept
{
    m_buffer = other.m_buffer;
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    other.m_buffer = nullptr;
    other.m_size = 0;
    other.m_capacity = 0;
}

MyString MyString::clone(const MyString &other) noexcept
{
    return MyString(other.m_buffer);
}

MyString &MyString::operator=(MyString &&other) noexcept
{
    if (other.m_buffer != m_buffer)
    {
        if (m_buffer != nullptr)
        {
            delete m_buffer;
        }
        m_buffer = other.m_buffer;
        other.m_buffer = nullptr;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
    }
    return *this;
}

MyString::~MyString() noexcept
{
    delete m_buffer;
}
