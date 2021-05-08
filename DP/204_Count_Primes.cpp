//204. Count Primes
//https://leetcode.com/problems/count-primes/

class Solution {
public:
    int countPrimes(int n) {
        
        bool dp[n+1];
      
        memset(dp,true,sizeof(dp));
       
        for(int i=2;(i*i)<=n;i++){
          if(dp[i]==true){
            
              for(int j=i*i;j<=n;j+=i)
                  dp[j]=false;
              
          }
          }
        int count=0;
             for(int i=2;i<n;i++){
                 if(dp[i]) count++;
             }
            return count;
            
    }
};
