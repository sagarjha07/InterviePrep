// LEETCODE 23

class compare {
    public:
    bool operator()(ListNode*&a,ListNode*&b){
        return a->val>b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        for(int i=0;i<lists.size();i++) {
            if(lists[i]!=NULL) pq.push(lists[i]);
        }
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(!pq.empty()){
            ListNode* f= pq.top();
            pq.pop();
            if(head==NULL){
                head=f;
                tail=f;
            } else {
                tail->next=f;
                tail=tail->next;
            }
            if(f->next!=NULL){
                pq.push(f->next);
            }
        }
        return head;
    }
};
