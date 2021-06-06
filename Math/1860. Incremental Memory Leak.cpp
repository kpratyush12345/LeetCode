//1860. Incremental Memory Leak
//https://leetcode.com/problems/incremental-memory-leak/

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int i = 1;
        while(1){
            if(memory1>=memory2){
                if(memory1<i) break;
                memory1 -= i;
            }
            else{
                if(memory2<i) break;
                memory2 -= i;
            }
            i++;
        }
        vector<int> v = {i,memory1,memory2};
        return v;
    }
};
