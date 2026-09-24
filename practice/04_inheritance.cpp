// Practice: Inheritance
// Read theory/04_inheritance.md first if you haven't.

#include <iostream>
#include <string>
using namespace std;

// STEP 1: write two classes.
//   Vehicle — private int speed, public setSpeed(int)/getSpeed()
//   Car : public Vehicle — ALSO has private int numDoors, public
//     setNumDoors(int)/getNumDoors() (don't redeclare speed — Car
//     already has it automatically, from Vehicle)
// No main() usage yet — that's the next step.
class Vehicle{
    private:
        int speed= 0 ;
    public:
        void setSpeed(int s){
            if(s>=0)
                speed = s;
        }
        int getSpeed(){
            return speed;
        }
};
class Car : public Vehicle{
    private:
        int numDoors = 0;
    public:
        void setNumDoors(int nD){
            if(nD>=1)
                numDoors=nD;
        }
        int getNumDoors(){
            return numDoors;
        }
};
int main() {
    Car c;
    c.setSpeed(60);
    c.setNumDoors(4);
    
    cout<<c.getSpeed()<<"\n"<<c.getNumDoors();
    return 0;
}
