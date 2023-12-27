//LEETCODE 239

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> l; // store index of possible max in a window
        int j=0;
        int i=0;
        vector<int> ans;
        while(j<nums.size()){
            //do calculations
            while(l.size()>0 && nums[l.back()]<nums[j]){
                l.pop_back();
            }
            l.push_back(j);
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                //push front elememt of list in ans
                ans.push_back(nums[l.front()]);
                if(l.front()==i) l.pop_front(); // slide window
                i++;
                j++;
            }
        }
        return ans;
    }
};