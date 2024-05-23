class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
    	int first = -1;
        int second = -1;
        for(int i=0;i<n;i++) {
            int value=arr[i];
            if(value > first) {
                second = first;
                first = value;
    
            } else if(value > second && value != first) {
                second = value;
            }
        }
        return second;
	}
