// Practice: Classes and Objects
// Read theory/01_classes_and_objects.md first if you haven't.

#include <iostream>
#include <string>
using namespace std;

// STEP 1: write a class called Car with two pieces of data:
// a string called color, and an int called speed. Nothing else yet.
class Car{
    public:
    string color;
    int speed;
};
int main() {
    Car c ;
    c.color="red";
    c.speed =10;
    cout << c.color << " " << c.speed;
    return 0;
}

