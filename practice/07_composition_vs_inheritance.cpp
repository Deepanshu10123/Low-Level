// Practice: Composition vs Inheritance
// Read theory/07_composition_vs_inheritance.md first if you haven't.

#include <iostream>
#include <string>
using namespace std;

// STEP 1: write two classes.
//   Engine — private int horsepower, a constructor Engine(int hp) that
//     sets it, and a public getHorsepower()
//   Car — HAS-A Engine as a private member (NOT inheritance — Car should
//     NOT derive from Engine). A constructor Car(int hp) that builds its
//     Engine member (remember: Engine has no empty constructor, so this
//     needs the initializer list, same as the Constructors topic).
//     A public getEngineHorsepower() that returns engine.getHorsepower().
// No main() usage yet — that's the next step.
class Engine{
    int horsepower = 0;
    public:
        Engine(int h)
        {
            horsepower =h;
        }
        int getHorsepower(){
            return horsepower;
        }
};
class Car{
    Engine e ;
    public:
        Car(int hp) : e(hp){
            
        }
        int getEngineHorsepower()
        {
            return e.getHorsepower();
        }
};
int main() {
    Car c(300);
    cout<<c.getEngineHorsepower();
    return 0;
}
