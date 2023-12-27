/*
Given a string you need to print the size of the longest possible substring 
that has exactly K unique characters. 
If there is no possible substring then print -1.
*/


class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char,int> mp;
        int i=0;
        int j=0;
        int ans=-1;
        while(j<s.size()){
            mp[s[j]]+=1;
            if(mp.size()<k){
                j++;
            } 
            else if(mp.size()==k){
                ans=max(ans,j-i+1);
                j++;
            }
            else {
                while(mp.size()>k){
                    if(mp[s[i]]==1) mp.erase(s[i]);
                    else mp[s[i]]-=1;
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};