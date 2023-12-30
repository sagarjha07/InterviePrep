// LEETCODE 621

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char c:tasks){
            freq[c-'A']+=1;
        }
        sort(freq.begin(),freq.end());
        int maxFreq=freq[25];
        int idleTime=(maxFreq-1)*n;
        for(int i=0;i<=24;i++){
            idleTime-=min(maxFreq-1,freq[i]);
        }
        return tasks.size() + max(0,idleTime);
    }
};