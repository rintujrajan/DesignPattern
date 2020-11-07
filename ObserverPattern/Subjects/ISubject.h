#pragma once

class IObserver;

class ISubject
{
public:
	virtual void registerObserver(IObserver* observer) = 0;
	virtual void removeObserver(IObserver* observer) = 0;
	virtual void notifyObservers() = 0;
};

