// LEETCODE 994
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int totalOranges=0;
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    totalOranges+=1;
                } else if(grid[i][j]==1){
                    totalOranges+=1;
                }
            }
        }
        int time=0;
        int rottenOranges=0;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty()){
            int k=q.size();
            rottenOranges+=k;
            if(rottenOranges == totalOranges) return time;
            time+=1;
            for(int i=0;i<k;i++){
                vector<int> f=q.front();
                q.pop();
                int x=f[0];
                int y=f[1];
                for(int j=0;j<4;j++){
                    if(x+dx[j]>=0 && x+dx[j]<n && y+dy[j]>=0 && y+dy[j]<m &&grid[x+dx[j]][y+dy[j]]==1){
                        grid[x+dx[j]][y+dy[j]]=2;
                        q.push({x+dx[j],y+dy[j]});
                    }
                }
            }
        }
        if(rottenOranges == totalOranges) return time;
        return -1;
    }
};