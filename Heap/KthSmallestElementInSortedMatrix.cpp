class compare{
    public:
    bool operator()(vector<int>&a,vector<int>&b){
        return a[0]>b[0];
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        priority_queue<vector<int>,vector<vector<int>>,compare> pq;
        for(int i=0;i<n;i++){
            pq.push({matrix[i][0],i,0});
        }
        int count=0;
        while(!pq.empty()){
            vector<int> f=pq.top();
            pq.pop();
            count++;
            if(count==k) return f[0];
            int x = f[1];
            int y = f[2];
            if(y+1<matrix[x].size()){
                pq.push({matrix[x][y+1],x,y+1});
            }
        }
        return -1;
    }
};
