// LEETCODE 85 Maximal Rectangle

class Solution {
public:
    int findMaxAreaInHistogram(vector<int>&arr){
        int n=arr.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                right[i]=n;
            } else if(!s.empty() && arr[s.top()]<arr[i]){
                right[i]=s.top();
            }
            else if(!s.empty() && arr[s.top()]>=arr[i]){
                while(!s.empty() && arr[s.top()]>=arr[i]){
                    s.pop();
                }
                if(s.empty()) right[i]=n;
                else right[i]=s.top();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=0;i<n;i++){
            if(s.empty()){
                left[i]=-1;
            } else if(!s.empty() && arr[s.top()]<arr[i]){
                left[i]=s.top();
            }
            else if(!s.empty() && arr[s.top()]>=arr[i]){
                while(!s.empty() && arr[s.top()]>=arr[i]){
                    s.pop();
                }
                if(s.empty()) left[i]=-1;
                else left[i]=s.top();
            }
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(right[i]-left[i]-1)*arr[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<int> v(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]=='1') v[j]+=1;
                else v[j]=0;
            }
            ans=max(ans,findMaxAreaInHistogram(v));
        }
        return ans;
    }
};