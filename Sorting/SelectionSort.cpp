void selectionSort(int arr[], int n)
    {
        // For every index i, 
        // find min_idx in remaining array
        // swap current arr[i] value arr[min_idx]
       for(int i=0;i<n-1;i++){
           int mn_idx=i;
           for(int j=i+1;j<n;j++){
               if(arr[j]<arr[mn_idx]){
                   mn_idx=j;
               }
           }
            swap(arr[mn_idx],arr[i]);
       }
    }