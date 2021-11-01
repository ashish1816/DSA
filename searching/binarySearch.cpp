/******************************************************************************
 * Contibuted by:- Tanisha Bhadani
        Leetcode Problem 704. Binary Search
    Given an array of integers nums which is sorted in ascending order, and an 
    integer target, write a function to search target in nums. If target exists, 
    then return its index. Otherwise, return -1. 
    Input:- nums = [-1,0,3,5,9,12], target = 9
    Output:- 4
    
    Time complexity:- O(log n)
    Space complexity:- O(1)
                              
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &nums, int target) {
    int start = 0;
    int end = nums.size()-1;
    
    while(start<=end) {
        int mid = start+(end-start)/2;
        
        if(target==nums[mid]) return mid;
        else if(target>nums[mid]) start = mid+1;
        else end = mid-1;
    }
    return -1;
}

int main()
{
    vector<int> nums = { -1,0,3,5,9,12 };
    int target = 9;
    
    int result = binarySearch(nums, target);
    
    cout << result;
    return 0;
}