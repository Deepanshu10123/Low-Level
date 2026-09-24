# Practice: UML Basics

Not code this time — just write your answer as text below each question
(or tell me in chat), and I'll check it.

## Q1
You built `class Car : public Vehicle`. What's the relationship name, and
draw the arrow (in words: which end has the triangle, is it solid or
dashed)?
Ans : (is-a) here the triangle would be at Vehicle 

## Q2
You built `Car` holding an `Engine` as a member. What's the relationship
name, and which end gets the diamond?
Ans : (has-a) diamond would be at car side 

## Q3
You built `NotificationService` holding a `Sender&`, injected through the
constructor rather than stored as a fixed concrete type. Is the link to
`Sender` closer to composition, or dependency? Why?
Ans : composition, because we are holding the class object into another class object without having the inheritance relationship

(Correction after review: Q3 is **association**, not composition — see the
3-question test in theory/13_uml_basics.md.)
Retry answer: it is stored, main created it and NotificationService
doesn't own it → stored but not owned = **association**. ✓

## Q4 (retry with the 3-question test)
In the Liskov exercise you wrote `void testShape(Rectangle& r)`, a
function that receives a `Rectangle` and uses it only inside that one
call. Run the 3-question test: what's the relationship between
`testShape` and `Rectangle`?
Ans : **dependency** — not stored anywhere, only used inside one call
(worked out together).