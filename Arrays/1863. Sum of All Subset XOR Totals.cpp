//1863. Sum of All Subset XOR Totals
//https://leetcode.com/problems/sum-of-all-subset-xor-totals/

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int count = pow(2, nums.size());
        int xr = 0;
        int sum =0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < nums.size(); j++) {
            if ((i & (1 << j)) != 0)
                xr^=nums[j];
        }
        sum+=xr;
        xr=0;
    }
        return sum;
    }
};
