#include <iostream>
#include <unordered_set>
using namespace std;
class Observable;
class IObserver
{
public:
    virtual void notify(Observable *observable) = 0;
};

class Observable
{
private:
    unordered_set<IObserver *> observersSet;

public:
    void registerObserver(IObserver *observer)
    {
        observersSet.insert(observer);
    }
    void deRegisterObserver(IObserver *observer)
    {
        observersSet.erase(observer);
    }
    void notifyObservers()
    {
        for (IObserver *observer : observersSet)
        {
            notifyEachObserver(observer);
        }
    }

protected:
    virtual void notifyEachObserver(IObserver *observer) = 0;
};

class SpeedMonitor : public Observable
{
private:
    int mSpeed;

private:
    void notifyEachObserver(IObserver *observer) override
    {
        observer->notify(this);
    }

public:
    void speedChanged(int speed)
    {
        mSpeed = speed;
        notifyObservers();
    }
    inline int getSpeed() const { return mSpeed; }
};

class GeoPosMonitor : public Observable
{
private:
    int mGeoPosMonitor;

private:
    void notifyEachObserver(IObserver *observer) override
    {
        observer->notify(this);
    }

public:
    void geoPosChanged(int geoPosMonitor)
    {
        mGeoPosMonitor = geoPosMonitor;
        notifyObservers();
    }
    inline int getGeoPosMonitor() const { return mGeoPosMonitor; }
};

class SoundManger : public IObserver
{
private:
    SpeedMonitor *mSpeedMonitor;
    GeoPosMonitor *mGeoPosMonitor;

protected:
    void notify(Observable *observable) override
    {
        cout << "We have an update!\n";
        if (dynamic_cast<SpeedMonitor *>(observable) == mSpeedMonitor)
        {
            cout << "Speed updated to " << mSpeedMonitor->getSpeed() << "\n";
            // do what is needed with the speed
        }
        if (observable == mGeoPosMonitor)
        {
            cout << "Geo Position updated to " << mGeoPosMonitor->getGeoPosMonitor() << "\n";
        }
    }

public:
    SoundManger(SpeedMonitor *speedMonitor)
        : mSpeedMonitor(speedMonitor)
    {
    }
    SoundManger(GeoPosMonitor *geoPosMonitor)
        : mGeoPosMonitor(geoPosMonitor)
    {
    }
};

int main()
{
    SpeedMonitor *speedMonitor = new SpeedMonitor();

    SoundManger *soundManagerForSpeed = new SoundManger(speedMonitor);
    speedMonitor->registerObserver(soundManagerForSpeed);
    speedMonitor->speedChanged(20);

    GeoPosMonitor *geoPosMonitor = new GeoPosMonitor();

    SoundManger *soundManagerForGeoPosition = new SoundManger(geoPosMonitor);
    geoPosMonitor->registerObserver(soundManagerForGeoPosition);
    geoPosMonitor->geoPosChanged(123);
    cin.get();
    delete speedMonitor;
    delete soundManagerForSpeed;
    delete soundManagerForGeoPosition;
}