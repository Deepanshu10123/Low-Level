// Practice: Polymorphism
// Read theory/05_polymorphism.md first if you haven't.

#include <iostream>
#include <string>
using namespace std;

// STEP 1: write three classes.
//   Vehicle — a public virtual makeSound() that prints something generic
//   Car : public Vehicle — overrides makeSound(), prints "beep beep"
//   Bike : public Vehicle — overrides makeSound(), prints "ring ring"
// No main() usage yet — that's the next step.
class Vehicle{
    public:
        virtual void makeSound(){
            cout << "generic vehicle sound\n";  
        }
};
class Car : public Vehicle{
    public:
    void makeSound() override{
        cout<<"beep beep";
    }
};
class Bike : public Vehicle{
    public:
    void makeSound() override{
        cout<<"ring ring";
    }
};
int main() {
    Vehicle* v = new Car() ;
    Vehicle* b = new Bike();
    v->makeSound();
    b->makeSound();
    return 0;
}
