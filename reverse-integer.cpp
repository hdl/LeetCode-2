/*
Solution for LeetCode problem

Title: Reverse Integer
URL: http://oj.leetcode.com/problems/reverse-integer/
Version: 1.1

Created by Darcy Liu on 3/15/14.
*/
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int reverse(int x){
        int bottle[32] = {0};
        int length = 0, r , i, s = 0;
        int t = x;
        if(t<0) {
            t = - x;
        }
        while(t>0){
            r = t % 10;
            t = t/10;
            bottle[length] = r;
            length ++;
        }
        for(i=0;i<length;i++){
            r = bottle[i]*pow(10,length-i-1);
            s +=r;
            /*cout<<length<<"|"<<bottle[i]<<"|"<<i<<"|"<<r<<endl;*/
        }

        if(x<0){
            s = -s;
        }

        return s;
    }
};

int main()
{
    Solution solution;
    int i;
    int test_data[4] = {100,123,321,-123};
    for(i=0;i<4;i++){
        cout<< test_data[i] <<" -> " << solution.reverse(test_data[i])<<endl;
    }
    return 0;
}
