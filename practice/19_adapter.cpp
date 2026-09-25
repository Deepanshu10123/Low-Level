// Practice: Adapter
// Read theory/19_adapter.md first if you haven't.
// Building this one tiny piece at a time. Don't look ahead.

#include <iostream>
using namespace std;

// STEP 1: write ONLY the MediaPlayer interface — ONE pure virtual
// method, play(), plus a virtual destructor. Nothing else yet.
class MediaPlayer {
    public:
        virtual void play()=0;
        virtual ~MediaPlayer()=default;
};
class LegacyAudioPlayer{
    public:
        void playSound(){
            cout<<"playing sound (legacy)\n";
        }
};
class LegacyAudioPlayerAdapter:public MediaPlayer{
    private:
        LegacyAudioPlayer& p;
    public:
        LegacyAudioPlayerAdapter(LegacyAudioPlayer& p): p(p) {}
        void play() override{
            p.playSound();
        }

};
int main() {
    LegacyAudioPlayer old;
    LegacyAudioPlayerAdapter adapter(old);
    MediaPlayer * player = &adapter;
    player->play();
    return 0;
}
