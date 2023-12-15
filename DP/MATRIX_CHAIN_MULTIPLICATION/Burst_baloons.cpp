// LEETCODE 312

/*
Reframing the question :-
We are given n balloons indexed from 0 to n-1.Each balloon carry's a number with it representedd by nums array . If we burst a balloon we need to multiply the number of that balloon with the neighbouring left and right ballons.

For example :-
nums => [2,3,4,5]
say we bursted the 2nd ballon i.e the balloon with number 3 
then we need to multiply the left and right neighbours i.e  2 * 3 * 4 which gives us 24 coins .
In the end we need to burst all the balloons wisely so that we can get maximum number of coins from them .

Edge case:- The balloons which after bursting creates an out of bound condition then we need to treat out of bound index as a virtual balloon with number 1 .
For example:-
In the above example if we burst the balloon with number 2 the left neighbour will go out of bound thus during calculations we will treat the out of bound index as a virtual balloon with number 1 i.e 1[Vritual balloon with out of bound index] * 2 * 3 .
So this completes the entire question .

1st Intuition:-

After understanding the entire question the first intuition that we may got is backtracking .But after seeing the constraints my eye balls popped out to floor. The reason behind this is that we have n balloons so the number of permutaions that will be in the worst case scenerio is O(n!) .
That's super high . Maybe it will work for constraints till 15 but the question maker has gifted us with a constraint like this 1 <= n <= 500 So in the end say goodbye to backtracking .
2nd Intuition:-

The sacrifice of backtrack should not go to vein. So after this we all thought of dp but not sure how to implement dp. After some huge brainstorming and taking hints from others I got an observation i.e That the ballons that were already bursted can be ignored for finding the maxcoins for the ballons that we will be bursting in future
This observation gives us a green signal for using DP's bottom up approach .
3rd Intuition:-

Now to think for time complexity, we have C(n,k) cases for k balloons and for each case it need to scan the k balloons to compare. Still it's too high but It's better than O(n!) but worse than O(2^n) or maybe O(3^n).
4th Intuition:-

One thing we all may have understood till now is that there seems to be many sub-similar problems from previous approaches. Somehow if we can cut down those time execution we may get an optimized approach .
5th Intuition:-
i ..........k-1....k...k+1.......... j
[- - - - - - - - - - - - - - - - - -]

Till now we are bursting a balloon let's say k'th balloon and we are getting the coins by multiplying the (k-1)th * k'th * (k+1)th balloons . As the balloon k is already burst, we solve the subproblems from i to k -1 and k + 1 to j. But wait, what's going wrong here? The subproblem solve(nums, i, k - 1) and solve(nums, k + 1, j) are not independent since after bursting kth balloon, balloon k - 1 and k + 1 have become adjacent and they will need each other in order to calculate the max profit of coins .
So in the end we are facing a new isusue in this problem. The issue is that as the left and right become adjacent they will effect the maxCoins in the future calculation . We don't want this thing to happen .
6th Intuition:-

The above issue will happen in every kth balloon but but there is one exception to this i.e if We choose the kth balloon as the last one to be burst then the subproblems will become independent since (k - 1)th balloon and (k + 1)th balloon won't need each other in order to calculate the answer. WHY? THINK MY FRIENDS!!!
7th Intuition:-

So to answer the 6th Intuition, if we think with a pen and paper we get that becuase only the first and last balloons are the balloons where we are sure of their adjacent balloons before hand! Because
For the first we have nums[k-1] * nums[k] * nums[k+1] and for the last we have nums[-1] * nums[k] * nums[n] .
OKkk. Now think about n balloons if j is the last one to burst, We can see that the balloons are again getting separated into 2 sections. But this time since the balloon j is the last balloon of all to burst, the left and right section now has well defined boundary and do not affect each other!
Thus now we can do either recursive with memoization or our favourite dp .
Final Intuition
Let's recap a bit:

Edge case: Pad the beginning + end of the array with a virtual 1, since the problem defines it this way, it won't affect the final value, and most importantly it eliminates the need to deal with these special cases
Realized that working backwards will allow us to cleanly divide the array into subproblems
Pop all the 0 balloons first and remove them from the array (since they are worth nothing)
Now there are 3 variables in our main equation: the values of the 3 balloons to pop. Again, we use the two 1's we just padded the array with to eliminate two of those variables off the bat
Now just try all the possible middle balloons to pop (the 3rd variable). For each balloon we choose, use it as the right and left ballon of the next level of recursion, along with the padded 1's, and so forth.
Base case is when there are no more balloons between the left and right balloon indexes (left+1 == right)
Time complexity will be O(N^3)
*/


class Solution {
public:
    int solve(int i,int j, vector<int>&arr,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MIN;
        for(int k=i;k<=j;k++){
            int temp = solve(i,k-1,arr,dp)+solve(k+1,j,arr,dp) + arr[i-1]*arr[k]*arr[j+1];
            ans=max(ans,temp);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,n-2,nums,dp);
    }
};

