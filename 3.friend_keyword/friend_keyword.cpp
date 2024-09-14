// A class or a structure may declare any function it's friend. If a function is a friend of a class, it may access all it's
// protected and private members:
//Friend declarations are not inherited.

#include <iostream>
using namespace std;

//forward declaration
void friend_function();
void non_friend_function();

class WomenParents{
public:
    void access_the_women_age();
};

class GentleMen{
public:
    void women_age_acessor();
};

class Women {
public:
    Women(int val) : age(val) {}
private:
    int age;
    // Declare one of the function as a friend.
    friend void friend_function();
    //we can also use friend keyword with mthods of other classes, other class member function can also be friend to this class
    friend void GentleMen :: women_age_acessor();
    // we can make a different class as friend class
    friend class WomenParents;

};

// void non_friend_function() {
//  PrivateHolder ph(10);
//  // Compilation error: private_value is private.
//  std::cout << ph.private_value << std::endl;
// }

void friend_function() {
 // OK: friends may access private values.
 Women Maria(30);
 cout << Maria.age << endl;
}

// ----------friend_method ----------------
void GentleMen :: women_age_acessor(){
    Women Daisy(25);
    cout<<Daisy.age<<endl;
}

// A friend class of Women can also acess private values of Women Class
void WomenParents :: access_the_women_age(){
    Women Priya(15);
    cout<<Priya.age<<endl;
}

int main(){
    friend_function();
    GentleMen Harsh;
    Harsh.women_age_acessor();
    WomenParents Ashok;
    Ashok.access_the_women_age();
    return 0;
}