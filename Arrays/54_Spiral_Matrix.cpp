//54. Spiral Matrix
//https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> v;
    int i, k = 0, l = 0;
    while (k < m && l < n) {
        for (i = l; i < n; ++i) {
            v.push_back(matrix[k][i]);
        }
        k++;
 
        for (i = k; i < m; ++i) {
            v.push_back(matrix[i][n - 1]);
        }
        n--;
 
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                v.push_back(matrix[m - 1][i]);
            }
            m--;
        }
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                v.push_back(matrix[i][l]);
            }
            l++;
        }
    }
        return v;
    }
};
