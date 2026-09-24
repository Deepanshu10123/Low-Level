# Inheritance

**Inheritance** lets one class reuse another class's data and actions, and
add its own on top — instead of rewriting the shared parts every time.

The class being reused from is the **base class** (or "parent"). The class
reusing it is the **derived class** (or "child").

## The test: is it really "is-a"?
Use inheritance only when the relationship is genuinely "is-a": a `Car`
**is a** `Vehicle`. Don't use it just because two classes happen to share
a field — that's a different idea (composition), for later.

## Syntax
```cpp
class Vehicle {
public:
    int speed;
};

class Car : public Vehicle {
public:
    int numDoors;
};
```
`class Car : public Vehicle` means "Car is a Vehicle, plus whatever Car
adds on its own." A `Car` object automatically has `speed` (from Vehicle)
**and** `numDoors` (its own) — no need to redeclare `speed` in `Car`.

## Real-world example
A kid inherits traits from a parent (eye color, etc.) but also has their
own new traits on top. Same idea — the derived class gets everything the
base class has, plus whatever new it adds.

## One-line summary
Derived class = base class's stuff, automatically, plus its own extra stuff.
