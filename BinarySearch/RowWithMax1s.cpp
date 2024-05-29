class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int maxRowIndex = -1;
        int j = m - 1; // Start from the top-right corner
        
        for (int i = 0; i < n; i++) {
            
            while (j >= 0 && arr[i][j] == 1) {
                j--; 
                maxRowIndex = i; // Update the row index with max 1s
            }
        }
        return maxRowIndex;
	}

}
