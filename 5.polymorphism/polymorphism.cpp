// vtable: An array of function pointers for each virtual function.
// vptr (Virtual Table Pointer): Each object of a class with virtual functions contains a hidden 
// pointer (called vptr) that points to the vtable for the class.

#include <iostream>
#include <string>
using namespace std;

class Animal{
public:
    Animal(){
        cout<<"Animal constructor called."<<endl;
    }

    virtual void sound(){
        cout<<"Hi I am Animal"<<endl;
    }

    virtual void sound(string voice){
        cout<<"Hey: "<< voice <<endl;
    }

    virtual ~Animal() { // use of virtual keyword to ensure destruction of derived classes properly
        cout<<"Animal destructor called."<<endl;
    }
};

class Dog : public Animal{
public:
    Dog(){
        cout<<"Dog constructor called"<<endl;
    }

    void sound() override{
        cout<<"Dog barks!"<<endl;
    }

    void sound(string voice) override{
        cout<<"Hey "<< voice <<endl;
    }

    ~Dog(){
        cout<<"Dog destructor called."<< endl;
    }
};

class Husky : public Dog{
public:
    Husky(){
        cout<<"Husky Constructor is called."<<endl;
    }

    void sound() override {
        cout<<"Bhaw bhaw"<<endl;
    }

    void sound(string voice) override {
        cout<<"I am husky: "<< voice <<endl;
    }

    ~Husky(){
        cout<<"Husky destructor"<<endl;
    }

};

int main(){
    // Animal A;
    // A.sound();
    // A.sound("Moo");
    // Dog D1;
    // D1.sound();
    // D1.sound("Grrr");
    // Animal *A_ptr = new Dog();
    // A_ptr -> sound();
    // A_ptr -> sound("Mmm");
    // delete A_ptr;
    Animal *A_ptr1 = new Husky();
    A_ptr1 -> sound();
    A_ptr1 -> sound("Pheww");
    delete A_ptr1;
    return 0;
}