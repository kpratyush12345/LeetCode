//76. Minimum Window Substring
//https://leetcode.com/problems/minimum-window-substring/
//https://youtu.be/iwv1llyN6mo

class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char,int> mp;
     for(char i:t)
        mp[i]++;
 int i=0,j=0,start=0,len=INT_MAX,count=mp.size();
    while(j<s.size()){
        if(mp.find(s[j]) != mp.end()){
            mp[s[j]]--;
            if(mp[s[j]] == 0)
                count--;
           }  
   while(count==0){          
     if(mp.find(s[i]) != mp.end()){ 
          mp[s[i]]++;
         if(mp[s[i]] > 0)
           count++;       
           if(j-i+1 < len){
              start=i;
              len=j-start+1;
            }
      }
       i++;
  }
        j++;
 } 
        return (len==INT_MAX)?"":s.substr(start,len);
}
};
