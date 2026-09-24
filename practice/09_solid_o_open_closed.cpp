// Practice: SOLID - Open/Closed Principle
// Read theory/09_solid_o_open_closed.md first if you haven't.

#include <iostream>
#include <string>
using namespace std;

// This function violates OCP — adding a new customer type means editing
// this same function again.
//
// STEP 1: replace this with:
//   an abstract DiscountStrategy (pure virtual getDiscount(double price))
//   RegularDiscount (returns 0.0) and PremiumDiscount (returns price * 0.10)
// Then update main() to use a DiscountStrategy object instead of a string.
// double getDiscount(string customerType, double price) {
//     virtual int getDiscount(double price)= 0;
//     if (customerType == "regular") return 0.0;
//     if (customerType == "premium") return price * 0.10;
//     return 0.0;
// }
class DiscountStrategy{
    public:
        virtual double getDiscount(double price)=0;
        virtual ~DiscountStrategy()=default;
};

class RegularDiscount : public DiscountStrategy{
    public:
        double getDiscount(double price) override{
            return 0.0;
        }
};
class PremiumDiscount : public DiscountStrategy{
    public:
        double getDiscount(double price) override{
            return price * 0.10;
        }
};

int main() {
    // double discount = getDiscount("premium", 200.0);
    // cout << "Discount: $" << discount;
    DiscountStrategy* s = new RegularDiscount();
    DiscountStrategy* p = new PremiumDiscount();
    cout<<s->getDiscount(200)<<"\n";
    cout<<p->getDiscount(300);
    return 0;
}
