//1859. Sorting the Sentence
//https://leetcode.com/problems/sorting-the-sentence/

class Solution {
public:
    string sortSentence(string s) {
        vector<pair<int,string>> v;
        int i=0;
        int j=0;
            for(j=0;j<s.length();j++){
                if(s[j]>='1' && s[j]<='9'){
                    string st = s;
                    string r = st.substr(i,j-i);
                    v.push_back(make_pair(s[j],r));
                    i=j+2;
                }
            }
        sort(v.begin(),v.end());
        string str;
        for(int i=0;i<v.size();i++){
            str += v[i].second;
            if(i!=v.size()-1) str += ' ';
        }
        return str;
    }
};
