#pragma once

#include <cstddef> /// std::size_t
#include <cassert> /// assert()
#include <iostream>

/*
 * C++ std::array
 * https://en.cppreference.com/w/cpp/container/array
 */

template<typename T, std::size_t _size>
class MyArray {
private:
    T data_[_size];
public:
    using type     = T;
    using iterator = T*;
    using const_iterator = const T*;
    using pointer  = T*;

    /// important that this is a reference. Otherwise there would be a performance hit if we were to store large objects, they would be copied every time they are accessed.
    T& operator[](std::size_t index) {
        assert(index < _size);

        return data_[index];
    }

    [[nodiscard]] constexpr std::size_t size() const noexcept {
        return _size;
    }

    [[nodiscard]] constexpr bool empty() const noexcept
    {
        return size() == 0;
    }

    T* data() {
        return data_;
    }

    const T* data() const {
        return data_;
    }

    T& front() {
        data_[0];
    }

    T& back() {
        data_[_size - 1];
    }

    constexpr const_iterator begin() const noexcept
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return data();
    }

    constexpr iterator begin() noexcept
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return data();
    }

    constexpr const_iterator end() const noexcept
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return data() + _size;
    }

    constexpr iterator end() noexcept
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return data() + _size;
    }

    constexpr const_iterator cbegin() const noexcept
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return const_iterator(data());
    }

    constexpr const_iterator cend() const noexcept
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return const_iterator(data() + _size);
    }
};

