//LEETCODE 19

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        if(n==0) return head;
        ListNode*ne=new ListNode(-1);
        ne->next=head;
        ListNode*f=head;
        ListNode*s=head;
        int k=n;
        while(k--){
            f=f->next;
        }
        ListNode* prev=ne;
        while(f!=NULL){
            prev=s;
            s=s->next;
            f=f->next;
        }
		prev->next = s->next;
		delete s;
		return ne->next;
    }
};