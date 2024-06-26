// DO SWAP AND NON-SWAP CALL FOR EVERY INDEX

class Solution
{
    public:
    void solve(string str, string &ans, int k, int index){
        
        //base case
        if(index == str.size() || k == 0){
            ans = max(ans, str);
            return;
        }
        
        //No swap call
        solve(str, ans, k, index+1);
        
        //Now swaping rest of the element with curr only if they are greater than curr element
        for(int i = index + 1; i < str.size(); i++){
            if(str[index] < str[i]){
                swap(str[index], str[i]);
                solve(str, ans, k-1, index+1);
                swap(str[index], str[i]);
            }
        }
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        string ans = "";
        
        solve(str, ans, k, 0);
        
        return ans;
    }
}
}
