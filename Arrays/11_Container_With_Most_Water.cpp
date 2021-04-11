//11. Container With Most Water
//https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
       if (height.size()<=1) return 0;
        
        int maxArea=0;
        int left=0;
        int right=height.size()-1;
        
        while(left<right){
            int curArea=min(height[left], height[right])*(right-left);
            maxArea=max(maxArea, curArea);
            if(height[left]<height[right])  left++;
            else  right--;
               
        }
        
        return maxArea;
    }
};
