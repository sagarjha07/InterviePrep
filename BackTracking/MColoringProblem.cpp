class Solution{
public:
    bool canPlace(bool graph[][101],int currentNode,int n,int colorOfNode,
                    vector<int>&colors){
        for(int node=0;node<n;node++){
            if(graph[node][currentNode] && colors[node]==colorOfNode){
                return false;
            }
        }
        return true;
    }
    bool solve(bool graph[][101],int i,int m,int n,vector<int>&colors){
        if(i>=n) return true;
        for(int color=0;color<m;color++){
            if(canPlace(graph,i,n,color,colors)){
                colors[i]=color;
                bool ans = solve(graph,i+1,m,n,colors);
                if(ans) return true;
                colors[i]=-1;
            }
        }
        return false;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> colors(n,-1);
        return solve(graph,0,m,n,colors);
    }
};