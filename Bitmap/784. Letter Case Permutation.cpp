//784. Letter Case Permutation
//https://leetcode.com/problems/letter-case-permutation/

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int size = s.length();
        int subsetsize = (1<<size);
        set<string> allSubset;
        for(int subsetMask = 0; subsetMask<subsetsize; subsetMask++){
            string subset = s;
            for(int i = 0; i<size ; i++){
                if(!(subsetMask&(1<<i)) && !isdigit(subset[i])){
                    if(islower(subset[i])) subset[i] = toupper(subset[i]);
                    else subset[i] = tolower(subset[i]);
                }
            }
            allSubset.insert(subset);
        }
        vector<string> v(allSubset.size());
        copy(allSubset.begin(), allSubset.end(), v.begin());
        
        return v;
    }
};
