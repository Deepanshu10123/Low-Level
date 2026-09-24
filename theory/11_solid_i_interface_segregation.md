# SOLID — I: Interface Segregation Principle

Don't force a class to implement methods it doesn't actually need.

## Bad example
```cpp
class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
};

class Robot : public Worker {
public:
    void work() override { cout << "welding\n"; }
    void eat() override { /* ??? robots don't eat */ }
};
```
`Robot` is forced into an `eat()` method that makes no sense for it, just
because `Worker`'s interface bundled two unrelated things together.

## Fixed — split into smaller, focused interfaces
```cpp
class Workable {
public:
    virtual void work() = 0;
};
class Eatable {
public:
    virtual void eat() = 0;
};

class Human : public Workable, public Eatable {
public:
    void work() override { cout << "coding\n"; }
    void eat() override { cout << "eating lunch\n"; }
};

class Robot : public Workable {
public:
    void work() override { cout << "welding\n"; }
};
```
Notice `class Human : public Workable, public Eatable` — a class can
inherit from more than one base at once, separated by commas. `Human`
needs both interfaces, so it implements both. `Robot` only needs one.

## Real-world example
A job application shouldn't ask every applicant "favorite lunch spot" —
that only makes sense for some roles, not all of them.

## One-line summary
Small, focused interfaces. Implement only what actually applies to you.
