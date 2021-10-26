/******************************************************************************
    Problem:- 
        Given a string, check whether it's a Pangram or not.
        Pangram:- A pangram is a sentence containing every letter in the English Alphabet.
        Eg:- "the quick brown fox jumps over the lazy dog"
        
        Input:- A sentence with every letter in lower case
        Output:- true/ false

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkPangram(string s) {
    vector<bool> mark(26, false);

    for(int i=0; i<s.length(); i++) {
        if(s[i]>='a' && s[i]<='z')
            mark[(s[i]-'a')] = true;
    }
    
    for(int i=0; i<26; i++) {
        if(!mark[i]) return false;
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    
    bool result = checkPangram(s);
    
    cout << (result ? "true" : "false");

    return 0;
}