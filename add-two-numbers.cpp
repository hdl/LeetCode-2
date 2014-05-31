/*
Solution for LeetCode problem

Title: Add Two Numbers
URL: https://oj.leetcode.com/problems/add-two-numbers/
Version: 1.0

Created by Darcy Liu on 5/31/14.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode head(0);
        ListNode *p,*q;
        p = &head;
        int store = 0;
        while (l1!=NULL && l2!=NULL){
            if ((l1->val+l2->val+store)>9){
                q = new ListNode((l1->val+l2->val+store)%10);
                store = 1;
            } else {
                q = new ListNode((l1->val+l2->val+store)%10);
                store = 0;
            }
            p->next = q;
            p = q;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1!=NULL) {
            if ((l1->val+store)>9){
                q = new ListNode((l1->val+store)%10);
                store = 1;
            } else {
                q = new ListNode((l1->val+store)%10);
                store = 0;
            }
            p->next = q;
            p = q;
            l1 = l1->next;
        }
        
        while (l2!=NULL) {
            if ((l2->val+store)>9){
                q = new ListNode((l2->val+store)%10);
                store = 1;
            } else {
                q = new ListNode((l2->val+store)%10);
                store = 0;
            }
            p->next = q;
            p = q;
            l2 = l2->next;
        }
        
        if (store >0) {
            q = new ListNode(store);
            p->next = q;
            p = q;
        }
        
        p = head.next;
        head.next = NULL;
        return p;
    }
};

int main()
{
    Solution solution;
    
    ListNode a1(2),a2(4),a3(3);
    ListNode b1(5),b2(6),b3(4);
    ListNode c1(9),c2(1),c3(6);
    ListNode d1(0);
    a1.next = &a2;
    a2.next = &a3;
    
    b1.next = &b2;
    b2.next = &b3;
    
    c1.next = &c2;
    c2.next = &c3;
    
    ListNode *head = solution.addTwoNumbers(&a1,&b1);
    
    while(head!=NULL){
        cout << head->val;
        head = head->next;
        if (head!=NULL) {
            cout << " -> ";
        }else {
            cout << endl;
        }
    }
    head = solution.addTwoNumbers(&c1,&d1);
    while(head!=NULL){
        cout << head->val;
        head = head->next;
        if (head!=NULL) {
            cout << " -> ";
        }else {
            cout << endl;
        }
    }
    
    return 0;
}