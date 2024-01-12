class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int>> v;
	    for(int i=0;i<nums.size();i++){
	        v.push_back({nums[i],i});
	    }
	    
	    sort(v.begin(),v.end());
	    
	    vector<bool> visited(nums.size(),false);
	    int ans=0;
	    
	    for(int i=0;i<nums.size();i++){
	        if(v[i].second==i) continue; // Already at right index
	        if(visited[i]) continue;
	        int j=i;
	        int cycle_size=0;
	        while(!visited[j]){
	            visited[j]=true;
	            j=v[j].second;
	            cycle_size+=1;
	        }
	        if(cycle_size>0) ans+=cycle_size-1;
	    }
	    return ans;
	}
};