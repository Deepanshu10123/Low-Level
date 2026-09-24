// Practice: Constructors and Destructors
// Read theory/03_constructors_and_destructors.md first if you haven't.

#include <iostream>
#include <string>
using namespace std;

// STEP 1: write a class called Car with:
//   - private string color, private int speed
//   - a public constructor Car(string c, int s) that sets both
//     (no separate .color = / .speed = lines needed anymore)
//   - public getColor() and getSpeed() to read them back
// No destructor yet — that's the next step.
class Car{
    private:
        string color;
        int speed = 0 ;
    public:
        Car(string color, int speed){
            this->color =color;
            this->speed =speed;
        }
        string getColor(){
            return color;
        }
        int getSpeed(){
            return speed;
        }
        ~Car() {
            cout << "\nCar destroyed";
        }

};
int main() {
    Car c("red",10);
    cout<<c.getColor()<<"\n"<<c.getSpeed();
    return 0 ;
}


