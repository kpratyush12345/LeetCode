//3. Longest Substring Without Repeating Characters
//https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          int n = s.size();
    int res = 0; 
 
    for (int i = 0; i < n; i++) {

        vector<bool> visited(256);  
 
        for (int j = i; j < n; j++) {
 
            if (visited[s[j]] == true)
                break;
 
            else {
                res = max(res, j - i + 1);
                visited[s[j]] = true;
            }
        }
    }
    return res;
    }
};
