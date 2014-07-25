/*
Solution for LeetCode problem

Title: Merge Intervals
URL: https://oj.leetcode.com/problems/merge-intervals/
Version: 1.0

Created by Darcy Liu on 7/25/14.
*/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compare(const Interval t1,const Interval t2){  
    return t1.start < t2.start;  
}

class Solution {
public:

    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> group;
        vector<Interval>::iterator g,p,it;
        
        sort(intervals.begin(),intervals.end(),compare);

        if (intervals.size()>0) {
            p = intervals.begin();
            it = intervals.begin();
            for (it++; it < intervals.end(); it++) {
                if (it->start <= p->end){
                    if (it->start < p->start) {
                        p->start = it->start;
                    }
                    if (it->end > p->end) {
                        p->end = it->end;
                    }
                } else {
                    g = group.end();
                    g = group.insert(g,*p);
                    p = it;
                }
            }
            g = group.end();
            g = group.insert(g,*p);
        }
        
        return group;
    }
};

int main()
{
    Solution solution;

    Interval a1(1,3),a2(2,6),a3(8,10),a4(15,18);

    vector<Interval> intervals;
    vector<Interval>::iterator it;

    it = intervals.begin();
    it = intervals.insert(it, a4 );
    it = intervals.insert(it, a3 );
    it = intervals.insert(it, a2 );
    it = intervals.insert(it, a1 );

    vector<Interval> result = solution.merge(intervals);

    for (it=result.begin(); it<result.end(); it++) {
        cout << it->start << ' ' << it->end << endl;
    }
    return 0;
}