// LEETCODE 1046

class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
        int n = arr.size();
        priority_queue<int> pq;
        for (int i : arr)
            pq.push(i);
        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            pq.push(y - x);
        }
        return pq.top();
    }
};