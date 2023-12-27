// LEETCODE 567
// same as finding all anagrams index (Leetcode 438)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp;
        int k=s1.size();
        for(int i=0;i<k;i++) mp[s1[i]]+=1;
        int counter=mp.size();
        int j=0;
        int i=0;
        while(j<s2.size()){
            if(mp.find(s2[j])!=mp.end()){
                mp[s2[j]]-=1;
                if(mp[s2[j]]==0) counter--;
            }
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                if(counter==0) return true;
                if(mp.find(s2[i])!=mp.end()){
                    mp[s2[i]]+=1;
                    if(mp[s2[i]]==1) counter++;
                }
                i++;
                j++;
            }
        }
        return false;
    }
};