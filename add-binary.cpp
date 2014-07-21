/*
Solution for LeetCode problem

Title: Add Binary
URL: https://oj.leetcode.com/problems/add-binary/
Version: 1.0

Created by Darcy Liu on 7/21/14.
*/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0;
        int i = a.length()-1, j = b.length()-1;
        for (; i >=0 && j >= 0; i--,j--){
            if (a.at(i)=='1' && b.at(j)=='1') {
                if (carry==1) {
                    result.insert(result.begin(),'1');
                } else {
                    result.insert(result.begin(),'0');
                }
                carry = 1;
            } else if ((a.at(i)=='1' && b.at(j)=='0') || (a.at(i)=='0' && b.at(j)=='1')){
                if (carry==1) {
                    carry = 1; // keep carry
                    result.insert(result.begin(),'0');
                }else{
                    result.insert(result.begin(),'1');
                }
            } else { // both 0
                if (carry==1) {
                    carry = 0;
                    result.insert(result.begin(),'1');
                }else{
                    result.insert(result.begin(),'0');
                }
            }
        }
        for (; i >= 0; i--) {
            if (a.at(i)=='1' && carry==1) {
                result.insert(result.begin(),'0');
            } else if ((a.at(i)=='1' && carry==0)||(a.at(i)=='0' && carry==1)) {
                carry = 0;
                result.insert(result.begin(),'1');
            } else {
                result.insert(result.begin(),'0');
            }         
        }

        for (; j >= 0; j--) {
            if (b.at(j)=='1' && carry==1) {
                result.insert(result.begin(),'0');
            } else if ((b.at(j)=='1' && carry==0)||(b.at(j)=='0' && carry==1)) {
                carry = 0;
                result.insert(result.begin(),'1');
            } else {
                result.insert(result.begin(),'0');
            }         
        }
        if (carry == 1){
            result.insert(result.begin(),'1');
        }
        return result;
    }
};

int main()
{
    Solution solution;
    cout << solution.addBinary(string("11"),string("1")) << endl;
    cout << solution.addBinary(string("1010"),string("1011")) << endl;
    cout << solution.addBinary(string("100010"),string("11")) << endl;

    return 0;
}