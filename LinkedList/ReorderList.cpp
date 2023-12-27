//LEETCODE 143

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
    ListNode* reverse(ListNode*head){
        if(head==NULL || head->next==NULL) return head;
        ListNode*c=head;
        ListNode*n=NULL;
        ListNode*p=NULL;
        while(c!=NULL){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;
    }
    ListNode* middle(ListNode*head){
        if(head==NULL || head->next==NULL) return head;
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        ListNode*mid=middle(head);
        ListNode*t=mid->next;
        mid->next=NULL;
        ListNode*rev=reverse(t);
        ListNode*c=head;
        bool addFromLast=true;
        while(c!=NULL && rev!=NULL){
            ListNode*temp=NULL;
            if(addFromLast){
                temp=c->next;
                c->next=rev;
                c=temp;
            }else {
                temp=rev->next;
                rev->next=c;
                rev=temp;
            }
            addFromLast=!addFromLast;
        }
    }
};