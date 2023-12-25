// LEETCODE 739

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        /*find next greater element index 
        difference from current index */
        int n=arr.size();
        stack<int> s;
        vector<int> ngr(n,0);
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                s.push(i);
                ngr[i]=i;
            }
            else if(!s.empty() && arr[s.top()]>arr[i]){
                ngr[i]=s.top();
                s.push(i);
            } else if(!s.empty() && arr[s.top()]<=arr[i]){
                while(!s.empty() && arr[s.top()]<=arr[i]){
                    s.pop();
                }
                if(s.empty()) ngr[i]=i;
                else ngr[i]=s.top();
                s.push(i);
            }
        }
        for(int i=0;i<n;i++){
            ngr[i]-=i;
        }
        return ngr;
    }
};