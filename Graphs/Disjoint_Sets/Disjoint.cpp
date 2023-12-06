#include <bits/stdc++.h>
using namespace std;

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
