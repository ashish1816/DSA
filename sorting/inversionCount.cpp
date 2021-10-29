/******************************************************************************
 * Contributed by:- Tanisha Bhadani
            Counting number of inversions using Merge Sort Algorithm
        Given an array of unsorted elements, sort them.
        
        Time Complexity:- O(n)
        Space Complexity:- O(n)
                              
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int> &v, int start, int mid, int end) {
    // create an auxilliary array where sorted elements will be inserted
    vector<int> temp(end-start+1);
    
    int count=0;
    
    int i=start, j=mid+1;
    int k=0;
    
    while(i<=mid && j<=end) {
        if(v[i]<v[j]) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
            count += mid-i+1;
        }
    }
    
    while(i<=mid) {
        temp[k++] = v[i++];
    }
    while(j<=end) {
        temp[k++] = v[j++];
    }
    
    // bring back the sorted elements from temp to original array
    for(int i=start; i<=end; i++) {
        v[i] = temp[i-start];
    }
    
    return count;
    
}

int mergeSortInversionCount(vector<int> &v, int start, int end) {
    int inversionCount = 0;
    
    int mid = start + (end-start)/2;
    if(start<end) {
        // left split inversionCount
        inversionCount += mergeSortInversionCount(v, start, mid);
        // right split inversionCount
        inversionCount += mergeSortInversionCount(v, mid+1, end);
        // split merge inversionCount
        inversionCount += merge(v, start, mid, end);
    }
    return inversionCount;
}

int main()
{
    vector<int> v = {4, 8, 2, 4, 1, 5, 9};
    int start = 0;
    int end = v.size()-1;
    
    int res = mergeSortInversionCount(v, start, end);
    
    for(auto i: v) {
        cout << i << " ";
    }
    cout << "\n" << res;

    return 0;
}