//57. Insert Interval
//https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back({newInterval[0],newInterval[1]});
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>res;
        for (int cur =0, next =0; cur < intervals.size(); cur = next) {
            next = cur + 1;
            int start = intervals[cur][0];
            int end = intervals[cur][1];
            while (next < intervals.size() && end >= intervals[next][0]) {
                end = max(end, intervals[next][1]);
                next++;
            } 
            res.push_back({start, end});
        }
        return res;
    }
};
