// LEETCODE 57
// case 1: a[0]---a[1] s---e // insert a[0]--a[1]
// case 2: s---e a[0]---a[1] // if interval not present, insert interval and push a[0]--a[1]
// case 3: all merging cases // change s and e expand interval after merging

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& v) {
        vector<vector<int>> ans;
        int s=v[0];
        int e=v[1];
        bool intervalNotPresent=true;
        for(vector<int>&a:arr){
            if(a[1]<s) ans.push_back(a);
            else if(a[0]>e){
                if(intervalNotPresent) {
                    ans.push_back({s,e});
                    intervalNotPresent=false;
                }
                ans.push_back(a);
            }else{
                s=min(a[0],s);
                e=max(a[1],e);
            }
        }
        if(intervalNotPresent) ans.push_back({s,e});
        return ans;
    }
};