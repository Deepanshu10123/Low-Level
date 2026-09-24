# SOLID — D: Dependency Inversion Principle

High-level code shouldn't be hard-wired to a specific low-level class —
both should depend on a shared abstraction (interface) instead.

## Bad example
```cpp
class EmailSender {
public:
    void send(string msg) { cout << "Email: " << msg << "\n"; }
};

class NotificationService {
    EmailSender sender;   // hard-wired to ONE specific concrete class
public:
    void notify(string msg) { sender.send(msg); }
};
```
Want to add SMS later? You have to go edit `NotificationService` itself.

## Fixed
```cpp
class Sender {
public:
    virtual void send(string msg) = 0;
    virtual ~Sender() = default;
};

class EmailSender : public Sender {
public:
    void send(string msg) override { cout << "Email: " << msg << "\n"; }
};

class NotificationService {
    Sender& sender;   // depends on the ABSTRACTION, not a specific class
public:
    NotificationService(Sender& s) : sender(s) {}
    void notify(string msg) { sender.send(msg); }
};
```
`NotificationService` now holds a `Sender&`, built via the constructor's
initializer list (same trick as the `Engine` example). It never mentions
`EmailSender` by name — so a future `SmsSender` just plugs in, with zero
changes to `NotificationService`.

## Real-world example
A wall socket. Appliances don't wire directly into the power plant — they
plug into a standard socket shape. The power source behind the wall can
change completely, and no appliance cares.

## One-line summary
Depend on the interface, not the specific class — so the specific class
can change without you having to change.
