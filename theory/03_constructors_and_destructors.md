# Constructors and Destructors

**Constructor**: a special method that runs automatically the moment an
object is created. Used to set up its starting values in one step, instead
of setting each field separately after the fact.

**Destructor**: a special method that runs automatically when an object
is destroyed (e.g. it goes out of scope). Used for cleanup.

## Example, in words
Instead of:
```cpp
Car c;
c.color = "red";
c.speed = 0;
```
A constructor lets you do:
```cpp
Car c("red", 0);
```
Both fields get set in one step, right when `c` is created.

## Naming rule
- Constructor: same name as the class, no return type. `Car(string col, int s) { ... }`
- Destructor: same name as the class with a `~` in front, no arguments, no return type. `~Car() { ... }`

## Real-world example
Constructor = filling out a form when you register for something — setup
happens once, at the very start. Destructor = closing things out when
you're done with something.

## One-line summary
Constructor = runs automatically on creation, for setup. Destructor =
runs automatically on destruction, for cleanup.
