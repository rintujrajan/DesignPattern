#pragma once
#include <iostream>
#include <cstring>

template <typename MyVector>
class MyVectorIterator
{
public:
    using ValueType = typename MyVector::ValueType;
    using PointerType = ValueType *;
    using ReferenceType = ValueType &;

private:
    PointerType m_Ptr;

public:
    MyVectorIterator() : m_Ptr(nullptr){};
    MyVectorIterator(PointerType ptr) : m_Ptr(ptr){};

    MyVectorIterator &operator++() //++it
    {
        m_Ptr++;
        return *this;
    }

    MyVectorIterator operator++(int) //it++
    {
        MyVectorIterator iter = *this;
        ++(*this);
        return iter;
    }

    MyVectorIterator &operator--()
    {
        m_Ptr--;
        return *this;
    }

    MyVectorIterator operator--(int)
    {
        MyVectorIterator iter = *this;
        --(*this);
        return iter;
    }

    ReferenceType operator[](int index)
    {
        return *(m_Ptr + index);
    }

    PointerType operator->()
    {
        return m_Ptr;
    }

    ReferenceType operator*()
    {
        return *m_Ptr;
    }

    bool operator==(const MyVectorIterator &other) const
    {
        return m_Ptr == other.m_Ptr;
    }
    bool operator!=(const MyVectorIterator &other) const
    {
        // return !(*this == other);
        return m_Ptr != other.m_Ptr;
    }
};

template <class Typ>
class MyVector
{
public:
    using ValueType = Typ;
    using Iterator = MyVectorIterator<MyVector<Typ>>;

private:
    Typ *arr;
    size_t curSize;
    size_t curCapacity;

public:
    MyVector() : curSize(0), curCapacity(0)
    {
        arr = new Typ[curCapacity];
    }
    MyVector(size_t capacity) : curSize(0), curCapacity(capacity)
    {
        arr = new Typ[curCapacity];
    }
    ~MyVector()
    {
        delete[] arr;
    }
    void push_back(Typ data)
    {
        if (curSize == curCapacity)
        {
            // re-allocate memory and copy the contents
            std::cout << "Reallocating memory since CurCapacity : " << curCapacity
                      << " and CurSize : " << curSize << "\n";
            Typ *tempArr = new Typ[curSize];
            std::memcpy(tempArr, arr, curSize * sizeof(Typ));
            delete[] arr;
            size_t newCapacity = curCapacity == 0 ? 1 : curCapacity * 2;
            std::cout << "Increasing capacity from " << curCapacity << " to " << newCapacity << "\n";
            arr = new Typ[newCapacity];
            std::memcpy(arr, tempArr, curSize * sizeof(Typ));
            delete[] tempArr;
            tempArr = nullptr;
            curCapacity = newCapacity;
        }
        arr[curSize] = data;
        curSize++;
    }
    Typ &operator[](int pos)
    {
        return arr[pos];
    }
    void clear()
    {
        curSize = 0;
        curCapacity = 0;
        delete[] arr;
        arr = new Typ[curCapacity];
    }
    inline size_t size()
    {
        return curSize;
    }

    Iterator begin()
    {
        return Iterator(arr);
    }

    Iterator end()
    {
        return Iterator(arr + curSize);
    }
};
