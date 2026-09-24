# SOLID — L: Liskov Substitution Principle

A subclass must be usable anywhere its base class is expected, without
breaking correctness — the caller shouldn't get surprised.

## The classic violation
```cpp
class Rectangle {
public:
    virtual void setWidth(int w) { width = w; }
    virtual void setHeight(int h) { height = h; }
    int getArea() { return width * height; }
protected:
    int width, height;
};

class Square : public Rectangle {
public:
    void setWidth(int w) override { width = height = w; }   // also changes height!
    void setHeight(int h) override { width = height = h; }  // also changes width!
};
```
Any code that does `r.setWidth(5); r.setHeight(4);` and expects
`getArea() == 20` is correct for a `Rectangle` — but silently wrong for a
`Square`, which would give `16` instead (both got forced to `4`).

## Why this matters
This is exactly why "is-a" isn't always the right call, even when it
sounds true in plain English. A `Square` *is*, mathematically, a kind of
rectangle — but it doesn't behave like one the way this class's callers
expect. Inheritance isn't just about shared data; it's a promise that
subclasses honor the base class's behavior.

## The actual fix
Not a code trick — a design decision: `Square` shouldn't inherit from
`Rectangle` here at all. They could both instead implement a shared
`Shape` interface with just `getArea()`, without one pretending to behave
like the other.

## One-line summary
"Is-a" in English isn't enough — a subclass must also honor the base
class's *behavior*, or it shouldn't inherit from it.
