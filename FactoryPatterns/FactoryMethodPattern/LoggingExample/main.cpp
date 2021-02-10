#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

class Logger
{
public:
    virtual void logRequestedMessage(string msg) = 0;
};

class ConsoleLogger : public Logger
{
public:
    ConsoleLogger()
    {
        cout << "Console Logger instance created!\n";
    }
    void logRequestedMessage(string msg) override
    {
        cout << msg;
    }
};
class FileLogger : public Logger
{
public:
    FileLogger()
    {
        cout << "File Logger instance created!\n";
    }
    void logRequestedMessage(string msg) override
    {
        cout << "Output to file";
        try
        {
            ofstream fileStream;
            fileStream.open("Log.txt", ios::app);
            fileStream << chrono::system_clock::to_time_t(chrono::system_clock::now()) << " " << msg;
            fileStream.close();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
};

class Log
{
protected:
    virtual Logger *getLogger() = 0; //factory method
public:
    void logMessage(string msg)
    {
        Logger *logger = getLogger();
        logger->logRequestedMessage(msg);
        delete logger;
    }
};
class ConsoleLogCreator : public Log
{
public:
    Logger *getLogger()
    {
        return new ConsoleLogger;
    }
};
class FileLogCreator : public Log
{
public:
    Logger *getLogger()
    {
        return new FileLogger;
    }
};

int main()
{
    Log *log = new ConsoleLogCreator();
    log->logMessage("Print on Console!\n");

    log = new FileLogCreator();
    log->logMessage("Print to file\n");
    cin.get();
}