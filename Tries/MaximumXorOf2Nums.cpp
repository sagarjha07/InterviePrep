// LEETCODE 421
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
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(int i=0;i<nums.size();i++){
            t.insert(nums[i]);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,t.findMaxXor(nums[i]));
        }
        return ans;
    }
};
