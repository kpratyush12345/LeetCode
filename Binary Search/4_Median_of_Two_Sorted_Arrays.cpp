//4. Median of Two Sorted Arrays
//https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        if(nums1.size()%2==0){
            int x = nums1[nums1.size()/2];
            int y = nums1[(nums1.size()/2)-1];
            return (double)(x+y)/2;
        }
        else{
            int r = nums1[nums1.size()/2];
            return (double)r;
        }
    }
};
