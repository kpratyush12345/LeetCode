//474. Ones and Zeroes
//https://leetcode.com/problems/ones-and-zeroes/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        int dp[sz+1][m+1][n+1]; //We start of by making a 3D DP
        memset(dp,0,sizeof(dp)); // Initializing every element by 0
        int ans = 0;
        for(int i=1;i<=sz;i++){
            int ones = count(strs[i-1].begin(),strs[i-1].end(),'1'); // Counting Number of ones
            int zeros = strs[i-1].size() - ones; //Counting Number of zeros
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    dp[i][j][k] = dp[i-1][j][k];
                    if(j >= zeros && k >= ones){ // When substring have more than or equal nos of zeroes and ones
                        dp[i][j][k] = max(dp[i][j][k] , 1 + dp[i-1][j-zeros][k-ones]);
                    }
                    ans = max(ans,dp[i][j][k]); //max in DP
                }
            }
        }
        return ans;
    }
};

/*Example 2 :
strs = ["10","0","1"], m = 1, n = 1

for i=1; ones = 1 and zeros = 1
    dp[1][0][0] = 0; dp[1][0][1] = 0; dp[1][1][0] = 0; dp[1][1][1] = 1;
for i=2; ones = 0 and zeros = 1
    dp[2][0][0] = 0; dp[2][0][1] = 0; dp[2][1][0] = 1; dp[2][1][1] = 1;
for i=3; ones = 1 and zeros = 0
    dp[3][0][0] = 0; dp[3][0][1] = 1; dp[3][1][0] = 1; dp[3][1][1] = 2;

Output: max in DP ---> 2*/
