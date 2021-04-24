//703. Kth Largest Element in a Stream
//https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > pq;
    int kk=0;
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        for(int i=0;i<nums.size();++i){
        pq.push(nums[i]);
        if(pq.size()>kk)
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>kk) pq.pop();
    return pq.top();
    }
};
