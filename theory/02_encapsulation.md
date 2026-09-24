# Encapsulation

**Encapsulation** means hiding a class's data (making it private) and only
allowing it to be changed through controlled methods, instead of letting
outside code touch it directly.

## Why it matters
If data is public, anything can set it to a bad value — nothing stops
`c.speed = -500;`. If it's private, and only changeable through a method
like `setSpeed(int s)`, that method can check the value first and refuse
bad input.

## Real-world example
You don't reach into an ATM and grab cash directly. You go through its
controlled process (card, PIN, amount) — it checks things along the way
before letting anything out. Encapsulation is that same idea applied to a
class's data.

## The usual shape
- Data members: `private`
- A "getter" method to read the value: `getSpeed()`
- A "setter" method to change it, with checks: `setSpeed(int s)`

## One-line summary
Hide the data, control access to it through methods — so bad values can
be stopped before they get in.
