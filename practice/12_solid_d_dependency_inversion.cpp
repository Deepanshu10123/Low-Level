// Practice: SOLID - Dependency Inversion Principle
// Read theory/12_solid_d_dependency_inversion.md first if you haven't.
// Building this one tiny piece at a time. Don't look ahead.

#include <iostream>
using namespace std;

// STEP 1: just write the Sender interface — ONE pure virtual method,
// send(string msg). Nothing else yet, no EmailSender, no
// NotificationService.
class Sender{
    public:
        virtual void send(string msg)=0;
        virtual ~Sender()=default;
};
class EmailSender : public Sender{
    public:
        void send(string msg) override{
            cout<<"Email: " << msg;
        }
};
class SmsSender : public Sender{
    public:
        void send(string msg) override{
            cout<<"SMS: " << msg;
        }
};
class NotificationService{
    Sender& s;
    public:
        NotificationService(Sender & s) : s(s){}
        void notify(string msg){
            s.send(msg);
        }
};
int main() {
    EmailSender e ;
    NotificationService s(e);
    s.notify("hello");
    SmsSender sms;
    NotificationService service2(sms);
    service2.notify("hi");

    return 0;
}
