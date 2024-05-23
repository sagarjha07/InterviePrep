void merge(int arr[], int l, int mid, int r){
        int i=l;  // initialise with i=l;
        int j=mid+1; // intitalise with j=mid+1
        int temp[r+l+1];
        int k=l; // initialisze with k=l same as i
        while(i<=mid &&j<=r){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            } else {
                temp[k++]=arr[j++];
            }
        }
        while(i<=mid){
            temp[k++]=arr[i++];
        } 
        while(j<=r){
            temp[k++]=arr[j++];
        }
        for(int s=l;s<=r;s++){
            arr[s]=temp[s];
        }
    }
void mergeSort(int arr[], int l, int r)
    {
        if(l>=r) return;
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
