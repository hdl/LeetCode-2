/*
Solution for LeetCode problem

Title: N-Queens II
URL: https://oj.leetcode.com/problems/n-queens-ii/
Version: 1.0

Created by Darcy Liu on 9/21/14.
*/
#include <iostream>
using namespace std;

class Solution {
public:
	int total;
	int a[100];
	int is_in_the_same_line(int x1,int y1,int x2,int y2) {
		return (x1 == x2 || y1 == y2 || abs(x1-x2) == abs(y1-y2));
	}
	int is_valid(int x,int y,int a[],int n) {
		int r = 0;
		for (int i=1;i < n; i++) {
			r = r || is_in_the_same_line(x,y,i,a[i]);
			if (r){
				break;
			}
		}
		return !r;
	}
	void n_queen(int row,int n){
		if (row>n) {
			total ++;
			return;
		}
		for (int y=1;y<=n;y++) {
			int r = is_valid(row,y,a,row);
			if (r) {
				a[row] = y;
				n_queen(row+1,n);
				a[row] = 0;
			}else{
				
			}
		}
	}
    int totalNQueens(int n) {
		total = 0;
		n_queen(1,n);
		return total;
    }
};

int main()
{
    Solution solution;
	for (int i = 1;i < 10; i ++){
		cout << "n" << i << " = " << solution.totalNQueens(i) << endl;
	}
    return 0;
}