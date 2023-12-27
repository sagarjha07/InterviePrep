//LEETCODE 76

class Solution {
public:
    string minWindow(string s, string p) {
        unordered_map<char, int> mp;
        int k = p.size();
        for (int i = 0; i < k; i++)
            mp[p[i]] += 1;
        int counter = mp.size();
        int j = 0;
        int i = 0;
        int start = -1;
        int mn = INT_MAX;
        while (j < s.size()) {
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]] -= 1;
                if (mp[s[j]] == 0)
                    counter--;
            }
            if (counter > 0)
                j++;
            else if (counter == 0) {
                while (counter == 0) {
                    if (j - i + 1< mn) {
                        mn = j - i + 1;
                        start = i;
                    }
                    if (mp.find(s[i]) != mp.end()) {
                        mp[s[i]] += 1;
                        if (mp[s[i]] == 1)
                            counter++;
                    }
                    i++;
                }
                j++;
            }
        }
        if (start == -1)
            return "";
        return s.substr(start, mn);
    }
};