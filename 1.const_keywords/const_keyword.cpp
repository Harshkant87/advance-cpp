#include<iostream>
using namespace std;

class Student
{
public:
    char& GetScore(bool midterm)
    {
        return const_cast<char&>(const_cast<const Student*>(this)->GetScore(midterm));
    }

    const char& GetScore(bool midterm) const
    {
        if (midterm)
        {
        return midtermScore;
        }
        else
        {
        return finalScore;
        }
    }

private:
    char midtermScore;
    char finalScore;
};
int main()
{
 // non-const object
 Student A;
 // We can assign to the reference. Non-const version of GetScore is called
 A.GetScore(true) = 'B';
 A.GetScore(false) = 'A';

 // const object
 const Student b(A);
 // We still can call GetScore method of const object,
 // because we have overloaded const version of GetScore
 cout << b.GetScore(true) << " "<< b.GetScore(false) << '\n';


 // const variable

 const int a = 10;
 cout<<"Value of const a: "<< a <<endl;
// a = 1; // error
//int &b = a; //error as a non constant reference can't bind to const variable
const int &c = a; //correct
cout<<"Value of const c: "<<c<<endl;

//int *d = &a; // Error: can't bind pointer-to-non-const to const variable
const int *e = &a; //correct, a pointer which points to const integer
cout<<"Value of const pointer e: "<< e <<endl;

// const pointer
int x = 0, y = 2;
const int* pA = &x; // pointer-to-const. `a` can't be changed through this
int* const pB = &x; // const pointer. `a` can be changed, but this pointer can't.
const int* const pC = &x; // const pointer-to-const.

cout<<"Value of pA: "<<pA<<endl;
cout<<"Value of pA: "<<pB<<endl;
cout<<"Value of pA: "<<pC<<endl;
//Error: Cannot assign to a const reference
// *pA = b;
// pA = &b;
// *pB = b;
//Error: Cannot assign to const pointer
// pB = &b;
//Error: Cannot assign to a const reference
// *pC = b;
//Error: Cannot assign to const pointer
// pC = &b;

}

// const member Function:

// The function is marked const, meaning it promises not to modify any member variables of the class it belongs to.
// This ensures that the function can be called on a const object.
