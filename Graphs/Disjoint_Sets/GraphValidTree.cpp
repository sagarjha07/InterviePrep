#include <bits/stdc++.h> 
class Disjoint{
    public:
        vector<int> parent;
        vector<int> rank;
        vector<int> size;

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

bool checkgraph(vector<vector<int>> edges, int n, int m)
{
    Disjoint d(n);
    for (vector<int>& e : edges) {
        int a = d.findParent(e[0]);
        int b = d.findParent(e[1]);
        if (a == b) return false;
        else d.unionBySize(e[0],e[1]);
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(d.parent[i]==i) count+=1;
    }
    return count==1;
}