class SingletonOnStack
{
private:
    SingletonOnStack();
    volatile int value;
public:
    SingletonOnStack(const SingletonOnStack&) = delete;
    SingletonOnStack& operator=(const SingletonOnStack&) = delete;
    SingletonOnStack(SingletonOnStack&&) = delete;
    SingletonOnStack& operator=(SingletonOnStack&&) = delete;
    static SingletonOnStack& getSingletonOnStackInstance();
    void incrementValue();
    int getValue();
};

class SingletonOnHeapUsingDoubleCheckedLocking
{
private:
    SingletonOnHeapUsingDoubleCheckedLocking();
    static SingletonOnHeapUsingDoubleCheckedLocking* singletonOnHeapUsingDoubleCheckedLockingInstance ;
    volatile int value;
public:
    SingletonOnHeapUsingDoubleCheckedLocking(const SingletonOnHeapUsingDoubleCheckedLocking&) = delete;
    SingletonOnHeapUsingDoubleCheckedLocking& operator=(const SingletonOnHeapUsingDoubleCheckedLocking&) = delete;
    SingletonOnHeapUsingDoubleCheckedLocking(SingletonOnHeapUsingDoubleCheckedLocking&&) = delete;
    SingletonOnHeapUsingDoubleCheckedLocking& operator=(SingletonOnHeapUsingDoubleCheckedLocking&&) = delete;
    static SingletonOnHeapUsingDoubleCheckedLocking& getSingletonOnHeapUsingDoubleCheckedLockingInstance();
    void incrementValue();
    int getValue();
};

