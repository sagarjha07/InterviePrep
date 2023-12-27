// LEETCODE 21

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//RECURSION
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* c=NULL;
        if(l1->val<=l2->val){
            c=l1;
            c->next=mergeTwoLists(l1->next,l2);
        } else {
            c=l2;
            c->next=mergeTwoLists(l1,l2->next);
        }
        return c;
    }
};


//ITERATION
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* c=NULL;
        if(l1->val<=l2->val){
            c=l1;
            l1=l1->next;
        } else {
            c=l2;
            l2=l2->next;
        }
        ListNode* ans=c;
        while(l1 && l2){
            if(l1->val<=l2->val){
                c->next=l1;
                l1=l1->next;
            } else {
                c->next=l2;
                l2=l2->next;
            }
            c=c->next;
        }
        if(l1==NULL) c->next=l2;
        else c->next=l1;
        return ans;
    }
};