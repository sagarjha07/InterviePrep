//LEETCODE 438

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mp;
        int k=p.size();
        for(int i=0;i<k;i++) mp[p[i]]+=1;
        int counter=mp.size();
        vector<int> ans;
        int j=0;
        int i=0;
        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]-=1;
                if(mp[s[j]]==0) counter--;
            }
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                if(counter==0) ans.push_back(i);
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]+=1;
                    if(mp[s[i]]==1) counter++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};