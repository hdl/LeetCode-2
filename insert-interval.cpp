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
        vector<Interval>::iterator g,p,it;
        bool skip = false;
        if (intervals.size()>0) {
            for (it = intervals.begin(); it < intervals.end(); it++) {
                if (it->end < newInterval.start || it->start > newInterval.end){
                    if (it->start > newInterval.start && skip == false) {
                        skip = true;
                        g = group.end();
                        g = group.insert(g,newInterval);
                    }
                    g = group.end();
                    g = group.insert(g,*it);
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
                g = group.end();
                g = group.insert(g,newInterval);
            }
        } else {
            g = group.end();
            g = group.insert(g,newInterval);
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
    vector<Interval>::iterator it;

    it = intervals.begin();
    it = intervals.insert(it, a5 );
    it = intervals.insert(it, a4 );
    it = intervals.insert(it, a3 );
    it = intervals.insert(it, a2 );
    it = intervals.insert(it, a1 );

    vector<Interval> result = solution.insert(intervals,newInterval);

    for (it=result.begin(); it<result.end(); it++) {
        cout << it->start << ' ' << it->end << endl;
    }
    return 0;
}