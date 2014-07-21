/*
Solution for LeetCode problem

Title: Valid Number
URL: https://oj.leetcode.com/problems/valid-number/
Version: 1.0

Created by Darcy Liu on 7/21/14.
*/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isNumber(const char *s) {
        bool valid = true;
        int e = 0 , sign = 0 /*plus = 0, minus = 0*/, dot = 0, num = 0, space = 0;
        while (*s!='\0') {
            if (*s == ' '){
                s ++;
                continue;
            }
            break;
        }
        while (*s!='\0') {
            if (*s == ' ') {
                space ++;
            } else {
                if (space > 0) {
                    valid = false;
                    break;
                }
                if ( *s >='0' && *s <= '9') {
                    num ++;
                } else if ( *s == '+' || *s == '-' ) {
                    sign ++;
                    if ( num > 0 || dot > 0) {
                        valid = false;
                        break;
                    }
                } else if ( *s == '.' ) {
                    dot ++;
                    if ( e > 0 || dot >1) {
                        valid = false;
                        break;
                    }
                } else if ( *s == 'e' || *s == 'E' ) {
                    e ++;
                    if ( num == 0 || e > 1) {
                        valid = false;
                        break;
                    } else {
                        num = 0, sign = 0, dot = 0; // reset
                    }
                } else {
                    valid = false;
                    break;
                }
            }
            s++;
        }
        if (num == 0 || dot > 1) {
            valid = false;
        }
        return valid;
    }
};

int main()
{
    Solution solution;

    assert(solution.isNumber("0") == true);
    assert(solution.isNumber(" 0.1 ") == true);
    assert(solution.isNumber("abc") == false);
    assert(solution.isNumber("1 a") == false);
    assert(solution.isNumber("2e10") == true);
    assert(solution.isNumber("e") == false);
    assert(solution.isNumber(" ") == false);
    assert(solution.isNumber(".1") == true);
    assert(solution.isNumber("0e") == false);
    assert(solution.isNumber("e9") == false);
    assert(solution.isNumber("0.1e2") == true);
    assert(solution.isNumber("10e") == false);
    assert(solution.isNumber(". 1") == false);
    assert(solution.isNumber("1 4") == false);
    assert(solution.isNumber("..2") == false);
    assert(solution.isNumber("6+1") == false);
    assert(solution.isNumber(".-4") == false);
    assert(solution.isNumber("6e6.5") == false);
    assert(solution.isNumber("123e45e6") == false);
    assert(solution.isNumber("6e+5") == true);
    
    return 0;
}