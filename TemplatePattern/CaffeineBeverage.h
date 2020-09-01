#ifndef CAFFEINE_BEVERAGE
#define CAFFEINE_BEVERAGE
class CaffeineBeverage
{
protected:
    bool isCondimentsAdded;
public:
    // The template method. It is amrked as final so that derived class canot override the function
    // This contains the algoithm to prepare a Caffeine beverage
    virtual void prepareBeverage() final;

    /* 
    Common for both the beverages hence implemented herein
    A concrete operation is defined in the abstract class. 
    This one is declared final so that subclasses can’t override it.
    It may be used in the template method directly, or used by subclasses.
    */
    virtual void boilWater() final;

    /*
    We still have our primitive methods; these are abstract and implemented by concrete subclasses. 

    The Hollywood Principle - Don’t call us, we’ll call you.
    With the Hollywood Principle, we allow low-level components to hook themselves into a system,
    but the high-level components determine when they are needed, and how. 
    In other words, the high-level components give the low-level components a “don’t call us, we’ll call you” treatment.

    CaffeineBeverage is our high-level component.
    It has control over the algorithm for the recipe,
    and calls on the subclasses only when they’re needed for an implementation of a method
    */ 
    virtual void brewBeverage() = 0;

    /* 
    Common for both the beverages hence implemented herein
    A concrete operation is defined in the abstract class. 
    This one is declared final so that subclasses can’t override it.
    It may be used in the template method directly, or used by subclasses.
    */
    virtual void pourInCup() final;

    /*
    We still have our primitive methods; these are abstract and implemented by concrete subclasses. 
    
    The Hollywood Principle - Don’t call us, we’ll call you.
    With the Hollywood Principle, we allow low-level components to hook themselves into a system,
    but the high-level components determine when they are needed, and how. 
    In other words, the high-level components give the low-level components a “don’t call us, we’ll call you” treatment.

    CaffeineBeverage is our high-level component.
    It has control over the algorithm for the recipe,
    and calls on the subclasses only when they’re needed for an implementation of a method
    */ 
    virtual void addCondiments() = 0;

    /* 
    A hook is a method that is declared abstract class, 
    but only given an empty or default implementation. 
    This gives subclasses the ability to “hook into” the algorithm at various points,
    if they wish; a subclass is also free to ignore the hook

    Here we’ve defined a method with a (mostly) empty default implementation.
    This method just returns true and does nothing else.

    This is a hook because the subclass can override this method, but doesn’t have to.
    In our current example, both derived classes override to ask if condiments are needed

    Use abstract methods when your subclass MUST provide an implementation of the method 
    or step in the algorithm.
    Use hooks when that part of the algorithm is optional. 
    With hooks, a subclass may choose to implement that hook, but it doesn’t have to.
    */
    inline virtual bool customerNeedsCondiments()
    {
        return true;
    }
};

#endif CAFFEINE_BEVERAGE