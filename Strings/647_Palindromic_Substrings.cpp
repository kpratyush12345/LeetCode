//647. Palindromic Substrings
//https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        bool table[n][n];
        int count=0;
    memset(table, 0, sizeof(table));
    int maxLength = 1;
 
    for (int i = 0; i < n; ++i){
        table[i][i] = true;
        count++;
    }
 
    int start = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            table[i][i + 1] = true;
            count++;
            start = i;
            maxLength = 2;
        }
    }
    for (int k = 3; k <= n; ++k) {
        for (int i = 0; i < n - k + 1; ++i) {
            int j = i + k - 1;
 
            if (table[i + 1][j - 1] && s[i] == s[j]) {
                table[i][j] = true;
                count++;
 
                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    return count;
    }
};
