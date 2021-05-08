//547. Number of Provinces
//https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    void BFS(vector<vector<int>>& isConnected,int j,vector<bool>& visited){
        queue<int> q;
        q.push(j);
        visited[j] = true;
        int v = isConnected.size();
        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(int i=0;i<v;i++){
                if(isConnected[f][i] == 1 && visited[i] == false){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }
        
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans =0;
        int v = isConnected.size();
        vector<bool> visited(v,false);
        for(int i = 0;i < v;i++){
            if(visited[i]==false){
                BFS(isConnected,i,visited);
                ans++;
            }
        }
        return ans;
    }
};
