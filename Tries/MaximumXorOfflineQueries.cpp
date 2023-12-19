// LEETCODE 1707
//Maximum xor with an element from array (Online Queries)
//Sort nums array
//Sort queries array based on mi
//Convert whole problem as offline queries

class Node{
public:
    Node*links[2];
    bool containsKey(int i){
        return links[i]!=NULL;
    }
    void put(int i,Node*node){
        links[i]=node;
    }
    Node*get(int i){
        return links[i];
    }
};
class Trie{
    private:Node*root;
    public:
        Trie(){
            root=new Node();
        }
        void insert(int n){
            Node*node=root;
            for(int i=31;i>=0;i--){
                int bit=(n>>i)&1;
                if(!node->containsKey(bit)){
                    node->put(bit,new Node());
                }
                node=node->get(bit);
            }
        }
        int findMaxXor(int n){
            Node*node=root;
            int ans=0;
            for(int i=31;i>=0;i--){
                int bit=(n>>i)&1;
                if(node->containsKey(!bit)){
                    ans=ans | (1<<i);
                    node=node->get(!bit);
                } else {
                    node=node->get(bit);
                }
            }
            return ans;
        }
        
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(),0);
        vector<vector<int>> q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i][1],queries[i][0],i});
        }
        //sort queries based on mi
        sort(q.begin(),q.end());
        //sort nums array
        sort(nums.begin(),nums.end());
        Trie t;
        int j=0;
        // O(N+Q)
        //complete offline queries
        for(int i=0;i<q.size();i++){
            int a= q[i][0];
            int x=q[i][1];
            int ind=q[i][2];
            while(j<nums.size() && nums[j]<=a){
                t.insert(nums[j]);
                j++;
            }
            if(j==0) ans[ind]=-1;
            else ans[ind]=t.findMaxXor(x);
        }
        return ans;
    }
};