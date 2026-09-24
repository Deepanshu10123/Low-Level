# Factory Method

A **Factory** is one function that decides which object to build and
hands it back, so the rest of the program never has to choose or know
which concrete class is used.

Real-world example: a vending machine. You press `A1`, and something
inside figures out "A1 means Soda" and gives you a Soda. You never
assemble it yourself.

## Why bother
Without a factory, every place that needs a product repeats the same
"if A1 make Soda, if B1 make Chips..." checks. Add a new product and you
have to hunt down every copy. With a factory, that decision lives in
exactly **one** place.

## The shape
```cpp
class Product {
public:
    virtual string name() = 0;
    virtual double price() = 0;
    virtual ~Product() = default;
};
class Soda : public Product { /* name() and price() */ };
class Chips : public Product { /* name() and price() */ };

Product* createProduct(string code) {
    if (code == "A1") return new Soda();
    if (code == "B1") return new Chips();
    return nullptr;   // unknown code, nothing to give back
}
```

Things to notice:
1. The return type is `Product*` (the abstract type), even though the
   real object is a `Soda` or `Chips` — polymorphism.
2. `new` keeps the object alive on the heap after the function ends, so
   it can be handed back.
3. There's still an if-chain, and that's fine: it lives in **one** place
   instead of being scattered everywhere.
4. Whoever receives the pointer must `delete` it later (a safer way,
   `unique_ptr`, comes right after this).

## The safer version: `unique_ptr`
The weak spot above is `delete p;` — one line you have to remember. Forget
it and the memory leaks. `unique_ptr` is a wrapper that calls `delete`
**automatically** when it goes out of scope. "Unique" means only one owner
at a time; it can't be copied, only handed over.

```cpp
#include <memory>

unique_ptr<Product> createProduct(string code) {
    if (code == "A1") return make_unique<Soda>();   // builds AND wraps
    if (code == "B1") return make_unique<Chips>();
    if (code == "C1") return make_unique<Candy>();
    return nullptr;
}

unique_ptr<Product> p = createProduct("A1");
cout << p->name();    // used exactly like a normal pointer
// no delete needed
```
Two changes from the raw-pointer version: the return type becomes
`unique_ptr<Product>`, and `new Soda()` becomes `make_unique<Soda>()`.

## Gotcha: unknown codes return `nullptr`
Using `p->name()` on a null pointer crashes. Always check first:
```cpp
unique_ptr<Product> x = createProduct("Z9");
if (x == nullptr) { cout << "No such product"; }
else { cout << x->name(); }
```

## In UML
- `Soda`, `Chips` → `Product`: **generalization** (solid line, hollow
  triangle).
- `createProduct` → `Soda`, `Chips`: **dependency** (dashed arrow,
  labeled "creates"). It builds them, but stores nothing.
- Callers depend only on `Product`, never on `Soda`/`Chips`.

## One-line summary
One function owns the "which class do I build?" decision; everyone else
just asks it.
