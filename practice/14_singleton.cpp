// Practice: Singleton
// Read theory/14_singleton.md first if you haven't.
// Building this one tiny piece at a time. Don't look ahead.

#include <iostream>
using namespace std;

// STEP 1: just the "locked front door".
// Write class Counter with ONLY a private, empty constructor.
// Nothing else yet.
class Counter{
    private:
        Counter(){}
        Counter(const Counter&) = delete;
        Counter& operator= (const Counter&) = delete;
        int count = 0 ;
    public:
        static Counter& instance(){
            static Counter c;
            return c ;
        }
        void increment(){
            count++;
        }
        int getCount(){
            return count;
        }
};
int main() {
    Counter::instance().increment();
    Counter::instance().increment();
    Counter::instance().increment();
    cout << Counter::instance().getCount();

    return 0;
}
