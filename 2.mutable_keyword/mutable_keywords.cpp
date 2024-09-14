#include<iostream>
using namespace std;

int main(){

    int a = 0;

    // auto bad_counter = [a] {
    //     return a++;
    // };

    auto good_counter = [a] () mutable {
        return a++;
    };

    good_counter();
    cout<<a<<endl;
    good_counter();
    cout<<a<<endl;


    return 0;
}