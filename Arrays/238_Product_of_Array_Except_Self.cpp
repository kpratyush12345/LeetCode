//238. Product of Array Except Self
//https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v;
        int p=1;
        for(int i=0;i<nums.size();i++){
            p*=nums[i];
        }
        int pp=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                for(int j=0;j<nums.size();j++){
                    if(i==j) continue;
                    pp*=nums[j];
                }
                v.push_back(pp);
            } else {
                v.push_back(p/nums[i]);
            }
        }
        return v;
    }
};
