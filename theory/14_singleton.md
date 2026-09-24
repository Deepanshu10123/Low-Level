# Singleton

A **Singleton** is a class where only **one object** can ever exist, and
everyone gets that same one object.

Real-world example: a school with one principal — every student who asks
"who's the principal?" is pointed to the same person, and nobody can
create a second principal.

Real uses: a logger every part of a program writes to, or a settings
object the whole program shares.

## How "only one" is enforced
1. **Locked front door** — make the constructor `private`, so nobody
   outside can create an object.
2. **One guarded side door** — a `static` function, usually named
   `instance()`, that creates the object the first time and hands back
   the same one every time after.
3. **No copying** — delete the two copy operations so nobody can sneak a
   second object in by copying the first.

## The whole pattern
```cpp
class Counter {
public:
    static Counter& instance() {
        static Counter c;   // built once, the first time only
        return c;           // the same c, every time
    }
    void increment() { count++; }
    int getCount() { return count; }

private:
    Counter() {}                                  // locked front door
    Counter(const Counter&) = delete;             // no copying (new object)
    Counter& operator=(const Counter&) = delete;  // no copying (existing one)
    int count = 0;
};

// usage: Counter::instance().increment();
```

## The new words
- `static` function: belongs to the class, callable without an object:
  `Counter::instance()`.
- `static` variable inside a function: built only the first time that
  function runs, then reused.
- `Counter&`: a reference, meaning the actual same object, not a copy.
- `= delete`: "this operation doesn't exist, using it is a compile error."

## Reading the two `= delete` lines
They block two different kinds of copying:

- `Counter b = a;` makes a **new** object as a copy → the **copy constructor**
- `b = a;` overwrites an **existing** `b` → the **copy assignment operator**

```cpp
Counter(const Counter&) = delete;              // copy constructor
Counter& operator=(const Counter&) = delete;   // copy assignment operator
```

Breaking down `Counter& operator=(const Counter&) = delete;`:
1. `operator=` — the name of the function C++ runs for `b = a;`. The `=`
   sign is secretly a function with this name.
2. `(const Counter&)` — the input, the object on the right side of `=`.
   `&` = don't copy it just to pass it in. `const` = I'll only read it.
3. `Counter&` at the front — what it gives back. Assignment returns the
   object itself; a reference avoids making yet another copy.
4. `= delete` — this function doesn't exist; using it is a compile error.

Why it's written so formally: C++ auto-generates copy functions with
exactly these shapes. To turn one off, you write the same shape and mark
it `= delete`.

## In UML
One box. The constructor is marked `-` (private). `instance()` is marked
`+` and underlined (static). Every other class reaches the Singleton only
through `instance()`.

## One-line summary
Locked constructor + one `static instance()` door + no copying = exactly
one object, shared by everyone.
