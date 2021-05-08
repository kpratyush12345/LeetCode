//785. Is Graph Bipartite?
//https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int len = graph.size();
        vector<int> color(len+1,-1);
        for(int i=0;i<len;i++){
            if(color[i]==-1){
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    for(int ele : graph[curr]){
                        if(color[ele]==color[curr]) return false;
                        if(color[ele]==-1){
                            color[ele] = 1-color[curr];
                            q.push(ele);
                        }
                    }
                }
            }
        }
        return true;
    }
};
