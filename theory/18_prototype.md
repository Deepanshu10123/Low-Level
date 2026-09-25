# Prototype

Get "another one just like this" by **cloning** an existing object,
instead of building a new one from scratch — useful when you only have a
base-class pointer and don't know the exact concrete type.

Real-world example: photocopying a document instead of retyping it. You
don't need to know how it was originally written; you just feed it into
the copier and get an identical one out.

## The shape
```cpp
class Shape {
public:
    virtual unique_ptr<Shape> clone() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    Circle(int r) : radius(r) {}
    unique_ptr<Shape> clone() const override { return make_unique<Circle>(*this); }
private:
    int radius;
};
```

## Why `make_unique<Circle>(*this)` works
`*this` gives the actual `Circle` object currently running `clone()`.
Passing an object into `make_unique<Circle>(...)` of its own type calls
C++'s **copy constructor** — generated automatically for every class,
even ones that never wrote one — which copies every member over. So
`clone()` builds a brand-new `Circle` with the same data.

## Using it
```cpp
unique_ptr<Shape> original = make_unique<Circle>(5);
unique_ptr<Shape> copy = original->clone();
```
Even though `original` is just a `Shape*`, `clone()` runs `Circle`'s
version (polymorphism) and returns a real, independent `Circle` — `copy`
and `original` are two separate objects with the same data.

## In UML
`Circle` → `Shape`: generalization, same as always. `clone()` itself
isn't a new relationship — it's just a method every subclass overrides.

## One-line summary
Every class knows how to copy itself; calling `clone()` through the base
type still produces the right kind of copy.
