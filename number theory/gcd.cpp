/******************************************************************************

                        GCD of two numbers:-
        Time Complexity:- O(log(max(a, b)))

*******************************************************************************/

#include <iostream>

using namespace std;
int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

int main()
{
    int a=105, b=35;
    
    int res = gcd(a, b);
    
    cout<< res;
    return 0;
}