#include <iostream>
using namespace std;

class pi_calculator {
public:
    double get_pi() const { // const function will not change the object
        if (pi_calculated) {
        return pi;
        }
        else {
        double new_pi = 0;
        for (int i = 0; i < 100; ++i) {
        // some calculation to refine new_pi
        new_pi = i + 1;
        }
        // note: if pi and pi_calculated were not mutable, we would get an error from a compiler
        // because in a const method we can not change a non-mutable field
        pi = new_pi;
        pi_calculated = true;
        return pi;
        }
    }
private:
    mutable bool pi_calculated = false;
    mutable double pi = 0;
};

int main(){
    pi_calculator p_cal;
    cout<<p_cal.get_pi()<<endl;
    return 0;
}