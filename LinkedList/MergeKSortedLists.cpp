//LEETCODE 23

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

class comp {
public:
    bool operator()(ListNode*& a, ListNode*& b) { return a->val > b->val; }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if (arr.size() == 0)
            return NULL;
        ListNode* ans = new ListNode(-1);
        ListNode* curr = ans;
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != NULL)
                pq.push(arr[i]);
        }
        while (!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();
            ListNode* nextOfTemp = temp->next;
            curr->next = temp;
            curr = curr->next;
            if (nextOfTemp != NULL)
                pq.push(nextOfTemp);
        }
        return ans->next;
    }
};