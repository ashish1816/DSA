/******************************************************************************
 * Contributed by:- Ashish Burnwal
 * Finding n-th term of fibonacci series using Matrix Exponentiation

Binary Exponentiation:- 
    1. if n is odd
        A^n = A^(n/2) * A^(n/2) * A 
    2. if n is even
        A^n = A^(n/2) * A^(n/2)

[ fib(n)        =   [ 1 1  * [ fib(n-1) 
  fib(n-1) ]          1 0 ]     fib(n-2) ]
  
  

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// multiply two square matrix
vector<vector<int> > multiply(vector<vector<int> > &a, vector<vector<int> > &b)
{
    vector<vector<int> > ans(a.size(), vector<int>(a.size(), 0));
    for(int i=0; i<a.size(); i++) {             // iterating a's row 
        for(int j=0; j<a.size(); j++) {         // iterating b's column
            for(int k=0; k<a.size(); k++) {     // iterating over the a's column or b's row
                ans[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    return ans;
}

// function to exponentiate square matrix to the power n
vector<vector<int> > matrixExponentiate(vector<vector<int> > &a, int n)
{
    // if power is zero, return identity matrix
    if(n==0) {
        vector<vector<int> > ans(a.size(), vector<int>(a.size(), 0));
        
        for(int i=0; i<a.size(); i++) {
            ans[i][i] = 1;
        }
        return ans;
    }
    
    // if power is one, return the matrix itself
    if(n==1) return a;
    
    // if power is greater than 1, do recursive calls
    vector<vector<int> > temp = matrixExponentiate(a, n/2);
    vector<vector<int> > ans = multiply(temp, temp);
    
    if(n&1) {
        ans = multiply(ans, a);
    }
    
    return ans;
}

int main()
{
    
    vector<vector<int> > M(2, vector<int>(2, 0));
    M[0][0] = 1, M[0][1] = 1;
    M[1][0] = 1, M[1][1] = 0;
    
    int n = 4;
    
    vector<vector<int> > ans = matrixExponentiate(M, n-2);
    
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans.size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    // fib(n) = matrixExponentiate(M, n-2) * [ fib(1)
    //                                         fib(0) ]
    
    cout << "The 4th fibonacci number is " << ans[0][0]*1 + ans[0][1]*1;
    
    return 0;
}
