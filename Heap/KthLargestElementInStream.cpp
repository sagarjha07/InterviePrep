// LEETCODE 703

class KthLargest {
private: priority_queue<int,vector<int>,greater<int>> pq;
        int sz;
public:
    KthLargest(int k, vector<int>& nums) {
        sz=k;
        for(int i:nums){
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>sz) pq.pop();
        return pq.top();
    }
};