// LEETCODE 2

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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1);
        ListNode*curr=ans;
        int carry=0;
        while (l1 != NULL || l2 != NULL) {
            int a = l1 != NULL ? l1->val : 0;
            int b = l2 != NULL ? l2->val : 0;
            int sum = a+b+carry;
            carry = sum/10;
            int val = sum%10;
            curr->next=new ListNode(val);
            curr=curr->next;
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
        }
        if(carry==1) curr->next=new ListNode(carry);
        return ans->next;
    }
};