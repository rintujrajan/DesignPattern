#include "PancakeHouseMenuIterator.h"

PancakeHouseMenuIterator::PancakeHouseMenuIterator(std::vector<MenuItem*> menuItems)
                                    :pIteratorPosition(0)
{
        pMenuItems = menuItems;
}

bool PancakeHouseMenuIterator::hasNext()
{
    return pIteratorPosition < pMenuItems.size();
}
MenuItem* PancakeHouseMenuIterator::next()
{
    MenuItem* itemToReturn = pMenuItems[pIteratorPosition];
    pIteratorPosition++;
    return itemToReturn;
}