//1431. Kids With the Greatest Number of Candies
//https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> v;
        int mx = *max_element(candies.begin(),candies.end()); 
        for(int i=0;i<candies.size();i++){
            candies[i]+=extraCandies;
            if(candies[i]>=mx){
                v.push_back(true);
            } else {
                v.push_back(false);
            }
            candies[i]-=extraCandies;
        }
        return v;
    }
};
