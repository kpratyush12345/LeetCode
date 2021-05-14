//1295. Find Numbers with Even Number of Digits
//https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

class Solution {
public:
    int countDigit(long long n){
    int count = 0;
    while (n != 0){
        n = n / 10;
        ++count;
    }
    return count;
}
    
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(countDigit(nums[i])%2==0) cnt++;
        }
        return cnt;
    }
};
