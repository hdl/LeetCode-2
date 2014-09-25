/*
Solution for LeetCode problem

Title: Pascal's Triangle
URL: https://oj.leetcode.com/problems/pascals-triangle/
Version: 1.0

Created by Darcy Liu on 9/25/14.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > triangle;

        for (int i=0;i< numRows;i++){
            vector<int> line(i+1,1);
            for(int j=1;j<i;j++) {
                line[j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
            triangle.push_back(line);
        }

        return triangle;
    }
};

int main()
{
    Solution solution;

    vector<vector<int> > triangle = solution.generate(10);

    for (vector<vector<int> >::iterator it = triangle.begin(); it != triangle.end(); ++it) {
        vector<int> line = *it;
        for (vector<int>::iterator item = line.begin(); item != line.end(); ++item) {
            cout << *item << " ";
        }
        cout << endl;
    }
    return 0;
}