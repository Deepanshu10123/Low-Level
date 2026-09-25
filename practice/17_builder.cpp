// Practice: Builder
// Read theory/17_builder.md first if you haven't.
// Building this one tiny piece at a time. Don't look ahead.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// STEP 1: write ONLY the Pizza class (the "product") — a public
// string size, and a public vector<string> toppings. Nothing else yet,
// no PizzaBuilder.
class Pizza {
    public:
        string size;
        vector<string> toppings;
};
class PizzaBuilder{
    private:
        Pizza pizza;
    public:
        PizzaBuilder& setSize(string s)
        {
            pizza.size=s;
            return *this ;
        }
        PizzaBuilder& addTopping(string t)
        {
            pizza.toppings.push_back(t);
            return *this;
        }
        Pizza build(){
            return pizza;
        }
};
int main() {
    Pizza p = PizzaBuilder().setSize("large").addTopping("cheese").addTopping("olives").build();
    cout << p.size << ": ";
    for (const auto& t : p.toppings) cout << t << " ";
    return 0;
}
