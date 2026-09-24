// Practice: SOLID - Liskov Substitution Principle
// Read theory/10_solid_l_liskov_substitution.md first if you haven't.
//
// This one isn't about fixing code — it's about PROVING the violation to
// yourself, so you recognize it later.

#include <iostream>
using namespace std;

// STEP 1: write Rectangle (virtual setWidth/setHeight/getArea) and
// Square : public Rectangle (overriding setWidth/setHeight so BOTH
// width and height change together, keeping it square) — same shape as
// the theory file.
//
// STEP 2: write a function testShape(Rectangle& r) that does
// r.setWidth(5); r.setHeight(4); then prints r.getArea().
// Call it once with a real Rectangle (should print 20), and once with a
// Square (watch what it prints instead — that mismatch IS the LSP
// violation, made visible).
class Rectangle {
    public:
        virtual void setWidth(int w) { width = w; }
        virtual void setHeight(int h) { height = h; }
        virtual int getArea() { return width * height; }
    protected:
        int width = 0, height = 0;
};

class Square : public Rectangle {
public:
    void setWidth(int w) override { width = height = w; }
    void setHeight(int h) override { height = width = h; }
};


void testShape(Rectangle& r){
    r.setWidth(5);
    r.setHeight(4);
    cout<<r.getArea();
}
int main() {
    Rectangle r;
    testShape(r);
    Square s;
    testShape(s);
    return 0;
}
