/*
    * Sorted order is red < green < blue
    * Dutch National Flag Algorithm
*/
#include <iostream>
#include <vector>
#include <string>

vector<string> solve(vector<string>& strs) {
    int size = strs.size();
    int low=0, mid=0, high=size-1;

    // low is for red, mid is for green, high is for blue
    while(mid<=high) {
        if(strs[mid]=="red") {
            swap(strs[mid], strs[low]);
            mid++; low++;
        }
        else if(strs[mid]=="green") {
            mid++;
        }
        else if(strs[mid]=="blue") {
            swap(strs[mid], strs[high]);
            // we still don't know whether the mid was pointing to red or green, so we don't increment mid
            high--;
        }
    }
    return strs;
}

int main() {
    vector<string> strs = {"red", "blue", "blue", "green", "red", "green"};

    solve(strs);

    for(auto i: strs) {
        cout << i << " ";
    }
    return 0;
}