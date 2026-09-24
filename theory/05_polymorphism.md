# Polymorphism

**Polymorphism** means: one call, different behavior, depending on the
actual object underneath.

## How it works
1. The base class marks a method `virtual`.
2. Each derived class writes its own version of that method.
3. Calling that method — even through a base class pointer/reference —
   automatically runs whichever version matches the real object.

## Syntax
```cpp
class Vehicle {
public:
    virtual void makeSound() {
        cout << "generic vehicle sound\n";
    }
};

class Car : public Vehicle {
public:
    void makeSound() override {
        cout << "beep beep\n";
    }
};

class Bike : public Vehicle {
public:
    void makeSound() override {
        cout << "ring ring\n";
    }
};
```
`override` isn't required to make this work, but always write it anyway —
it tells the compiler "double check this actually matches a virtual
method in the base," catching typos immediately instead of silently
creating an unrelated new method.

## The real payoff
```cpp
Vehicle* v = new Car();
v->makeSound();   // prints "beep beep" — NOT the generic Vehicle version
```
Even though `v` is *typed* as `Vehicle*`, it actually points to a `Car`,
so `Car`'s version runs. This is what lets you write one loop over a list
of different vehicle types and have each one behave correctly, without
an if/else checking what type each one is.

## Real-world example
You tell any employee "do your job" — same instruction, but a chef cooks
and a driver drives. One call, different behavior depending on who it
actually is.

## One-line summary
`virtual` + `override` = calling through the base type still runs the
real object's own version.
