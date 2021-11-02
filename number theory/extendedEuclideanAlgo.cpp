/******************************************************************************

                        Extended Euclidean Algorithm
        Time Complexity:- O(log (max(a, b)))
*******************************************************************************/

#include <iostream>

using namespace std;

int d, x, y;

void extendedEuclidean(int a, int b) {
    if(b==0) {
        d = a;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclidean(b, a%b);
        int temp = x;
        x = y;
        y = temp - (a/b)*y;
    }
}

int main()
{
    int a=108, b=48;
    
    extendedEuclidean(a, b);
    
    cout << "The gcd of " << a << " and " << b << " b is " << d << ".\n";
    cout<< "x : " << x;
    cout << "\ny : " << y;
    return 0;
}