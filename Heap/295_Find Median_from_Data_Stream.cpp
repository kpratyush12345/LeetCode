//295. Find Median from Data Stream
//https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
    priority_queue<int, vector<int>, greater<int>>minh; 
    priority_queue<int> maxh;                              
     

public:  void addNum(int input)
    {
        maxh.push(input);                                    
         minh.push(maxh.top());                               
        maxh.pop();

        if (maxh.size() < minh.size()) {                    
            maxh.push(minh.top());
            minh.pop();
        }
    }

    double findMedian()
    {
        if(maxh.size() > minh.size())
        return maxh.top();
        else return ((double) maxh.top() + minh.top()) * 0.5;
        
    
    }
};
