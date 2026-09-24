// Practice: Factory Method
// Read theory/15_factory_method.md first if you haven't.
// Building this one tiny piece at a time. Don't look ahead.

#include <iostream>
#include <string>
#include <memory>
using namespace std;

// STEP 1: write the abstract Product (pure virtual name() returning a
// string and price() returning a double, plus a virtual destructor),
// and ONE concrete class, Soda, that inherits from it.
// Nothing else yet.
class Product{
    public:
        virtual string name()=0;
        virtual double price()=0;
        virtual ~Product()=default;
};
class Soda: public Product{
    public:
        string name() override{
            return "Soda";
        }
        double price() override{
            return 10.0;
        }
};
class Candy: public Product{
    public:
        string name() override{
            return "Candy";
        }
        double price() override{
            return 50.0;
        }
};
class Chips: public Product{
    public:
        string name() override{
            return "Chips";
        }
        double price() override{
            return 20.0;
        }
};

// Product* createProduct(string code){
//     if(code == "A1"){
//         Product* p = new Soda();
//         return p;
//     }
//     if(code == "B1"){
//             Product* p = new Chips();
//             return p;
//         }
//     if(code == "C1"){
//         Product* p = new Candy();
//         return p;
//     }
//     return nullptr;
// }
unique_ptr<Product> createProduct(string code){
    if(code == "A1"){
        unique_ptr<Product> p = make_unique<Soda>();
        return p;
    }
    if(code == "B1"){
            unique_ptr<Product> p = make_unique<Chips>();
            return p;
        }
    if(code == "C1"){
        unique_ptr<Product> p = make_unique<Candy>();
        return p;
    }
    return nullptr;
}
int main() {
    // Product* p = createProduct("A1");
    unique_ptr<Product> p = createProduct("A1");
    cout<<p->name()<<" "<<p->price();
    unique_ptr<Product> q = createProduct("C1");
    cout<<q->name()<<" "<<q->price();
    unique_ptr<Product> x = createProduct("Z9");
    if (x == nullptr) {
        cout << "No such product";
    } else {
        cout << x->name();
    }
    // delete p;
    return 0;
}
