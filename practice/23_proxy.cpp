// Practice: Proxy
// Read theory/23_proxy.md first if you haven't.
// Building this one tiny piece at a time. Don't look ahead.

#include <iostream>
#include <string>
#include <memory>
using namespace std;

// STEP 1: write ONLY the Image interface — ONE pure virtual method,
// display(), plus a virtual destructor. Nothing else yet, no RealImage.
class Image{
    public:
        virtual void display()=0;
        virtual ~Image()=default;
};
int main() {
    return 0;
}
