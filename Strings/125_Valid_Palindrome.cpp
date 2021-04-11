//125. Valid Palindrome
//https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        string st,str;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isalpha(s[i])||isdigit(s[i])){
                st.push_back(tolower(s[i]));
            }
        }
        for(int i=0;i<st.size();i++){
            str.push_back(st[i]);
        }
        reverse(str.begin(),str.end());
        if(str==st) return true;
        else 
            return false;
    }
};
