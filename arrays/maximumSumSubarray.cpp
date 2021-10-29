/******************************************************************************
 *  Contributed by:- Tanisha Bhadani
            Leetcode Problem 53.  Maximum sum subarray
    Given an integer array nums, find the contiguous subarray (containing at 
    least one number) which has the largest sum and return its sum.

    A subarray is a contiguous part of an array.
    
    Input:- [-2,1,-3,4,-1,2,1,-5,4]
    Output:- 6
    Input:- [-1, -7]
    Output:- -1
*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxSubSum(vector<int> &v) {
    int n = v.size();
    int curr_sum = 0;
    int max_sum = INT_MIN;
    
    for(int i=0; i<n; i++) {
        curr_sum = max(v[i], curr_sum+v[i]);
        max_sum = max(curr_sum, max_sum);
    }
    return max_sum;
}

int main()
{
    vector<int> v = { -2,1,-3,4,-1,2,1,-5,4 };
    
    int res = maxSubSum(v);
    
    cout << res;

    return 0;
}