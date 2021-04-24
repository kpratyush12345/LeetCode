//474. Ones and Zeroes
//https://leetcode.com/problems/ones-and-zeroes/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        int dp[sz+1][m+1][n+1];
        memset(dp,0,sizeof(dp));
        int ans =0;
        for(int i=1;i<=sz;i++){
            int ones = count(strs[i-1].begin(),strs[i-1].end(),'1');
            int zeroes = strs[i-1].length() - ones;
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    dp[i][j][k]=dp[i-1][j][k];
                    if(j>=zeroes && k>=ones){
                        dp[i][j][k] = max(dp[i][j][k],1 + dp[i-1][j-zeroes][k-ones]);
                    }
                    ans = max(ans,dp[i][j][k]);
                }
            }
        }
        return ans;
    }
};
