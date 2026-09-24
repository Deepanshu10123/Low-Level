// Practice: Abstract Classes and Interfaces
// Read theory/06_abstract_classes_and_interfaces.md first if you haven't.

#include <iostream>
#include <string>
using namespace std;

// STEP 1: write Vehicle with makeSound() as PURE virtual (= 0, no body).
// Then Car and Bike, same as last topic, each overriding it with a real
// body ("beep beep" / "ring ring").
// No main() usage yet — that's the next step.
class Vehicle{
    public:
        virtual void makeSound()=0;
};
class Car : public Vehicle{
    public:
        void makeSound() override{
            cout<<"Beep Beep";
        }
};
class Bike : public Vehicle{
    public:
        void makeSound() override {
            cout<<"Ring Ring";
        }
};
int main() {
    Vehicle* v = new Car() ;
    Vehicle* b = new Bike();
    v->makeSound();
    b->makeSound();
    return 0;
}
