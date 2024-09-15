// A std::unique_ptr is a class template that manages the lifetime of a dynamically stored object. Unlike for
// std::shared_ptr, the dynamic object is owned by only one instance of a std::unique_ptr at any time,



// The class template std::shared_ptr defines a shared pointer that is able to share ownership of an object with
// other shared pointers. This contrasts to std::unique_ptr which represents exclusive ownership.
// The sharing behavior is implemented through a technique known as reference counting, where the number of
// shared pointers that point to the object is stored alongside it.
// To create multiple smart pointers that share the same object, we need to create another shared_ptr that aliases
// the first shared pointer.


#include <iostream>
#include <memory>

using namespace std;

int main(){
    // Creates a dynamic int with value of 20 owned by a unique pointer
    unique_ptr<int> ptr = make_unique<int>(20);
    cout<<*ptr<<endl;


    // Creates a unique_ptr to an array of 15 ints
    unique_ptr<int[]> ptr_arr = make_unique<int[]>(15);
    for(int i = 0; i < 15; i++){
        ptr_arr[i] = i;
        cout<<ptr_arr[i]<<" ";
    }
    cout<<endl;

    // 1. unique_ptr
    unique_ptr<int> ptr1 = make_unique<int>();
    // Change value to 1
    *ptr1 = 1;
    // 2. std::unique_ptr (by moving 'ptr' to 'ptr2', 'ptr' doesn't own the object anymore)
    unique_ptr<int> ptr2 = move(ptr1);
    int a = *ptr2; // 'a' is 1
    cout<<"Value of a: "<<a<<endl;

    // int b = *ptr1; // undefined behavior! 'ptr1' is 'nullptr'
    // cout<<"Value of b: "<<b<<endl;
    // // (because of the move command above)


    auto arr_ptr = std::make_unique<int[]>(10); // simple way to declare unique smart pointer
    arr_ptr[2] = 10; // Modify third element
    cout<<arr_ptr[2]<<endl;

 // shared smart pointers
    shared_ptr<int> firstShared = make_shared<int>(7);
    cout<<*firstShared<<endl;
    shared_ptr<int> secondShared = firstShared;
    cout<<*secondShared<<" "<<*firstShared<<endl;

    auto anotherShared = make_shared<int>(8);
    cout<<*anotherShared<<endl;

    auto anotherSharedArray = make_shared<int[]>(5); // array with shared pointer
    anotherSharedArray[2] = 2;
    cout<<anotherSharedArray[2]<<endl;


    return 0;
}