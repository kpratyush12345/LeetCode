//90. Subsets II
//https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int size = nums.size();
        int subsetsize = (1<<size);
        set<vector<int>> allSubset;
        for(int subsetMask = 0; subsetMask<subsetsize; subsetMask++){
            vector<int> subset;
            for(int i = 0; i<size ; i++){
                if(!(subsetMask&(1<<i))){
                    subset.push_back(nums[i]);
                }
            }
            sort(subset.begin(),subset.end());
            allSubset.insert(subset);
        }
        vector<vector<int>> v(allSubset.size());
        copy(allSubset.begin(), allSubset.end(), v.begin());
        return v;
    }
};
