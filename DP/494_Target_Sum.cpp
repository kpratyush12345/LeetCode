//494. Target Sum
//https://leetcode.com/problems/target-sum/

#define ll long long int
class Solution {
public:
    int findTargetSumWays(vector<int>& a, int target) {
        ll i,j,sum=0,n=a.size();
        for(i=0;i<n;i++){
            sum+=a[i];
        }
        if(target>sum)
            return 0;
        
        sum = (sum+target);
        if(sum%2!=0)
            return 0;
        
        ll k = (sum)/2;
        ll dp[n+1][k+1];
        memset(dp, 0, sizeof(dp));
        for(i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(i=1;i<=n;i++){
            for(j=0;j<=k;j++){
                if(a[i-1]<=j){
                    dp[i][j]=dp[i-1][j] + dp[i-1][j-a[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][k];
    }
};
