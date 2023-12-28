// LEETCODE 25

//RECURSION
class Solution {
public:
    bool notcontains(ListNode*head,int k){
        int ans=0;
        while(head!=NULL){
            ans+=1;
            head=head->next;
        }
        return ans<k;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || notcontains(head,k)) return head;
        ListNode* c=head;
        ListNode* p=NULL;
        ListNode* n=NULL;
        int x=k;
        while(c!=NULL && x>0){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
            x--;
        }
        head->next=reverseKGroup(n,k);
        return p;
    }
};

//ITERATION
class Solution {
public:
    void reverse(ListNode*&s,ListNode*e){
        ListNode*p=NULL;
        ListNode*c=s;
        while(p!=e){
            ListNode*n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==1) return head;
        ListNode*dummy=new ListNode(-1);
        ListNode*e=head;
        ListNode*beforeStart=dummy;
        beforeStart->next=head;
        int i=0;
        while(e!=NULL){
            i++;
            if(i%k==0){
                ListNode*s=beforeStart->next;
                ListNode*temp=e->next;
                reverse(s,e);
                beforeStart->next=e;
                s->next=temp;
                beforeStart=s;
                e=temp;
            } else e=e->next;
        }
        return dummy->next;
    }
};