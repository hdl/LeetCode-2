/*
Solution for LeetCode problem

Title: Remove Duplicates from Sorted List
URL: http://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *t = head,*p = head;

        if (head==NULL){

        }else{
            p = p->next;
            while(p!=NULL){
                if (p->val == t->val) {
                    t->next = p->next;
                }else{
                    t = p;
                }
                p = p->next;
            }
        }

        return head;
    }
    void print(ListNode *head){
        cout << "--------" << endl;
        while(head!=NULL){
            cout << head->val << endl;
            head = head->next;
        }
    }
};

int main()
{
    Solution solution;
    ListNode a1(1),a2(1),a3(2),*head;
    ListNode b1(1),b2(1),b3(2),b4(3),b5(3);
    ListNode c1(1);
    a1.next = &a2;
    a2.next = &a3;

    b1.next = &b2;
    b2.next = &b3;
    b3.next = &b4;
    b4.next = &b5;

    solution.print(solution.deleteDuplicates(&a1));
    solution.print(solution.deleteDuplicates(&b1));
    solution.print(solution.deleteDuplicates(&c1));
    return 0;
}
