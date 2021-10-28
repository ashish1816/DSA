/******************************************************************************
    Contributed by:- Tanisha Bhadani
        Merge two sorted arrays into third auxillary array
        a[] = {1, 3, 4, 7}
        b[] = {2, 4, 6, 8}
        result[] = {1, 2, 3, 4, 4, 6, 7, 8}

        m = size of a
        n = size of b

        Time Complexity:- O(m+n)
        Space Complexity:- O(m+n)
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> &a, vector<int> &b) {
    int m = a.size();
    int n = b.size();
    
    int i=0;
    int j=0;
    int k=0;
    
    vector<int> result(m+n, -1);
    
    while(i<a.size() && j<b.size()) {
        if(a[i]<b[j]) {
            result[k] = a[i++];
        } else {
            result[k] = b[j++];
        }
        k++;
    }
    
    while(i<a.size()) {
        result[k] = a[i++];
        k++;
    }
    while(j<b.size()) {
        result[k] = b[j++];
    }
    return result;
}

int main()
{
    vector<int> a = {1, 3, 4, 7};
    vector<int> b = {2, 4, 6, 8};
    
    vector<int> result = merge(a, b);
    
    for(auto i: result) {
        cout << i << " ";
    }
    return 0;
}