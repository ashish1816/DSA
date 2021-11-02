/******************************************************************************
                    Sieve of Eratosthenes
                    ----------------------
        Time Complexity:- O(log(log n)
        Space Complexity:- O(n)
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<bool> sieve(10000, true);

void sievePrime(int n) {
    sieve[0] = false;
    sieve[1] = false;
    for(int i=2; i*i<=n; i++) {
        if(sieve[i]) {
            for(int j=i; j*i<=n; j++) 
                sieve[j*i] = false;
        }
    }
}

int main()
{
    int n = 9999;
    
    sievePrime(n);
    
    for(int i=1; i<100; i++) {
        if(sieve[i]) cout << i << "  ";
    }
    return 0;
}