#include <iostream>
#include "MyVector.h"
#include "MyUnorderedMultiSet.h"

void customVector()
{
    MyVector<int> myVec(6);
    for (int i = 0; i < 9; i++)
    {
        std::cout<<"i: "<<i<<"\n";
        myVec.push_back(i);
    }
    for (int i = 0; i < myVec.size(); i++)
    {
        std::cout<<"myVec["<<i<< "] : " << myVec[i]  <<"\n";
    } 

    std::cout<<"\n\nClearing Values...\n";
    myVec.clear();

    for (int i = 5; i > 0; i--)
    {
        std::cout<<"i: "<<i<<"\n";
        myVec.push_back(i);
    }

    std::cout<<"\nIterator for loop: \n";
    MyVector<int>::Iterator iter;
    for (iter = myVec.begin(); iter != myVec.end(); iter++)
    {
        // std::cout<<"myVec["<<i<< "] : " << myVec[i]  <<"\n";
        std::cout<< *iter <<" ";
    } 

    std::cout<<"\nRange based for loop: \n";

    for (int i : myVec)
    {
        std::cout<< i <<" ";   
    }
}

void customUnorderedSet()
{
    MyUnorderedMultiSet<int> uSet({20,10,30,20});
    size_t bucketsUsed =  uSet.bucket_count();
    // MyUnorderedMultiSet<int>::Iterator it = uSet.begin(0);
    // for(size_t i = 0; i < bucketsUsed;++i)
    // {
    //     for(it = uSet.begin(i); it != uSet.end(i); it++)
    //     {
    //         std::cout<<"Check";
    //     }
    // }

}

int main()
{
    // customVector();
    customUnorderedSet();
    
    std::cin.get();

    return 0;
}