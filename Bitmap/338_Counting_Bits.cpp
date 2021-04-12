//338. Counting Bits
//https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>v;
        vector<int> nums;
        for(int i=0;i<=num;i++) nums.push_back(i);
        for(int i=0;i<=num;i++){
            int count=0;
            while(nums[i]>0){
            count+=(nums[i]&1);
            nums[i] = nums[i]>>1;
        }
            v.push_back(count);
        }
        return v;
    }
};
