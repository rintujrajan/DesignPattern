#include <mutex>
#include <stack>

class ChocolateMakerSingleton
{
    private:
    ChocolateMakerSingleton(std::string threadName);
    ~ChocolateMakerSingleton();
    static std::string getThreadName();
    static void setThreadName(std::string);
    void print(std::string statement);
    static void unlockThreadInstanceLock();
    static void setNoThreadBlockingStatus(bool);
 

    std::stack<std::string> fillStack;
    std::stack<std::string> boilStack;
    std::stack<std::string> drainStack;
    static std::string threadName;
    static bool isThreadInstanceUnLocked;
    static bool isNoThreadBlocking;
    volatile bool isEmpty;
    volatile bool isBolied;
    std::mutex fillLock;
    std::mutex boilLock;
    std::mutex drainLock;
    std::mutex printLock;
    static std::mutex threadNameLock;
    std::condition_variable fillLockCondition;
    std::condition_variable boilLockCondition;
    std::condition_variable drainLockCondition;
    static std::condition_variable threadNameLockCondition;

    public:
    static ChocolateMakerSingleton& getChocolateMakerInstance(std::string threadNameSent);
    void fill();
    void boil();
    void drain();

    /* 
    Note: Scott Meyers mentions in his Effective Modern C++ book, that deleted functions should generally be public,
          as it results in better error messages due to the compilers behavior to check accessibility before deleted status
    */
    ChocolateMakerSingleton() = delete;
    ChocolateMakerSingleton(const ChocolateMakerSingleton&) = delete;
    ChocolateMakerSingleton& operator=(const ChocolateMakerSingleton&) = delete;
    ChocolateMakerSingleton(ChocolateMakerSingleton&&) = delete;
    ChocolateMakerSingleton& operator==(ChocolateMakerSingleton&&) = delete;
};