// Practice: Prototype
// Read theory/18_prototype.md first if you haven't.
// Line-by-line walkthrough: practice/18_prototype_explained.md

#include <iostream>
#include <memory>
using namespace std;

class Shape{
    public:
        virtual unique_ptr<Shape> clone() const =0;
        virtual void describe() const =0;
        virtual ~Shape()=default;
};
class Circle : public Shape{
    private:
        int radius;
    public:
        Circle(int r) : radius(r){};
        unique_ptr<Shape> clone() const override{
            return make_unique<Circle>(*this);
        }
        void describe() const override{
            cout << "circle, radius=" << radius << "\n";
        }
};
int main() {
    unique_ptr<Shape> original = make_unique<Circle>(5);
    unique_ptr<Shape> copy = original->clone();
    cout << "original: "; original->describe();
    cout << "copy:     "; copy->describe();
    return 0;
}


