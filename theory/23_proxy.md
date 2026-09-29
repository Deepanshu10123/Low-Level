# Proxy

A stand-in that implements the **same interface** as a real object, and
controls access to it — often to delay creating something expensive
until it's actually needed.

Real-world example: a receptionist. You ask for something, and the
receptionist decides whether to actually go get the real person or
resource, or handle it themselves — you never deal with the real thing
directly unless it's actually needed.

## The problem it solves
An `Image` that's expensive to load (reading a big file from disk). If
you create a hundred `Image` objects but only ever display three, loading
all hundred wastes real time on images nobody looked at.

## The shape
```cpp
class Image {
public:
    virtual void display() = 0;
    virtual ~Image() = default;
};

class RealImage : public Image {
public:
    RealImage(string f) : filename(f) { cout << "Loading " << filename << " from disk\n"; }
    void display() override { cout << "Displaying " << filename << "\n"; }
private:
    string filename;
};

class ProxyImage : public Image {
public:
    ProxyImage(string f) : filename(f) {}
    void display() override {
        if (!real) real = make_unique<RealImage>(filename);
        real->display();
    }
private:
    string filename;
    unique_ptr<RealImage> real;   // starts as nullptr, nothing created yet
};
```

Using it:
```cpp
ProxyImage img("photo.png");
// nothing loaded yet — no RealImage exists
img.display();   // NOW it loads, then displays
img.display();   // already loaded, just displays again, no reload
```

## The one new idea
`unique_ptr<RealImage> real;` with no initializer starts out **null**
automatically. `display()` checks `if (!real)` — "have I created the
real one yet?" — and only builds it the first time, right there
("lazy initialization"). Every call after that skips straight to
`real->display()`.

## In UML
- `RealImage`, `ProxyImage` → `Image`: generalization.
- `ProxyImage` → `RealImage` (the `real` member): composition — owns it,
  but only creates it lazily.

## One-line summary
Same interface as the real thing, but decides *when* (or whether) the
real, expensive object actually gets built.
