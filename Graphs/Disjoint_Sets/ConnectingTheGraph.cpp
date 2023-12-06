// GFG  Connecting the Graph
/* You are given a graph with n vertices and m edges.
You can remove one edge from anywhere and add that edge between any two vertices in one operation.
Find the minimum number of operations that will be required to make the graph connected.
If it is not possible to make the graph connected, return -1. */

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        //count extra edges while creating graph using DSU
        //if both nodes parents are already same it means i.e. an extra edge
        // if num of components -1 <= extra edges answer is possible otheriwse not
       Disjoint d(n);
       int extraEdges=0;
       for(vector<int> e:edge){
           int a=d.findParent(e[0]);
           int b=d.findParent(e[1]);
           if(a!=b) {
               d.unionBySize(e[0],e[1]);
           } else {
               //edge is already presnt , add this edge in num of extra edges
               extraEdges+=1;
           }
       }
       int numOfComponents =0;
       vector<int> p =d.getParent();
       for(int i=0;i<n;i++){
           if(p[i]==i) numOfComponents+=1;
       }
       if(extraEdges<numOfComponents-1) return -1;
       return numOfComponents-1;
    }
};