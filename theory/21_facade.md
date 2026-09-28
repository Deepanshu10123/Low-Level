# Facade

One simple entry point that hides a **complex, multi-step subsystem**
behind a single easy method.

Real-world example: a restaurant counter. You just say "one burger meal"
to the cashier. Behind the scenes, the grill, the fryer, and the drink
station all coordinate — but you only ever talked to one person.

## The problem it avoids
A home theater has a projector, a sound system, and a streaming device —
each its own class with its own methods. Without a Facade, "watch a
movie" means calling several methods, on several objects, in the right
order, every single time you want to watch something.

## The shape
```cpp
class Projector {
public:
    void turnOn() { cout << "Projector on\n"; }
};
class SoundSystem {
public:
    void turnOn() { cout << "Sound on\n"; }
};
class StreamingDevice {
public:
    void play() { cout << "Streaming started\n"; }
};

class HomeTheaterFacade {
public:
    HomeTheaterFacade(Projector& p, SoundSystem& s, StreamingDevice& d)
        : projector(p), sound(s), streaming(d) {}
    void watchMovie() {
        projector.turnOn();
        sound.turnOn();
        streaming.play();
    }
private:
    Projector& projector;
    SoundSystem& sound;
    StreamingDevice& streaming;
};
```

Using it:
```cpp
Projector p; SoundSystem s; StreamingDevice d;
HomeTheaterFacade theater(p, s, d);
theater.watchMovie();   // one call instead of three
```

## Nothing new mechanically
The Facade just holds references to each subsystem piece — same
constructor-injection shape as `NotificationService` (DIP topic) and
`LegacyAudioPlayerAdapter` (Adapter topic). Its one public method just
calls each piece's method, in the right order.

## In UML
`HomeTheaterFacade` → `Projector`/`SoundSystem`/`StreamingDevice`:
association (stored references, not owned/created by the facade).

## One-line summary
Wrap a messy multi-step process behind one clean method — the caller
never needs to know the subsystem exists.
