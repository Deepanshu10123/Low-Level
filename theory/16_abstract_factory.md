# Abstract Factory

A factory that builds a whole **matching family** of related objects,
instead of just one kind of thing.

Real-world example: a furniture store with a "modern" line and a
"Victorian" line. Order everything from the modern line and the sofa and
table match. You'd never accidentally get a Victorian chair with a
modern table.

## Why not just Factory Method?
Factory Method (last topic) builds **one kind** of thing (a Product).
Abstract Factory builds a **whole family** at once, and you swap the
entire family by swapping which factory you use.

## The shape
Three ingredients:
1. **Product interfaces** — one per kind of thing (`Button`, `Checkbox`).
2. **Concrete products per family** — `DarkButton`/`DarkCheckbox` and
   `LightButton`/`LightCheckbox`.
3. **One abstract factory interface**, with one method per product kind:

```cpp
class Button { public: virtual void render() = 0; virtual ~Button() = default; };
class Checkbox { public: virtual void render() = 0; virtual ~Checkbox() = default; };

class DarkButton : public Button { public: void render() override { /* ... */ } };
class DarkCheckbox : public Checkbox { public: void render() override { /* ... */ } };

class UIFactory {
public:
    virtual unique_ptr<Button> createButton() = 0;
    virtual unique_ptr<Checkbox> createCheckbox() = 0;
    virtual ~UIFactory() = default;
};

class DarkFactory : public UIFactory {
public:
    unique_ptr<Button> createButton() override { return make_unique<DarkButton>(); }
    unique_ptr<Checkbox> createCheckbox() override { return make_unique<DarkCheckbox>(); }
};
```

Using it:
```cpp
unique_ptr<UIFactory> factory = make_unique<DarkFactory>();
unique_ptr<Button> btn = factory->createButton();
unique_ptr<Checkbox> chk = factory->createCheckbox();
```
Both `btn` and `chk` are guaranteed dark, because both came from the same
`factory`. Swap in `LightFactory` and both become light — you can never
end up with a mismatched pair by accident.

## In UML
- `DarkButton` → `Button`, `DarkFactory` → `UIFactory`: generalization.
- `DarkFactory` → `DarkButton`/`DarkCheckbox`: dependency (creates them).
- Calling code depends only on `UIFactory`, `Button`, `Checkbox` — never
  on the concrete `Dark...`/`Light...` classes.

## One-line summary
One factory per family, one method per product kind — pick a factory,
get a guaranteed-matching set.
