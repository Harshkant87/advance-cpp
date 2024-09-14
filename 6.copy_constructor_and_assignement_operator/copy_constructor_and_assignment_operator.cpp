#include <iostream>
#include <string>
using namespace std;

class Student{
private:
    int roll;
    string Name;
    int *schoolID;

public:
    Student(int roll_num, string name, int schID){
        roll = roll_num;
        Name = name;
        schoolID = &schID;
    }

    void get_info(){
        cout<<"Name: "<<Name<<", roll num: "<<roll<< ", schoolID: " << schoolID <<endl;;
        cout<<endl;

    }

    Student(const Student &s1){ // copy constructor
        cout<<"Copy constructor called."<<endl;
        roll = s1.roll;
        Name = s1.Name;
        //schoolID = s1.schoolID; // shallow copy
        // schoolID = &(s1.schoolID);
        schoolID = new int; //deep copy
        *schoolID =  *s1.schoolID;
    }

    Student& operator= (const Student &s1){ //assignment operator
        cout<<"Assignement operator called."<<endl;
        roll = s1.roll;
        Name = s1.Name;
        //schoolID = s1.schoolID; // shallow copy
        // schoolID = &(s1.schoolID);
        schoolID = new int; //deep copy
        *schoolID =  *s1.schoolID;
        return *this;
    }

};


int main(){
    Student Harsh(6, "Harsh Kant", 5);
    Harsh.get_info();
    Student Ayush(Harsh); // copy constructor called
    Ayush.get_info();
    Student Atul = Harsh; // copy constructor called
    Atul.get_info();
    Student Akash(7, "Akash Kumar", 8);
    Akash.get_info();
    Akash = Harsh; // assingment operator called
    Akash.get_info();
    //Note: Copy constructor called when we dont initialize the object and assignement operator called when 
    //we assign after the initialization.
    return 0;
}