//1395. Count Number of Teams
//https://leetcode.com/problems/count-number-of-teams/

class Solution {
public:
    Solution(){
        ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    }
    int numTeams(vector<int>& rating) {
        int res=0;
        for(int i=1;i<rating.size()-1;i++){
            int rightLess=0,rightGreat=0, leftLess=0, leftGreat=0;
            for(int j=0;j<i;j++){
                if(rating[j]<rating[i])leftLess++;
                else leftGreat++;
            }    
            for(int j=i+1;j<rating.size();j++){
                if(rating[j]>rating[i])rightGreat++;
                else rightLess++;
            }
            res=res+leftLess*rightGreat + leftGreat*rightLess;
        }
        return res;
    }
};
