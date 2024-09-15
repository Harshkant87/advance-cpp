// All non-static member functions have a hidden parameter, a pointer to an instance of the class, named this; this
// parameter is silently inserted at the beginning of the parameter list, and handled entirely by the compiler. When a
// member of the class is accessed inside a member function, it is silently accessed through this; this allows the
// compiler to use a single non-static member function for all instances, and allows a member function to call other
// member functions polymorphically.
#include <iostream>
#include <string>
using namespace std;

class Class
{
 public:
    Class();
    ~Class();
    int getPrivateNumber () const;
 private:
    int private_number = 42;
};

Class::Class(){}
Class::~Class(){}

int Class::getPrivateNumber() const
{
    return this->private_number;
}

int main()
{
 Class class_example;
 cout << class_example.getPrivateNumber() << endl;
}


// const instances can access const and const volatile functions.
// volatile instances can access volatile and const volatile functions.
// const volatile instances can access const volatile functions
