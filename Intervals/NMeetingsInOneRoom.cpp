// N Meetings in one room GFG
class solution{
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<vector<int>> arr;
        for(int i=0;i<n;i++) arr.push_back({start[i],end[i]});
       sort(arr.begin(),arr.end());
        int last=arr[0][1];
        int count=0;
        for(int i=1;i<n;i++){
            if(arr[i][0]>last){
                last=arr[i][1];
            } else{
                count+=1;
                last=min(last,arr[i][1]);
            }
        }
        return n-count;
    }
};