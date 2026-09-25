// Practice: Abstract Factory
// Read theory/16_abstract_factory.md first if you haven't.
// Building this one tiny piece at a time. Don't look ahead.

#include <iostream>
#include <memory>
using namespace std;

// STEP 1: write the two product interfaces ONLY.
//   Button — pure virtual render(), plus a virtual destructor
//   Checkbox — pure virtual render(), plus a virtual destructor
// Nothing else yet — no Dark/Light versions, no factory.
class Button{
    public: 
        virtual void render() = 0 ;
        virtual ~Button() = default;
};
class Checkbox{
    public: 
        virtual void render() = 0 ;
        virtual ~Checkbox() = default;
};

class DarkButton : public Button{
    public:
        void render() override{
            cout << "[dark button]\n";
        }
};
class DarkCheckbox : public Checkbox{
    public:
        void render() override{
            cout << "[dark CheckBox]\n";
        }
};

class LightButton : public Button{
    public:
        void render() override{
            cout << "[Light button]\n";
        }
};
class LightCheckbox : public Checkbox{
    public:
        void render() override{
            cout << "[Light CheckBox]\n";
        }
};

class UIFactory {
    public:
        virtual unique_ptr<Button> createButton()=0;
        virtual unique_ptr<Checkbox> createCheckbox()=0;
        virtual ~UIFactory()= default;
};
class DarkFactory : public UIFactory{
    public:
        unique_ptr<Button> createButton() override{
            return make_unique<DarkButton>();
        }
        unique_ptr<Checkbox> createCheckbox() override{
            return make_unique<DarkCheckbox>();
        }
};
class LightFactory : public UIFactory{
    public:
        unique_ptr<Button> createButton() override{
            return make_unique<LightButton>();
        }
        unique_ptr<Checkbox> createCheckbox() override{
            return make_unique<LightCheckbox>();
        }
};
int main() {
    unique_ptr<UIFactory> factory = make_unique<DarkFactory>();
    unique_ptr<Button> btn = factory->createButton();
    unique_ptr<Checkbox> chk = factory->createCheckbox();
    btn->render();
    chk->render();
    return 0;
}
