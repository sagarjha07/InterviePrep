// LEETCODE 1584
// find all edges {w,u,v} based on pairs and apply ksruskal algo

class Disjoint{
    private:
        vector<int> parent;
        vector<int> rank;
        vector<int> size;

    public:
        Disjoint(int n) {
            parent.resize(n+1);
            rank.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }
        
    //Find parent of a node with path compression
        int findParent(int node) {
            if(node == parent[node]) return node;
            return parent[node] = findParent(parent[node]);
        }

    //Union by size
    void unionBySize(int u,int v) {
        int a = findParent(u);
        int b = findParent(v);
        if(a == b) return;
        if(size[a]<size[b]) {
            parent[a] = b;
            size[b]+=size[a];
        } else{
            parent[b] = a;
            size[a]+=size[b];
        }
    }

    //Union by rank
    void unionByRank(int u,int v) {
        int a =findParent(u);
        int b = findParent(v);
        if(a == b) return;
        if(rank[a]<rank[b]){
            parent[a]=b;
        } else if(rank[a]>rank[b]){
            parent[b]=a;
        } else {
            parent[a]=b;
            rank[b]++;
        }
    }
};

class Edge{
    public:
        int u;
        int v;
        int w;

        bool operator<(const Edge& other) {
            return w < other.w; // sort by weight
        }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& arr) {
        vector<Edge> edges;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                vector<int> p1=arr[i];
                vector<int> p2=arr[j];
                int w= abs(p1[0]-p2[0])+abs(p1[1]-p2[1]);
                Edge e;
                e.u=i;
                e.v=j;
                e.w=w;
                edges.push_back(e);
            }
        }
        sort(edges.begin(),edges.end());
        int n=edges.size();
        Disjoint d(n);
        int ans=0;
        for(auto e:edges){
            int a=d.findParent(e.u);
            int b=d.findParent(e.v);
            if(a!=b){
                ans+=e.w;
                d.unionBySize(e.u,e.v);
            }
        }
        return ans;
    }
};