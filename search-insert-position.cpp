/*
Solution for LeetCode problem

Title: Search Insert Position
URL: http://oj.leetcode.com/problems/search-insert-position/
Version: 1.0

Created by Darcy Liu on 3/26/14.
*/
#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int x = 0,y = n,t;
        while(x<y){
            t = (x + y)/2;
            if (A[t]==target){
                return t;
            }
            if (A[t]<target){
                x = t+1 ;
            }else{
                y = t;
            }
        }
        return (x+y)/2;
    }
};

int main()
{
    Solution solution;
    //[1,3,5,6], 5 ¡ú 2
    //[1,3,5,6], 2 ¡ú 1
    //[1,3,5,6], 7 ¡ú 4
    //[1,3,5,6], 0 ¡ú 0
    //[1,3], 2 ¡ú 1
    int a[4] = {1,3,5,6};
    int b[2] = {1,3};
    cout << "[1,3,5,6], 5 ¡ú 2 :" <<solution.searchInsert(a,4,5) << endl;
    cout << "[1,3,5,6], 2 ¡ú 1:" << solution.searchInsert(a,4,2) << endl;
    cout << "[1,3,5,6], 7 ¡ú 4:" << solution.searchInsert(a,4,7) << endl;
    cout << "[1,3,5,6], 0 ¡ú 0:" << solution.searchInsert(a,4,0) << endl;
    cout << "[1,3], 2 ¡ú 1:" << solution.searchInsert(b,2,2) << endl;
    return 0;
}
