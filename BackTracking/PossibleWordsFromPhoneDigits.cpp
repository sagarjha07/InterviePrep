class Solution
{
    public:
    vector<string> dict = {"","","abc","def","ghi","jkl","mno",
                            "pqrs","tuv","wxyz"};
    //Function to find list of all words possible by pressing given numbers.
    void solve(int*a,int i,int n,string temp,vector<string> &ans){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        string s=dict[a[i]];
        for(int j=0;j<s.size();j++){
            solve(a,i+1,n,temp+s[j],ans);
        }
    }
    
    vector<string> possibleWords(int a[], int n)
    {
        vector<string> ans;
        string temp="";
        solve(a,0,n,temp,ans);
        return ans;
    }
}