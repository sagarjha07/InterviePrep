// LEETCODE 853

// A beautiful question deals with finding the time 
        
        // we have to store the time in increasing order of requirement 
        
        // first of all {sort the vector<pp> of position & speed}
        
        // Lets take a testcase [{1 , 6 } , {3 , 4} , {4, 11} , {6,7} , {7,4} , {9 ,9} , {10 , 2}] , target = 14
        
        // Now we have to calculate no of fleets 
        
        // see we have to start from behind , & have to find the time required by each car
        
        
        // Important thing is -> Point of catch up of one car to its ahead moving car
        // can be any decimal values needs not to be integeral point 
        
        // Lets find out the time required for each car
        
        //  time = [(14-1)/6 , (14-3)/4 , (14-4)/11 , (14-6)/7 , (14-7)/4 , (14-9)/9 , (14-10)/2]
        
        // [2.1 , 2.8 , 0.9 , 1.1 , 1.75 , 0.56 , 2]
         // C1     C2   C3    C4     C5     C6    C7
        // These are time taken by each cars to reach target
        
        // So C7 take 2 second , meanwhile (  C6 , C5 , C4 , C3  all will C7 before target 
        // as time required by them is smaller . stack [2]
        
        // Now C2 time is 2.8 so push into stack [2 , 2.8]
        
        // Now C1 has time less than C2 , it will meet C2 before target.
        

class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n=pos.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({pos[i],speed[i]});
        }
        sort(v.begin(),v.end());
        stack<double> s;
        for(int i=n-1;i>=0;i--){
            double time = (target-v[i].first)/((double) v[i].second); 
            if(s.empty() || s.top()<time) s.push(time);
        }
        return s.size();
    }
};