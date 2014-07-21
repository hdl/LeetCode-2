/*
Solution for LeetCode problem

Title: Roman to Integer
URL: https://oj.leetcode.com/problems/roman-to-integer/
Version: 1.0

Created by Darcy Liu on 7/16/14.
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    /* 
    Symbol  Value
    I   1
    V   5
    X   10
    L   50
    C   100
    D   500
    M   1,000

    the numeral I can be placed before V and X to make 4 units (IV) and 9 units (IX respectively)
    X can be placed before L and C to make 40 (XL) and 90 (XC respectively)
    C can be placed before D and M to make 400 (CD) and 900 (CM) according to the same pattern[5]

    details at http://en.wikipedia.org/wiki/Roman_numerals
    */
    int romanToInt(string s) {
        int count = 0;
        for (int i = 0, len = s.length(); i < len; ++i) {
            //cout << s.at(i) << endl;
            if (s.at(i) == 'M') {
                count += 1000;
            } else if (s.at(i) == 'D') {
                count += 500;
            } else if (s.at(i) == 'C') {
                if ( (i+1)<len && s.at(i+1) == 'D'){
                    count += 400; // CD == 400
                    i ++;
                } else if ((i+1)<len && s.at(i+1) == 'M') {
                    count += 900; // CM == 900
                    i ++;
                } else {
                    count += 100;
                }
            } else if (s.at(i) == 'L') {
                count += 50;
            } else if (s.at(i) == 'X') {
                if ( (i+1)<len && s.at(i+1) == 'L'){
                    count += 40; // XL == 40
                    i ++;
                } else if ((i+1)<len && s.at(i+1) == 'C') {
                    count += 90; // XC == 90
                    i ++;
                } else {
                    count += 10;
                }
            } else if (s.at(i) == 'V') {
                count += 5;
            } else if (s.at(i) == 'I') {
                if ( (i+1)<len && s.at(i+1) == 'V'){
                    count += 4; // IV == 4
                    i ++;
                } else if ((i+1)<len && s.at(i+1) == 'X') {
                    count += 9; // IX == 9
                    i ++;
                } else {
                    count += 1;
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution solution;
    cout << solution.romanToInt(string("MCMLIV")) << endl; //1954
    cout << solution.romanToInt(string("MCMXC")) << endl; //1990
    cout << solution.romanToInt(string("MMXIV")) << endl; //2014
    return 0;
}