# Decorator

Attach new behavior to an object at runtime by **wrapping** it, instead
of creating a new subclass for every combination of features.

Real-world example: dressing in layers. A t-shirt, wrapped by a jacket,
wrapped by a raincoat. Each layer adds something while still being
"something you wear" — you combine any layers you want, without a
pre-made outfit for every possible combination.

## The problem it avoids
A `Coffee` that can optionally have milk, sugar, or both, handled by
subclassing, needs `MilkCoffee`, `SugarCoffee`, `MilkSugarCoffee` — a
combinatorial explosion of classes as more add-ons appear.

## Not the same as Builder
A `PizzaBuilder` is a *different type* from `Pizza`, and it's thrown away
after `build()` produces one flat object. A `MilkDecorator` **is** a
`Coffee` (same interface) and stays wrapped permanently — every call
cascades live through every layer, every time.

## The shape
```cpp
class Coffee {
public:
    virtual double cost() = 0;
    virtual string description() = 0;
    virtual ~Coffee() = default;
};

class PlainCoffee : public Coffee {
public:
    double cost() override { return 2.0; }
    string description() override { return "Coffee"; }
};

class CoffeeDecorator : public Coffee {
public:
    CoffeeDecorator(Coffee* c) : wrapped(c) {}
protected:
    Coffee* wrapped;
};

class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* c) : CoffeeDecorator(c) {}
    double cost() override { return wrapped->cost() + 0.5; }
    string description() override { return wrapped->description() + " + Milk"; }
};
```

Using it:
```cpp
Coffee* c = new MilkDecorator(new PlainCoffee());
cout << c->description() << " $" << c->cost();
// Coffee + Milk $2.5
```

## The core trick
`CoffeeDecorator` both **is-a** `Coffee` (inherits it) and **has-a**
`Coffee*` (holds one as `wrapped`). That dual nature is what lets you
stack indefinitely — `wrapped` can be a plain coffee, or itself another
decorator, and each layer's method just calls `wrapped->...()` and adds
its own bit on top.

## In UML
- `PlainCoffee`, `CoffeeDecorator` → `Coffee`: generalization.
- `MilkDecorator` → `CoffeeDecorator`: generalization.
- `CoffeeDecorator` → `Coffee` (the `wrapped` member): composition — it
  owns and holds onto the wrapped object.

## One-line summary
Each decorator is-a the same interface it wraps, and has-a one instance
of it — stack as many as you want, each adding its own bit at call time.
