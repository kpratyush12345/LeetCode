//1155. Number of Dice Rolls With Target Sum
//https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
       int dp[1001][1001];
       memset(dp,0,sizeof(dp));
       
        for(int i=1;i<=f;i++){
            dp[0][i]=1;
        }
        
        int MOD = 1000000007;
        
        for(int i=1;i<d;i++){
            for(int s=1;s<=target;s++){
                int ans = 0;
                for(int k=s-1;k>=s-f && k>=0;k--){
                    ans = (ans + dp[i-1][k])%MOD;
                }
                dp[i][s]=ans;
            }
        }
        return dp[d-1][target];
    }
};
