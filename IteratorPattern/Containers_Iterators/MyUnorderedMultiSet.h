#pragma once
#include <list>
#include <set>
#include <algorithm>
#include <initializer_list>

namespace
{
    const int DEFAULT_BUCKETS = 10;
}

template <class Typ>
class MyUnorderedMultiSet
{
private:
    int bucketCount;
    std::list<Typ> *hashTable;
    int maxLoadFactor;
    std::set<int> buckedPositionsUsed;
public:
    MyUnorderedMultiSet()
    {
        bucketCount = DEFAULT_BUCKETS;
        hashTable = new std::list<Typ>[bucketCount];
        maxLoadFactor = 1;
    }

    MyUnorderedMultiSet(std::initializer_list<Typ> il):MyUnorderedMultiSet()
    {   
        std::initializer_list<Typ>::iterator it;
        for(it = il.begin(); it!= il.end();++it)
        {
            insert(*it);
        }
    }
    
    int hashFunction(const Typ& val)
    {
        std::hash<Typ> typ_hash;
        int hashValue =  typ_hash(val);
        return hashValue % bucketCount;
    }

    void insert( const Typ& val )
    {
        float curLoadFactor = (float)buckedPositionsUsed.size() / bucketCount;
        if(curLoadFactor<1)
        {
            int positionToInsert = hashFunction(val);
            std::list<Typ> chain = hashTable[positionToInsert];
            chain.push_back(val);
            hashTable[positionToInsert] = chain;
            buckedPositionsUsed.insert(positionToInsert);
        }
        else
        {
            rehash();
        }
    }

    int bucket_count()
    {
        return bucketCount;
    } 

    void rehash()
    {
        /* code */
    }
};