// Practice: SOLID - Single Responsibility Principle
// Read theory/08_solid_s_single_responsibility.md first if you haven't.

#include <iostream>
using namespace std;

// This class violates SRP — it has TWO reasons to change: the pricing
// math, and how the receipt gets printed.
//
// STEP 1: split this into two classes:
//   Invoice — only calculateTotal(price, qty)
//   ReceiptPrinter — only print(total)
// Then update main() to use both.
class Invoice {
public:
    double calculateTotal(double price, int qty) {
        return price * qty;
    }
};
class ReceiptPrinter{
public:
    void print(double total){
        cout << "Total: $" << total << "\n";
    }
};

int main() {
    Invoice inv;
    ReceiptPrinter pri;
    double total = inv.calculateTotal(20.0, 3);
    pri.print(total);
    return 0;
}
