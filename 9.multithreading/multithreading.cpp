#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

void sayHello()
{
 cout<<"Hello I am thread number: "<<this_thread::get_id<<endl;
 return;
}

int increm_x(int &x, mutex &m){
    m.lock();
    cout<<"Thread pid: "<<this_thread::get_id()<<endl;
    x++;
    m.unlock();
    return 0;
}

void foo(int& b)
{
     b = 10;
}

int main() {
    int a = 1;
    auto lambda = [](int a) { std::cout << a << '\n'; };


    thread thread1( foo, ref(a)); //'a' is now really passed as reference
    // Create and execute the thread
    thread thread2(lambda, 20); // Pass 10 to the lambda expression


    // The lambda expression will be executed in a separate thread
    // Wait for the thread to finish, this is a blocking operation
    thread1.join();
    thread2.join();
    cout << a << '\n'; //Outputs 10

    mutex mlock;
    int x = 0;
    thread thread3(increm_x, ref(x), ref(mlock));
    thread thread4(increm_x, ref(x), ref(mlock));
    thread3.join();
    thread4.join();
    cout<<"Value of x: "<<x<<endl;

    //create 100 thread objects that do nothing
    thread executors[10];


    // Some code
    // I want to create some threads now
    for (int i = 0;i < 10;i++)
    {
        // If this object doesn't have a thread assigned
        if (!executors[i].joinable())
            executors[i] = thread(sayHello);
    }

	return 0;
}