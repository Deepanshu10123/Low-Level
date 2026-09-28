// Practice: Facade
// Read theory/21_facade.md first if you haven't.
// Building this one tiny piece at a time. Don't look ahead.

#include <iostream>
using namespace std;

// STEP 1: write the three plain subsystem classes — Projector (method
// turnOn(), prints "Projector on"), SoundSystem (method turnOn(),
// prints "Sound on"), StreamingDevice (method play(), prints
// "Streaming started"). No inheritance, no Facade yet.
class Projector{
    public:
        void turnOn(){
            cout<<"Projector on";
        }
};
class SoundSystem{
    public:
        void turnOn(){
            cout<<"Sound on";
        }
};
class StreamingDevice{
    public:
        void play(){
            cout<<"Streaming started";
        }
};
class HomeTheater{
    private:
        Projector& p;
        SoundSystem& s;
        StreamingDevice& d;
    public:
        HomeTheater(Projector& p,SoundSystem& s,StreamingDevice& d): p(p), s(s), d(d){}
        void watchMovie(){
            p.turnOn();
            s.turnOn();
            d.play();
        }
};
int main() {
    Projector p;
    SoundSystem s;
    StreamingDevice d;
    HomeTheater t(p,s,d);
    t.watchMovie();
    return 0;
}
