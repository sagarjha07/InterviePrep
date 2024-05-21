// LEETCODE 1358
// Given a string s consisting only of characters a, b and c.
//Return the number of substrings containing at least one occurrence of all these characters a, b and c.

class Solution {
public:
    int solve(string s,int k){
        int n=s.size();
        int i=0;
        int j=0;
        int ans=0;
        unordered_map<char,int> mp;
        while(j<n){
            mp[s[j]]+=1;
            if(mp.size()<=k){
                j++;
            } else {
                while(mp.size()>k){
                    if(mp[s[i]]==1) mp.erase(s[i]);
                    else mp[s[i]]-=1;
                    i++;
                }
                j++;
            }
          //add number of substring/subarrays here
            ans+=(j-i);
        }
        return ans;
    }
    int numberOfSubstrings(string s) {
        return solve(s,3)-solve(s,2);
    }
};
