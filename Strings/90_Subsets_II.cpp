//90. Subsets II
//https://leetcode.com/problems/subsets-ii/
//https://youtu.be/RIn3gOkbhQE

class Solution {
public:
    vector<vector<int>>ans;
    
    void ok(int x, vector<int>& nums , vector<int>curr){
        ans.push_back(curr);
        for(int i=x;i<nums.size();i++){
            if(i!=x && nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            ok(i+1,nums,curr);
            curr.pop_back();
        }
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>curr;
        sort(nums.begin(),nums.end());
        ok(0,nums,curr);
        return ans;

    }
};
