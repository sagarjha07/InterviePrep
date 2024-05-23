
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low>=high) return;
        int p=partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int i=low;
       int pivot=arr[high];
       for(int j=low;j<high;j++){
           if(arr[j]<=pivot){
               swap(arr[i],arr[j]);
               i++;
           }
       }
       swap(arr[i],arr[high]);
        return i;
    }
};
