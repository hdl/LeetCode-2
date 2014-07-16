/*
Solution for LeetCode problem

Title: Integer to Roman
URL: https://oj.leetcode.com/problems/integer-to-roman/
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
    string intToRoman(int num) {
        string letters;
        int i = 0;

        while(num>=1000) { //M
            letters.append("M");
            num -= 1000;
            i ++;
        }
        while(num>=900) { //CM
            letters.append("CM");
            num -= 900;
            i ++;
        }
        while(num>=500) { //D
            letters.append("D");
            num -= 500;
            i ++;
        }
        while(num>=400) { //CD
            letters.append("CD");
            num -= 400;
            i ++;
        }
        while(num>=100) { //C
            letters.append("C");
            num -= 100;
            i ++;
        }
        while(num>=90) { //XC
            letters.append("XC");
            num -= 90;
            i ++;
        }
        while(num>=50) { //L
            letters.append("L");
            num -= 50;
            i ++;
        }
        while(num>=40) { //XL
            letters.append("XL");
            num -= 40;
            i ++;
        }
        while(num>=10) { //X
            letters.append("X");
            num -= 10;
            i ++;
        }
        while(num>=9) { //IX
            letters.append("IX");
            num -= 9;
            i ++;
        }
        while(num>=5) { //V
            letters.append("V");
            num -= 5;
            i ++;
        }
        while(num>=4) { //IV
            letters.append("IV");
            num -= 4;
            i ++;
        }
        while(num>=1) { //I
            letters.append("I");
            num -= 1;
            i ++;
        }
        return letters;
    }
};

int main()
{
    Solution solution;
    cout << solution.intToRoman(1954) << endl; //"MCMLIV"
    cout << solution.intToRoman(1990) << endl; //"MCMXC"
    cout << solution.intToRoman(2014) << endl; //"MMXIV"
    cout << solution.intToRoman(3999) << endl; //"MMMCMXCIX"
    return 0;
}