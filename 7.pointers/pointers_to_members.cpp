// A static member function is just like an ordinary C/C++ function, except with scope:
// It is inside a class, so it needs its name decorated with the class name;
// It has accessibility, with public, protected or private.
// So, if you have access to the static member function and decorate it correctly, then you can point to the function
// like any normal function outside a class:

#include <iostream>
using namespace std;

typedef int Fn(int); // Fn is a type-of function that accepts an int and returns an int
// Note that MyFn() is of type 'Fn'

int MyFn(int i) { return 2*i; }


class Class {
public:
    // Note that Static() is of type 'Fn'
    static int Static(int i) { return 3*i; }
    int twoTimes(int a){
        return 2*a;
    }
}; // Class


int main() {
 Fn *fn; // fn is a pointer to a type-of Fn
 fn = &MyFn; // Point to one function
 cout<<fn(3)<<endl; // Call it
 fn = &Class::Static; // Point to the other function
 cout<<fn(4)<<endl; // Call it

 Class c; // Need a Class instance to play with
 Class *p = &c; // Need a Class pointer to play with
 Fn Class::*fna; // fn is a pointer to a type-of Fn within Class
 fna = &Class::twoTimes; // fn now points to A within any Class
 int val = (c.*fna)(5); // Pass 5 to c's function A (via fn)
 cout<<val<<endl;

} // main()
