/*
Solution for LeetCode problem

Title: Insert Interval
URL: https://oj.leetcode.com/problems/insert-interval/
Version: 1.0

Created by Darcy Liu on 8/6/14.
*/
#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> group;
        bool skip = false;

        for (vector<Interval>::iterator it = intervals.begin(); it < intervals.end(); it++) {
            if (it->end < newInterval.start || it->start > newInterval.end){
                if (it->start > newInterval.end && skip == false) {
                    skip = true;
                    group.push_back(newInterval);
                }
                group.push_back(*it);
            } else {
                if (it->start < newInterval.start) {
                     newInterval.start = it->start;
                }
                if (it->end > newInterval.end) {
                    newInterval.end = it->end;
                }
            }
        }

        if (skip == false) {
            group.push_back(newInterval);
        }
        
        return group;
    }
};

int main()
{
    Solution solution;
    Interval a1(1,2),a2(3,5),a3(6,7),a4(8,10),a5(12,16);
    Interval newInterval(4,9);

    vector<Interval> intervals;
    
    intervals.push_back(a1);
    intervals.push_back(a2);
    intervals.push_back(a3);
    intervals.push_back(a4);
    intervals.push_back(a5);

    vector<Interval> result = solution.insert(intervals,newInterval);

    for (vector<Interval>::iterator it=result.begin(); it<result.end(); it++) {
        cout << it->start << ' ' << it->end << endl;
    }
    return 0;
}