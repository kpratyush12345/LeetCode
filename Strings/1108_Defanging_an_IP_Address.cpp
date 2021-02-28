//1108. Defanging an IP Address
//https://leetcode.com/problems/defanging-an-ip-address/

class Solution {
public:
    string defangIPaddr(string address) {
        string s;
        for(int i=0;i<address.length();i++){
            if(address[i]=='.'){
                s.push_back('[');
                s.push_back('.');
                s.push_back(']');
            }
            else{
                s.push_back(address[i]);
            }
        }
        return s;
    }
};
