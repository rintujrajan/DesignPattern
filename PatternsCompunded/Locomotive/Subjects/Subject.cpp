#include "Subject.h"

void Subject::registerObserver(std::shared_ptr<IObserver> observer)
{
    observersSet.emplace(observer);
}
void Subject::removeObserver(std::shared_ptr<IObserver> observer)
{
    observersSet.erase(observer);
}
void Subject::notifyAllObservers()
{
    for (auto &&observer : observersSet)
    {
        // each observer is notified from the concrete subjects, so that the "this" pointer of the concrete subjects can be passed
        notifyEachObserver(observer);
    }
}