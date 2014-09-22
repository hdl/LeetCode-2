/*
Solution for LeetCode problem

Title: N-Queens
URL: https://oj.leetcode.com/problems/n-queens/
Version: 1.0

Created by Darcy Liu on 9/22/14.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int total;
	int a[100];
	vector<vector<string> > ans;
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
			vector<string> t;
			for(int i=1;i<=n;i++) {
				string str;
				for (int j=1;j<=n;j++) {
					if(j == a[i]) {
						str += "Q";
					}else{
						str += ".";
					}
				}
				t.push_back(str);
			}
			ans.push_back(t);
			return;
		}
		for (int y=1;y<=n;y++) {
			int r = is_valid(row,y,a,row);
			if (r) {
				a[row] = y;
				n_queen(row+1,n);
				a[row] = 0;//magic
			}else{
				
			}
		}
	}
    int totalNQueens(int n) {
		total = 0;
		memset(a,0,sizeof(a));
		n_queen(1,n);
		return total;
    }
    vector<vector<string> > solveNQueens(int n) {
		memset(a,0,sizeof(a));
		n_queen(1,n);
		return ans;
    }
};

int main()
{
    Solution solution;
	vector<vector<string> > ans;
	ans = solution.solveNQueens(4);
	for (vector<vector<string> >::iterator it = ans.begin() ; it != ans.end(); ++it) {
		vector<string> solution = *it;
		for (vector<string>::iterator line = solution.begin() ; line != solution.end(); ++line) {
			cout << *line << endl;
		}
		cout << endl;
	}
    return 0;
}