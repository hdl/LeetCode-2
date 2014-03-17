/*
Solution for LeetCode problem

Title: Sqrt(x)
URL: http://oj.leetcode.com/problems/sqrtx/
Version: 1.0

Created by Darcy Liu on 3/17/14.
*/
#include <iostream>

using namespace std;

class Solution {
public:
	int sqrt(int x) {
		long long a=0,b = x/2+1,s,c=0;
		while(a<=b){
			c = (a+b)/2;
			s = c*c;
			if( s == x){
				return c;
			}
			if(s<x){
				a = c+1;
			}else{
				b = c-1;
			}
		}
		return (a+b)/2;;
	} 
};

int main()
{
    Solution solution;
	cout<< solution.sqrt(2147395599) <<endl;
	cout<< solution.sqrt(1) <<endl;
	cout<< solution.sqrt(2) <<endl;
	cout<< solution.sqrt(4) <<endl;
	cout<< solution.sqrt(9) <<endl;
	cout<< solution.sqrt(16) <<endl;
	cout<< solution.sqrt(32) <<endl;
	cout<< solution.sqrt(64) <<endl;
	cout<< solution.sqrt(81) <<endl;
	cout<< solution.sqrt(100) <<endl;
    return 0;
}