#include <iostream>
#include <vector>
using namespace std;

//asm:
//The asm keyword takes a single operand, which must be a string literal. It has an implementation-defined meaning,
// but is typically passed to the implementation's assembler, with the assembler's output being incorporated into the
// translation unit

void halt_system() {
 cout<<"System halts!"<<endl;
 asm("hlt");
 cout<<"Exiting.."<<endl; //this part will not be called
}

//volatile:
// The volatile keyword in C++ is used to tell the compiler that a variable's value can change at any time, without the
//  compiler's knowledge. It prevents the compiler from optimizing access to that variable, ensuring that every read 
//  and write happens exactly as it's written in the code.

void func_use_volatile(){
    volatile int CricketScore;
    cout<<"Initial value: "<<CricketScore<<endl;
    CricketScore = 300;
    cout<<"After change: "<<CricketScore<<endl;
}

// explicit: 
// When applied to a single-argument constructor, prevents that constructor from being used to perform
// implicit conversions.

class MyVector {
 private:
    vector<int>v;
 public:
 explicit MyVector(uint64_t size){
    v.resize(size);
 };
};

int main(){
    // halt_system();
    //func_use_volatile();
    MyVector v1(100); // ok
    uint64_t len1 = 100;
    MyVector v2{len1}; // ok, len1 is uint64_t
    int len2 = 100;
    //MyVector v3{len2}; // ill-formed, implicit conversion from int to uint64_t
    return 0;
}