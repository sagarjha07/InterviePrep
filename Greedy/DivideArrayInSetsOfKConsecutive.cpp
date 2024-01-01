// LEETCODE 1296

class Solution {
public:
    bool isPossibleDivide(vector<int>& arr, int k) {
        int n = arr.size();
        if(n%k!=0) return false;
        map<int,int> mp;
        int numOFGroups=n/k;
        for(int i=0;i<arr.size();i++) mp[arr[i]]+=1;
        for(int i=0;i<numOFGroups;i++){
            int temp = (*mp.begin()).first;
            for(int j=temp;j<temp+k;j++){
                if(mp.find(j)==mp.end()) return false;
                mp[j]-=1;
                if(mp[j]==0) mp.erase(j);
            }
        }
        return true;
    }
};