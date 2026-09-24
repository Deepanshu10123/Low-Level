# UML Basics

A **class diagram** is just a standard way to draw the classes and
relationships you've already been building in code — useful for sketching
a design on paper before (or during) writing it, especially in interviews.

## The class box
Three parts, stacked:
```
+----------------+
|      Car       |  <- name
+----------------+
| - speed: int   |  <- data (- = private, + = public)
+----------------+
| + getSpeed()   |  <- methods
+----------------+
```

## The relationship arrows (the part that actually matters)

**Generalization** — inheritance, "is-a". Solid line, **hollow triangle**
pointing at the parent.
```
Car ───▷ Vehicle
```
(You built this: `class Car : public Vehicle`.)

**Composition** — "has-a", genuinely owned (the part doesn't make sense
without the whole). Solid line, **filled diamond** at the "whole" end.
```
Car ◆─── Engine
```
(You built this: `Car` holds an `Engine` as a member.)

**Association** — stored as a member, but NOT owned: it was created
elsewhere and just referenced. Plain solid line, no diamond, no triangle.
```
NotificationService ───> Sender
```
(This is what you built: `NotificationService` stores a `Sender&`, but the
`EmailSender` was created in `main()` and handed in — it would keep
existing even if the `NotificationService` were destroyed.)

**Dependency** — "uses briefly," like a function parameter or local
variable — NOT stored as a member. Dashed line, open arrowhead.
```
OrderPrinter - - -> Receipt      (only used inside one method call)
```

## The 3-question test
1. Is it **stored** as a member? No → **dependency**.
2. Stored, and the whole **owns** it (created inside, dies with it)? →
   **composition** (filled diamond).
3. Stored, but created elsewhere and just referenced? → **association**.

## One-line summary
Box = class. Hollow triangle = is-a. Filled diamond = has-a (owned).
Plain line = stored but not owned. Dashed arrow = used briefly, not stored.
