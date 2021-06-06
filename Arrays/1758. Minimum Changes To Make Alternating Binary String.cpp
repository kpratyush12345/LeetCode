//1758. Minimum Changes To Make Alternating Binary String
//https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/

class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        int len = s.length();
        for(int i=0;i<s.length();i++){
            if(!(i%2) && s[i]=='1') ans++;
            if((i%2) && s[i]=='0') ans++;
        }
        return min(ans,len-ans);
    }
};
