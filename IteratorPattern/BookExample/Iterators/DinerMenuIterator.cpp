#include "DinerMenuIterator.h"

DinerMenuIterator::DinerMenuIterator(MenuItem *menuItems[], int numberOfItems)
                                    :pIteratorPosition(0),pNumberOfItems(numberOfItems)
{
    for (int i = 0; i < MAX_MENU_ITEMS; i++)
    {
        pMenuItems[i] = menuItems[i];
    }
}

bool DinerMenuIterator::hasNext()
{
    return pIteratorPosition < pNumberOfItems;
}
MenuItem* DinerMenuIterator::next()
{
    MenuItem* itemToReturn = pMenuItems[pIteratorPosition];
    pIteratorPosition++;
    return itemToReturn;
}