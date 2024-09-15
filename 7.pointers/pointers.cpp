#include <iostream>
using namespace std;

void pointer_increment(){
    char* str = new char[10]; 
    cout<<"str before increenting: "<<str<<endl;
    ++str; 
    cout<<"str after incrementing: "<<str<<endl;
    int* arr = new int[10]; 
    cout<<"arr before increenting: "<<arr<<endl;
    ++arr; 
    cout<<"arr after incrementing: "<<arr<<endl;
   
}

int main(){
    int var = 20;
    int *ptr;
    ptr = &var;
    cout << var << endl;
    //Outputs 20 (The value of var)
    cout << ptr << endl;
    //Outputs (var's memory location)
    cout << *ptr << endl;
    //Outputs 20(The value of the variable stored in the pointer ptr
    pointer_increment(); //similarly we can add or subtract valid values from pointers

    return 0;
}