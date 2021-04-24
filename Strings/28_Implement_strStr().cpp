//28. Implement strStr()
//https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        auto i1 = std::search(haystack.begin(),haystack.end(),needle.begin(),needle.end());
        if(i1 == haystack.end()) return -1;
        return i1-haystack.begin();
    }
};
