// LEETCODE 127

class Solution {
public:
    int ladderLength(string b, string e, vector<string>& wordList) {
        int n=wordList.size();
        unordered_set<string> mp;
        for(string &s: wordList) {
            mp.insert(s);
        }
        queue<pair<string,int>> q;
        unordered_map<string,bool> visited;
        q.push({b,1});
        visited[b]=true;
        while(!q.empty()){
            pair<string,int> p=q.front();
            q.pop();
            string curr=p.first;
            int dist=p.second;
            if(curr==e) return dist;
            for(int i=0;i<curr.size();i++){
                char temp=curr[i];
                for(int j=0;j<26;j++){
                    curr[i]=j+'a';
                    if(mp.find(curr)!=mp.end() && !visited[curr]){
                        visited[curr]=true;
                        q.push({curr,dist+1});
                    }
                }
                curr[i]=temp;
            }

        }
        return 0;
    }
};