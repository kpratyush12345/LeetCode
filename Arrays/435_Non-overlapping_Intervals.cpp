//435. Non-overlapping Intervals
//https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        if (n == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
             {
                return a[1] < b[1]; 
             });
       
        int ret = 1;
        int end = intervals[0][1];
        for (int i = 1; i < n; ++i)
        {
            auto begin = intervals[i][0];
            if (begin >= end)
            {
                ret++;
                end = intervals[i][1];
            }
        }
        return n - ret;
    }
};
