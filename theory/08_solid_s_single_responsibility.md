# SOLID — S: Single Responsibility Principle

A class should have **one job**, and only one reason to change.

## Bad example
```cpp
class Invoice {
public:
    double calculateTotal(double price, int qty) {
        return price * qty;
    }
    void printToConsole(double total) {
        cout << "Total: $" << total << "\n";
    }
};
```
This class has two reasons to change: if the pricing math changes, OR if
how it's printed/formatted changes. Two unrelated jobs, one class.

## Fixed
```cpp
class Invoice {
public:
    double calculateTotal(double price, int qty) {
        return price * qty;
    }
};

class InvoicePrinter {
public:
    void print(double total) {
        cout << "Total: $" << total << "\n";
    }
};
```
Now each class has exactly one reason to change.

## Real-world example
Don't hire one person to be the accountant, chef, and driver all at once
— give each job to its own person.

## One-line summary
One class, one job. If you can describe a class's purpose only using
"and," it's probably doing too much.
