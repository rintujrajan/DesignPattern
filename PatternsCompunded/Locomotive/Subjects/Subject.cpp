#include "Subject.h"

void Subject::registerObserver(std::shared_ptr<IObserver> observer)
{
    observersSet.emplace(observer);
}
void Subject::removeObserver(std::shared_ptr<IObserver> observer)
{
    observersSet.erase(observer);
}
