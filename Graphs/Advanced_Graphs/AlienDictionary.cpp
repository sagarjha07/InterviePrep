
class Solution{
    public:
    void dfs(char node, unordered_map<char,vector<char>> &adj,unordered_map<char,bool> &visited,string&ans){
        visited[node]=true;
        for(auto nbr:adj[node]){
            if(!visited[nbr]){
                dfs(nbr,adj,visited,ans);
            }
        }
        ans+=node;
    }
    string findOrder(string dict[], int n, int k) {
        //code here
        unordered_map<char,vector<char>> adj;
        for(int i=0;i<n-1;i++){
            string a=dict[i];
            string b=dict[i+1];
            for(int j=0;j<min(a.size(),b.size());j++){
                if(a[j]!=b[j]){
                    adj[a[j]].push_back(b[j]);
                    break;
                }
            }
        }
        unordered_map<char,bool> visited;
        string ans="";
        for(int i=0;i<k;i++){
            char ch = i+'a';
            if(!visited[ch]) {
                dfs(ch,adj,visited,ans);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};