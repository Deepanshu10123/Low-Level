# Glossary — "what is X" lookup

C++ tools and keywords, explained plainly, as we meet them. This is
separate from the theory files — those are about LLD/design ideas, this
is about the C++ vocabulary used to write them.

---

### `unique_ptr`
A "smart" pointer that automatically cleans up the object it points to
when it's no longer needed — you never have to remember to delete it
yourself. "Unique" means only one `unique_ptr` can own that object at a
time; you can't copy it, only hand it off.

### `make_unique<Type>(args)`
The easy way to create a new object and wrap it in a `unique_ptr`, in one
step. Example: `make_unique<Car>("red")` builds a `Car` and hands you back
a `unique_ptr<Car>` pointing to it.

### `virtual`
Marks a method as "subclasses are allowed to replace this with their own
version." Without it, C++ always uses the base class's version, even if a
subclass wrote its own.

### `override`
Written after a method that's replacing a `virtual` one from the parent
class. It tells the compiler "double check this actually matches a parent
method" — if you typo the name or the parameters, the compiler catches it
instead of silently creating an unrelated new method.

### `static` (on a function inside a class)
Means "call this without needing an actual object first" — e.g.
`Counter::instance()` instead of `someCounter.instance()`.

### `static` (on a variable inside a function)
Means "only build this once, the very first time this code runs — every
call after that reuses the same one." This is the trick behind Singletons.

### `&` (reference)
Means "point to the actual same thing, don't make a copy." Used a lot to
avoid accidentally copying objects when you just want to look at or use
the original.

### `= delete`
Written after a function to mean "this doesn't exist — if anyone tries to
use it, fail to compile with an error" instead of allowing it.

### Constructor initializer list
The part between a constructor's `)` and `{`, like `Car(string c) : color(c) {}`.
This is where a member actually gets built/set — not inside the `{ }` body.
Needed especially when a member's type has no "empty" way to build itself.
