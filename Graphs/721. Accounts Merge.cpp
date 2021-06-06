//721. Accounts Merge
//https://leetcode.com/problems/accounts-merge/

class Solution {
public:
void bfs(unordered_map<string,unordered_set<string>> & graph, unordered_set<string> & visited, string s, vector<string> & ans)
{
    queue<string> q;
    q.push(s);
    visited.insert(s);
    while(!q.empty())
    {
        string t = q.front(); q.pop();
        ans.push_back(t);
        for(string str : graph[t])
        {
            if(visited.find(str)==visited.end())
            {
                q.push(str);
                visited.insert(str);
            }
        }
    }
}
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
vector<vector<string>> result;
    unordered_map<string,unordered_set<string>> graph;
    for(auto & ls : accounts)
    {
        for(int i=1;i<ls.size();i++)
        {                                                         //Adjacency list.
            graph[ls[i]].insert(ls[1]);
            graph[ls[1]].insert(ls[i]);
        }
    }
    
    unordered_set<string> visited;
    for(auto & ls : accounts)
    {
        if(visited.find(ls[1])==visited.end())
        {
            vector<string> ans;
            bfs(graph,visited,ls[1],ans);
            sort(ans.begin(),ans.end());
            ans.insert(ans.begin(),ls[0]);
            result.push_back(ans);
        }
    }
    
    return result; 
}
};
