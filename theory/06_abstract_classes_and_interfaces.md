# Abstract Classes and Interfaces

Sometimes a base class shouldn't provide a real implementation at all —
it should just state "every subclass MUST have this," without saying how.

## Pure virtual — the `= 0` syntax
```cpp
class Vehicle {
public:
    virtual void makeSound() = 0;   // no body at all — pure virtual
};
```
`= 0` means: no default behavior here, and any class that doesn't provide
one becomes abstract too. A class with at least one pure virtual method is
called an **abstract class**.

## What "abstract" actually stops you from doing
```cpp
Vehicle v;   // ERROR — can't create a plain Vehicle anymore
```
You can only create objects of classes that provide a real `makeSound()`
— `Car`, `Bike`, etc. This is exactly what we want: a generic `Vehicle`
was never a real, sensible thing to create on its own.

## "Interface" — same thing, just a name for the common case
In C++ there's no separate `interface` keyword (like Java/C# have). A
class where *every* method is pure virtual (nothing else, no real logic)
is just called an "interface" informally — same mechanism, just used in
its purest form.

## Real-world example
A job posting says "must be able to cook" — a requirement, not an actual
recipe. The posting itself can't cook anything; only an actual hired chef
can. `Vehicle` is the posting; `Car`/`Bike` are the actual chefs.

## One-line summary
`= 0` = no body, subclasses must provide their own, and the base class
itself can no longer be created directly.
