// Practice: Decorator
// Read theory/20_decorator.md first if you haven't.
// Building this one tiny piece at a time. Don't look ahead.

#include <iostream>
#include <string>
using namespace std;

// STEP 1: write ONLY the Coffee interface — two pure virtual methods,
// cost() returning double and description() returning string, plus a
// virtual destructor. Nothing else yet, no PlainCoffee.
class Coffee {
    public: 
        virtual double cost()=0;
        virtual string description()=0;
        virtual ~Coffee()=default;
};
class PlainCoffee: public Coffee{
    public:
        double cost() override{
            return 2.0;
        }
        string description() override{
            return "Coffee";
        }
};
class CoffeeDecorator: public Coffee{
    protected: 
        Coffee* wrapped;
    public:
        CoffeeDecorator(Coffee* c): wrapped(c){}
};
class MilkDecorator: public CoffeeDecorator{
    public:
        MilkDecorator(Coffee *c) : CoffeeDecorator(c){}
        double cost() override{
            return wrapped->cost()+0.5;
        }
        string description() override{
            return wrapped->description()+ " + Milk";
        }
};
class SugarDecorator: public CoffeeDecorator{
    public:
        SugarDecorator(Coffee *c) : CoffeeDecorator(c){}
        double cost() override{
            return wrapped->cost()+0.25;
        }
        string description() override{
            return wrapped->description() + " + Sugar";
        }
};
int main() {
    Coffee* c = new SugarDecorator(new MilkDecorator(new PlainCoffee()));
    cout<<c->description()<< " $"<<c->cost();
    return 0;
}
