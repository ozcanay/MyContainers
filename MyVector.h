#pragma once

#include <cstddef>
#include <iostream>

template<typename T>
class MyVector {
private:
    T* data_ = nullptr;
    std::size_t size_ = 0;
    std::size_t capacity_ = 0;

    using type     = T;
    using iterator = T*;
    using const_iterator = const T*;
    using pointer  = T*;
public:
    MyVector()
    {
        realloc(2);
    }

    ~MyVector()
    {
        clear();
        operator delete(data_, capacity_ * sizeof(T));
    }

    void realloc(std::size_t new_capacity)
    {
//        T* chunk = new T[new_capacity];
        T* chunk = static_cast<T*>(operator new(new_capacity * sizeof(T)));

        /// if we are downsizing update the size variable first so we do not go out of bounds in for loop below.
        /// capacity must always be larger than or equal to the size!
        if(new_capacity < size_) {
            size_ = new_capacity;
        }

        /// we must not use memcpy here, since it will not invoke constructors for non-trivial types!
        for(std::size_t i = 0; i < size(); ++i) {
            /// You can't use assignment operator here (either move or copy) because chunk[i] is uninitialized memory
            /// it is not the object of type T and by calling operator= (again move or not) you treat it as if it is object of type T.
//            chunk[i] = std::move(data_[i]);
            new (&chunk[i]) T(std::move(data_[i]));
        }

        for(std::size_t i = 0; i < size(); ++i) {
            data_[i].~T();
        }

        /// jsut deallocating, not calling the destructor.
        operator delete(data_, capacity_ * sizeof(T));
//        delete[] data_;

        data_ = chunk;
        capacity_ = new_capacity;
    }

    [[nodiscard]] std::size_t size() const noexcept
    {
        return size_;
    }

    void push_back(const T& value)
    {
        if(size_ >= capacity_) {
            realloc(capacity_ * 2);
        }

        data_[size_++] = std::move(value);
    }

    void push_back(const T&& value)
    {
        if(size_ >= capacity_) {
            realloc(capacity_ * 2);
        }

        data_[size_++] = value;
    }

    template<typename... Args>
    T& emplace_back(Args&&... args)
    {
        if(size_ >= capacity_) {
            realloc(capacity_ * 2);
        }

        /// important part.
        /// correct approach with placement new operator. space is already allocated and we want to
        /// construct in-place where the space resides.
        new(&data_[size_]) T(std::forward<Args>(args)...);

        //data_[size_] = T(std::forward<Args>(args)...); -> this is wrong, this moves and destroys

        return data_[size_++];
    }

    void pop_back()
    {
        if(size_ > 0) {
            size_--;
            data_[size_].~T();
        }
    }

    void clear()
    {
        for(std::size_t i = 0; i < size(); ++i) {
            data_[i].~T();
        }

        size_ = 0;
    }

    const T& operator[](std::size_t index) const noexcept
    {
        return data_[index];
    }

    T& operator[](std::size_t index) noexcept
    {
        return data_[index];
    }

    T* data() {
        return data_;
    }

    const T* data() const {
        return data_;
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
        return data() + size_;
    }

    constexpr iterator end() noexcept
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return data() + size_;
    }
};

