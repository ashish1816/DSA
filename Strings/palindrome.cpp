/**
Given a string the programm tries to find if this string is a Palindrome.
Palindrome is a word or sequence that reads the same backwards as forwards.

Example:
    word: madam --> true
    word: nurse --> false
    number: 68986 --> true
    number: 12346 --> false

Time complexity: O(n)
Space complexity: O(n)
*/

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome( string s ) {
    for( int i = 0; i<s.length()/2; i++) {
        if( s[i] != s[s.length()-1-i] ) {
            return false;
        }
    }
    return true;
}

int main() {
    string word;
    cout<<"Please write a word : ";
    cin>>word;
    if( isPalindrome( word ) ) {
        cout<<"Your word is a Palindrome";
    } else {
        cout<<"Your word is not a Palindrome";
    }
}

