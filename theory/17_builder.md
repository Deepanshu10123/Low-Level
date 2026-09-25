# Builder

Construct a complex object **step by step**, instead of one giant
constructor call — especially useful when most pieces are optional.

Real-world example: ordering a custom sandwich at a counter. You don't
shout the entire order in one breath — you build it up: bread, filling,
sauce, done.

## The two classes
- **Product** (`Pizza`) — just holds data, nothing fancy.
- **Builder** (`PizzaBuilder`) — holds one `Pizza` internally, and has
  one method per piece you can set.

```cpp
class Pizza {
public:
    string size;
    vector<string> toppings;
};

class PizzaBuilder {
public:
    PizzaBuilder& setSize(string s) { pizza.size = s; return *this; }
    PizzaBuilder& addTopping(string t) { pizza.toppings.push_back(t); return *this; }
    Pizza build() { return pizza; }
private:
    Pizza pizza;
};

// usage:
Pizza p = PizzaBuilder().setSize("large").addTopping("cheese").addTopping("olives").build();
```

## Why `return *this;` makes chaining work
`this` is a pointer to the current object (the builder itself). `*this`
dereferences it back to the actual object. Returning it by reference
(`PizzaBuilder&`) means the next `.method()` in the chain runs on that
**same** builder, not a copy — that's what lets calls stack into one line.
`build()` at the end hands back the finished `Pizza`.

## In UML
`PizzaBuilder` → `Pizza`: **composition** (it owns and builds the one
`Pizza` inside it, filled diamond).

## One-line summary
One method per piece, each returning `*this`, chained together, finished
with `build()`.
