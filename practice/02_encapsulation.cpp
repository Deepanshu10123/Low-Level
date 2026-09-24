// Practice: Encapsulation
// Read theory/02_encapsulation.md first if you haven't.

#include <iostream>
#include <string>
using namespace std;

// STEP 1: write a class called Car with:
//   - a private int called speed
//   - a public setSpeed(int s) that only sets speed if s >= 0
//     (if s is negative, just don't change speed — maybe print a message)
//   - a public getSpeed() that returns speed
// Nothing about color yet — just speed, for now.
class Car{
    private:
    int speed=0;
    public:
    void setSpeed(int s)
    {
        if(s>=0)
            speed =s;
        else
            cout<<"speed is slow";
    }
    int getSpeed()
    {
        return speed;
    }
};
int main() {
    Car c;
    c.setSpeed(-5);
    cout<<c.getSpeed()<<"\n";
    c.setSpeed(50);
    cout<<c.getSpeed();
    return 0;
}
