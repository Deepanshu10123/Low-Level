# SOLID — O: Open/Closed Principle

Code should be **open for extension, closed for modification** — add new
behavior without editing existing, already-working code.

## Bad example
```cpp
double getDiscount(string customerType, double price) {
    if (customerType == "regular") return 0.0;
    if (customerType == "premium") return price * 0.10;
    // every new tier = another edit here, risking what already worked
}
```

## Fixed — using an interface (same idea as the abstract class topic)
```cpp
class DiscountStrategy {
public:
    virtual double getDiscount(double price) = 0;
    virtual ~DiscountStrategy() = default;
};

class RegularDiscount : public DiscountStrategy {
public:
    double getDiscount(double price) override { return 0.0; }
};

class PremiumDiscount : public DiscountStrategy {
public:
    double getDiscount(double price) override { return price * 0.10; }
};
```
Adding a new tier now means writing a *new class* — the code that calls
`getDiscount()` never has to change at all.

## Real-world example
A power strip — when you get a new appliance, you just plug it in. You
don't rewire your house's electrical every time.

## One-line summary
New behavior = a new class, not an edit to old code.
