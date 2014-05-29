/*
Solution for LeetCode problem

Title: Valid Palindrome
URL: https://oj.leetcode.com/problems/valid-palindrome/
Version: 1.0

Created by Darcy Liu on 5/30/14.
*/
#include <iostream>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        bool r = true;
        for (int i = 0,len = s.length()-1; i<len;){
            if (!isalnum(s[i])){
                i ++;
                continue;
            }
            if (!isalnum(s[len])){
                len --;
                continue;
            }
            if (tolower(s[i])!=tolower(s[len])){
                r = false;
                break;
            }else{
                i ++;
                len --;
            }
        }
        return r;
    }
};

int main()
{
    Solution solution;
    cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << solution.isPalindrome("race a car") << endl;
    return 0;
}