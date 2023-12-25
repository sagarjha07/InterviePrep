// LEETCODE 84

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
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
};