# Composition vs Inheritance

**Inheritance** = "is-a". `Car` is-a `Vehicle`.
**Composition** = "has-a". `Car` has-a `Engine`.

Composition means a class holds another class as a **member** (a field),
instead of inheriting from it. The two classes aren't related by "type of"
— one just contains the other as a part.

## Syntax
```cpp
class Engine {
public:
    Engine(int hp) : horsepower(hp) {}
    int getHorsepower() { return horsepower; }
private:
    int horsepower;
};

class Car {
public:
    Car(int hp) : engine(hp) {}   // build the Engine member right here
    int getEngineHorsepower() { return engine.getHorsepower(); }
private:
    Engine engine;   // Car HAS-A Engine
};
```
Notice `Car`'s constructor: `: engine(hp)`. Since `Engine` has no
"empty" way to build itself (its only constructor needs an `hp` value),
`Car` must build it in the initializer list — same rule from the
Constructors topic, just with a member that's a whole other class instead
of a plain `int`/`string`.

## When to pick which
- Genuinely "is-a", and you want shared/overridable behavior → inheritance.
- One thing is made up of / contains another, especially if that part
  could be swapped later → composition.

## One-line summary
Inheritance shares a type. Composition holds a part.
