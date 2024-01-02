// LEETCODE 133

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*,Node*> mp;
        mp[node]=new Node(node->val);
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node*f=q.front();
            q.pop();
            for(auto nbr:f->neighbors){
                if(mp.find(nbr)==mp.end()){
                    mp[nbr]=new Node(nbr->val);
                    q.push(nbr);
                }
                mp[f]->neighbors.push_back(mp[nbr]);
            }
        }
        return mp[node];
    }
};