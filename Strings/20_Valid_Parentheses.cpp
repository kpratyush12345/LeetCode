//20. Valid Parentheses
//https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
    stack<char> st;
    char x;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '(' || s[i] == '['
            || s[i] == '{'){
            st.push(s[i]);
            continue;
        }
        if (st.empty())
            return false;
 
        switch (s[i]){
        case ')':
            x = st.top();
            st.pop();
            if (x == '{' || x == '[')
                return false;
            break;
 
        case '}':
            x = st.top();
            st.pop();
            if (x == '(' || x == '[')
                return false;
            break;
 
        case ']':
            x = st.top();
            st.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }
    if (st.empty()) return true;
        else return false;
    }
};
