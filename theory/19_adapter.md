# Adapter

Makes one class's interface work where a **different** interface is
expected, without changing either class.

Real-world example: a power plug adapter. Your laptop charger has one
plug shape, the wall socket has a different one. The adapter doesn't
change either — it just sits between them, translating the shape.

## When you need it
You have a class that does what you need, but its methods are shaped
differently from what your code expects, and you can't change that class
(often because it's a third-party library).

## The shape
Three pieces: the interface your code expects, the incompatible class you
can't touch, and the adapter connecting them.

```cpp
class MediaPlayer {
public:
    virtual void play() = 0;
    virtual ~MediaPlayer() = default;
};

class LegacyAudioPlayer {   // can't change this — imagine third-party
public:
    void playSound() { cout << "playing sound (legacy)\n"; }
};

class LegacyAudioPlayerAdapter : public MediaPlayer {
public:
    LegacyAudioPlayerAdapter(LegacyAudioPlayer& p) : legacy(p) {}
    void play() override { legacy.playSound(); }
private:
    LegacyAudioPlayer& legacy;
};
```

Using it:
```cpp
LegacyAudioPlayer old;
LegacyAudioPlayerAdapter adapter(old);
MediaPlayer* player = &adapter;
player->play();   // runs playSound() underneath
```

## It's really two things you already know, combined
- Adapter **has-a** `LegacyAudioPlayer&` — composition/association,
  injected through the constructor, same shape as `NotificationService`'s
  `Sender&` from the DIP topic.
- Adapter **is-a** `MediaPlayer` — inheritance, so it can be used
  anywhere a `MediaPlayer` is expected.

## In UML
- `LegacyAudioPlayerAdapter` → `MediaPlayer`: generalization.
- `LegacyAudioPlayerAdapter` → `LegacyAudioPlayer`: association (stored
  reference, not owned/created by the adapter).

## One-line summary
Wrap the incompatible class, implement the expected interface, translate
calls underneath.
