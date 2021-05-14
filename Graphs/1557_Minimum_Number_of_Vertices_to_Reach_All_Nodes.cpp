//1557. Minimum Number of Vertices to Reach All Nodes
//https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {        
        vector<int> indegree(n);
        for(int i=0;i<edges.size();i++){
            indegree[edges[i][1]]++;
        }
        
        vector<int>v;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                v.push_back(i);
            }
        }
        return v;
    }
};
