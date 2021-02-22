//414. Third Maximum Number
//https://leetcode.com/problems/third-maximum-number/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        auto it = s.end();
        if(s.size()<3){
            return *max_element(s.begin(),s.end());
        }
        for(int i=0;i<3;i++)
           it--;
        return *it;
    }
};
