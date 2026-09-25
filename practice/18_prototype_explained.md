# `18_prototype.cpp`, line by line

## Includes
```cpp
#include <iostream>
```
Gives us `cout`, for printing.
```cpp
#include <memory>
```
Gives us `unique_ptr` and `make_unique`.
```cpp
using namespace std;
```
Lets us write `unique_ptr` instead of `std::unique_ptr` everywhere.

---

## `class Shape`

```cpp
virtual unique_ptr<Shape> clone() const = 0;
```
- **`= 0`** makes this pure virtual: no body here, every real `Shape`
  (`Circle`, `Square`, ...) **must** provide its own version.
- **`const`** means calling `clone()` doesn't change the object being
  cloned — it only reads it.
- The return type, **`unique_ptr<Shape>`**, means: whatever gets built,
  hand back a self-cleaning pointer to it, typed as the general `Shape`.

```cpp
virtual void describe() const = 0;
```
Same idea as `clone()` — every real `Shape` must know how to print
itself. This exists only so we can later **prove** the clone worked.

```cpp
virtual ~Shape() = default;
```
A virtual destructor. Needed because we delete `Shape`s through a
`Shape*` — without `virtual` here, only `~Shape()` would run, not
`~Circle()`, leaking whatever `Circle` owns.

---

## `class Circle : public Shape`

```cpp
int radius;
```
The one piece of data a `Circle` actually has.

```cpp
Circle(int r) : radius(r) {}
```
Constructor: builds `radius` using the initializer list (`: radius(r)`)
— same rule as every constructor so far, members get set before the
`{}` body runs.

```cpp
unique_ptr<Shape> clone() const override {
    return make_unique<Circle>(*this);
}
```
This is the actual **Prototype trick**.
- **`*this`** = the real `Circle` object currently running `clone()`.
- Passing a `Circle` into `make_unique<Circle>(...)` calls C++'s
  auto-generated **copy constructor**, which copies every member (just
  `radius` here) into a brand-new `Circle`.
- **`override`** checks this really matches `Shape`'s `clone()` — same
  name, same constness, same return type.

```cpp
void describe() const override {
    cout << "circle, radius=" << radius << "\n";
}
```
`Circle`'s own version of `describe()` — prints its radius so we can
**see**, not just assume, that cloning worked.

---

## `main()`

```cpp
unique_ptr<Shape> original = make_unique<Circle>(5);
```
Builds one real `Circle` (radius 5), but stores it as a `Shape*` —
`original` doesn't know or care it's specifically a `Circle`.

```cpp
unique_ptr<Shape> copy = original->clone();
```
Asks `original` to clone itself. Because `clone()` is `virtual`, this
actually runs `Circle::clone()` underneath (polymorphism), even though
we're calling it through a `Shape` pointer.

```cpp
cout << "original: "; original->describe();
cout << "copy:     "; copy->describe();
```
Prints both through the **same** `Shape` interface — neither line needs
to know it's really a `Circle`. Both show `radius=5`, proving `copy`
really did get `Circle`'s data, correctly.
