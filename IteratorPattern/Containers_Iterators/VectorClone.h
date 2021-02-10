#pragma once
#include <cstring>
#include <iostream>
template <class VectorClone>
class VectorCloneIterator
{
public:
    using ValueType = typename VectorClone::ValueType;

private:
    ValueType *ptr;

public:
    VectorCloneIterator()
        : ptr(nullptr)
    {
    }

    VectorCloneIterator(ValueType *ptrType)
        : ptr(ptrType)
    {
        std::cout << "Constr. called \n";
    }

    VectorCloneIterator operator++()
    {
        this->ptr++;
        return *this;
    }

    VectorCloneIterator operator++(int)
    {
        VectorCloneIterator iter = *this;
        this->ptr++;
        return iter;
    }

    bool operator!=(const VectorCloneIterator &other)
    {
        return this->ptr != other.ptr;
    }

    ValueType operator*()
    {
        return *ptr;
    }
};

template <class Typ>
class VectorClone
{
public:
    using Iterator = VectorCloneIterator<VectorClone<Typ>>;
    using ValueType = Typ;

private:
    Typ *arr;
    size_t capacity;
    size_t curSize;

public:
    VectorClone() : curSize(0), capacity(0)
    {
        arr = new Typ[capacity];
    }
    ~VectorClone()
    {
        delete[] arr;
    }
    void push_back(Typ typ)
    {
        if (curSize == capacity)
        {
            Typ *tempArr = new Typ[curSize];
            memcpy(tempArr, arr, curSize * sizeof(Typ));
            delete[] arr;

            capacity = capacity == 0 ? 1 : capacity * 2;

            arr = new Typ[capacity];
            memcpy(arr, tempArr, curSize * sizeof(Typ));

            delete[] tempArr;
            tempArr = nullptr;
        }
        arr[curSize] = typ;
        curSize++;
    }
    inline size_t size() const
    {
        return curSize;
    }
    void clear()
    {
        curSize = 0;
        capacity = 0;
    }
    Typ &operator[](int pos)
    {
        return arr[pos];
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