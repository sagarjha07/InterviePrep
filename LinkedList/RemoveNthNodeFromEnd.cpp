//LEETCODE 19

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
