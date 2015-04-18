#include <iostream>
using namespace std;

int mySqrt (int n) {

    double x = n;
    double y = 1;

    // Required accuracy
    double e = 0.00001;

    while(x-y > e) {
        x = (x+y)/2;
        y = n/x;

    }    
    return (int)x;
}
