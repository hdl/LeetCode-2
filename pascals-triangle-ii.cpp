/*
Solution for LeetCode problem

Title: 
URL: 
Version: 1.0

Created by Darcy Liu on 8/2/14.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex ++;
        vector<int> tempLine(rowIndex,1);
        vector<int> rowLine(rowIndex,1);
        
        for (int i=1;i < rowIndex; i++) {
            for(int j=1;j<i;j++) {
                tempLine[j] =  rowLine[j-1] + rowLine[j]; 
            }
            rowLine = tempLine;
        }
        return rowLine;
    }
};

int main()
{
    Solution solution;
    vector<int> row = solution.getRow(1);
    for (vector<int>::iterator it = row.begin(); it != row.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}