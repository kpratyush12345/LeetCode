//496. Next Greater Element I
//https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        stack<int> s;
        for (int i = nums2.size()-1; i >= 0; i--){
            if(s.size()==0)
               v.push_back(-1);
            else if(s.size()>0&& s.top()>nums2[i])
               v.push_back(s.top());
            else if(s.size()>0 && s.top()<=nums2[i]){
                while(s.size()>0 && s.top()<=nums2[i]){
                s.pop();
                }
                if(s.size()==0)
                  v.push_back(-1);
                else 
                  v.push_back(s.top());
            }
            s.push(nums2[i]);
        }
       reverse(v.begin(),v.end());
        vector<int> vec;
       for(int i=0;i<nums1.size();i++){
           for(int j=0;j<nums2.size();j++){
               if(nums1[i]==nums2[j]) vec.push_back(v[j]);
           }
       }
        return vec;
    }
};
