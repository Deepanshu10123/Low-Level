// Practice: SOLID - Interface Segregation Principle
// Read theory/11_solid_i_interface_segregation.md first if you haven't.

#include <iostream>
using namespace std;

// This violates ISP — Robot is forced to implement eat(), which makes
// no sense for it.
//
// STEP 1: replace Worker with two small interfaces, Workable (work()) and
// Eatable (eat()). Make Human inherit from BOTH (comma-separated, see
// theory file). Make Robot inherit from ONLY Workable — no eat() at all.
// class Worker {
// public:
//     virtual void work() = 0;
//     virtual void eat() = 0;
//     virtual ~Worker() = default;
// };

class Workable{
    public:
        virtual void work()=0;
        ~Workable()=default;
};
class Eatable{
    public:
        virtual void eat()=0;
        ~Eatable()= default ;
};

class Human : public Workable, public Eatable {
public:
    void work() override { cout << "coding\n"; }
    void eat() override { cout << "eating lunch\n"; }
};

class Robot : public Workable {
public:
    void work() override { cout << "welding\n"; }
    // void eat() override { /* doesn't make sense for a robot */ }
};

int main() {
    Human h;
    Robot r;
    h.work();
    h.eat();
    r.work();
    return 0;
}
