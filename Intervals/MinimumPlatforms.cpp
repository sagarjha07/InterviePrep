// MINIMUM PLATFORMS GFG

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int ans=1;
    	int i=1;
    	int j=0;
    	int platform_required=1;
    	while(i<n && j<n){
    	    if(arr[i]<=dep[j]){
    	        i++;
    	        platform_required+=1;
    	    } else{
    	        j++;
    	        platform_required-=1;
    	    }
    	    ans=max(ans,platform_required);
    	}
    	return ans;
    }
};