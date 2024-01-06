// LEETCODE 54

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<int> ans;
        int fr=0;
        int lr=n-1;
        int fc=0;
        int lc=m-1;
        while(fr<=lr && fc<=lc){
            for(int i=fc;i<=lc;i++) ans.push_back(arr[fr][i]);
            fr++;
            for(int i=fr;i<=lr;i++) ans.push_back(arr[i][lc]);
            lc--;
            if(fr<=lr && fc<=lc){
                for(int i=lc;i>=fc;i--) ans.push_back(arr[lr][i]);
                    lr--;
                for(int i=lr;i>=fr;i--) ans.push_back(arr[i][fc]);
                    fc++;
            }
        }
        return ans;
    }
};