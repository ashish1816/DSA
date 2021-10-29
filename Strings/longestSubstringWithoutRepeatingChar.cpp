/******************************************************************************
 * Contributed by:- Tanisha Bhadani
        Leetcode Problem 3:- Longest Substring Without Repeating Characters
    
    Given a string s, find the length of the longest substring without repeating characters.

    Input:- s = "abcabcbb"
    Output:- 3      abc | bca | cab 
    
    Time Complexity:- O(n)
    Space Complexity:- O(1)     // Constant space for auxilliary array

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int longSub(string &s) {
    int left=0, right=0;
    int n=s.size();
    
    int len = 0;
    
    // storing the index of last occurance of a alphabet in the table
    vector<int> seen(256, -1);      // -1 represents the alphabet is not seen yet
    
    while(right<n) {
        if(seen[s[right]]!=-1) {
            left = max(seen[s[right]]+1, left);     // discarding all values before recent repeated character
        }
        len = max(right-left+1, len);
        seen[s[right]] = right;
        right++;
    }
    return len;
}

int main()
{
    string s = "abcabcbb";
    
    int len = longSub(s);
    
    cout << len;

    return 0;
}