//42. Trapping Rain Water
//https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        stack <int> st;

    int ans = 0;
        int n=height.size();

    for(int i = 0; i < n; i++)
    {
        while ((!st.empty()) &&
               (height[st.top()] < height[i]))
        {
            int pop_height = height[st.top()];
            st.pop();

            if (st.empty())
                break;

            int distance = i - st.top() - 1;

            int min_height = min(height[st.top()],
                                 height[i]) -
                             pop_height;
 
            ans += distance * min_height;
        }
        st.push(i);
    }
    return ans;
}
    
};
