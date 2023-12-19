// LEETCODE 242

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]+=1;
        }
        for(int i=0;i<t.size();i++){
            if(mp[t[i]]==1) mp.erase(t[i]);
            else mp[t[i]]-=1;
        }
        return mp.size()==0;
    }
};