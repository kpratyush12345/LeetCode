//78. Subsets
//https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        int subsetsize = (1<<size);
        vector<vector<int>> allSubset;
        for(int subsetMask = 0; subsetMask<subsetsize; subsetMask++){
            vector<int> subset;
            for(int i = 0; i<size ; i++){
                if(!(subsetMask&(1<<i))){
                    subset.push_back(nums[i]);
                }
            }
            allSubset.push_back(subset);
        }
        return allSubset;
    }
};
