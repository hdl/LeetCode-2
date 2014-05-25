/*
Solution for LeetCode problem

Title: Merge Two Sorted Lists 
URL: https://oj.leetcode.com/problems/merge-two-sorted-lists/
Version: 1.0

Created by Darcy Liu on 3/17/14.
*/
#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head,*t;
        if (l1==NULL) {
            return l2;
        }
        if (l2==NULL) {
            return l1;
        }
        head = l1;
        if (l1->val > l2->val) {
            head = l2;
            l2 = l1;
            l1 = head;
        }
        
        while (l1->next!=NULL && l2!=NULL) {
            if (l1->next->val < l2->val) {
                l1 = l1->next;
            } else {
                t = l1->next;
                l1->next = l2;
                l2 = l2->next;
                l1->next->next = t;
            }
        }
        
        if (l1->next==NULL) {
            l1->next = l2;
        }
        
        return head;
    }
    
    void print(ListNode *head) {
        while(head!=NULL){
            cout<< head->val <<endl;
            head = head->next;
        }
    }
};

int main()
{
    Solution solution;
    ListNode a1(1),a2(3),a3(5);
    ListNode b1(2),b2(4),b3(6);
    
    //a1.next = &a2;
    //a2.next = &a3;
    
    //b1.next = &b2;
    //b2.next = &b3;
    
    solution.print(solution.mergeTwoLists(&b1,&a1));
    return 0;
}