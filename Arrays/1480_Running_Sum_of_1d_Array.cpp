//1480. Running Sum of 1d Array
//https://leetcode.com/problems/running-sum-of-1d-array/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> v;
        int ans = nums[0];
        v.push_back(ans);
        for(int i=1;i<nums.size();i++){
            ans+=nums[i];
            v.push_back(ans);
        }
        return v;
    }
};
