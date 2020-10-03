#pragma once
#include <iostream>
namespace
{
    const size_t DEFAULT_VEC_CAPACITY = 10;
}

template <typename MyVector>
class MyVectorIterator
{
public:
    using ValueType  = typename MyVector::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;

private:
    PointerType m_Ptr;

public:
    MyVectorIterator():m_Ptr(nullptr){};
    MyVectorIterator(PointerType ptr):m_Ptr(ptr){};

    MyVectorIterator& operator++()
    {
        m_Ptr++;
        return *this;
    }

    MyVectorIterator operator++(int)
    {
        MyVectorIterator iter = *this;
        ++(*this);
        return iter;
    }

    MyVectorIterator& operator--()
    {
        m_Ptr--;
        return *this;
    }

    MyVectorIterator operator--(int)
    {
        MyVectorIterator = *this;
        --(*this);
        return MyVectorIterator;
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

    bool operator==(const MyVectorIterator& other) const
    {
        return m_Ptr == other.m_Ptr;
    }
    bool operator!=(const MyVectorIterator& other) const
    {
        return !(*this == other);
    }

};

template<class Typ>
class MyVector
{
public:
    using ValueType  = Typ;
    using Iterator = MyVectorIterator<MyVector<Typ>>;
private:
    Typ *arr;
    size_t curSize;
    size_t curCapacity;
public:
    MyVector():curSize(0), curCapacity(DEFAULT_VEC_CAPACITY)
    {
        arr = new Typ[curCapacity];
    }
    MyVector(size_t capacity):curSize(0), curCapacity(capacity)
    {
        arr = new Typ[curCapacity];
    }
    ~MyVector()
    {
        delete [] arr;
    }
    void push_back(Typ data)
    {
        if(curCapacity < (curSize+2))
        {
            // re-allocate memory and copy the contents
            std::cout<<"Reallocating memory since curCapacity : "<<curCapacity
                    << " curSize : "<< curSize <<"(Index starts at 0)\n";
            size_t curCapacityUsed = curSize+1;
            Typ *tempArr = new Typ[curCapacityUsed];
            std::memcpy(tempArr, arr , curCapacityUsed*sizeof(Typ));
            delete [] arr;
            curCapacity = curCapacityUsed + DEFAULT_VEC_CAPACITY;
            std::cout<<"Increasing capacity from "<< curCapacityUsed << " to "<<curCapacity<<"\n";
            arr = new Typ[curCapacity];
            std::memcpy(arr, tempArr, curCapacityUsed*sizeof(Typ));
            delete [] tempArr;   
            tempArr = nullptr;  
        }
        arr[curSize] = data;
        curSize++;
    }
    Typ& operator[](int pos)
    {
        return arr[pos];
    }
    void clear()
    {
        curSize = 0;
        curCapacity = DEFAULT_VEC_CAPACITY;
        delete [] arr;
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

