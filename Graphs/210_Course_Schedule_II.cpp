//210. Course Schedule II
//https://leetcode.com/problems/course-schedule-ii/

/*-------------------------------------------------Topological Sort-----------------------------------------------------------*/
class Solution {
    //Graph coloring: 0->not visited...1->visited...2->visited & processed
    bool detectCycle_util(vector<vector<int>>& adj,vector<int>& visited,int v)
    {
        if(visited[v]==1)
            return true;
        if(visited[v]==2)
            return false;
        
        visited[v]=1;   //Mark current as visited
        for(int i=0;i<adj[v].size();++i)
            if(detectCycle_util(adj,visited,adj[v][i]))
                return true;
        
        visited[v]=2;   //Mark current node as processed
        return false;
    }
    
    //Cycle detection
    bool detectCycle(vector<vector<int>>& adj,int n)
    {
        vector<int> visited(n,0);
        for(int i=0;i<n;++i)
            if(!visited[i])
                if(detectCycle_util(adj,visited,i))
                    return true;
        return false;
    }
    
    //Topological sort
    void dfs(vector<vector<int>>& adj,int v,vector<bool>& visited,stack<int>& mystack)
    {
        visited[v] = true;
        for(int i=0;i<adj[v].size();++i)
            if(!visited[adj[v][i]])
                dfs(adj,adj[v][i],visited,mystack);
        
        mystack.push(v);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        //Make adjacecncy list
        for(int i=0;i<n;++i)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        //Detect CYCLE...If present then return empty array
        vector<int> ans;
        if(detectCycle(adj,numCourses))
            return ans;        
        
        //Find toposort and store it in stack
        stack<int> mystack;
        vector<bool> visited(numCourses,false);
        
        //Apply DFS and find topological sort
        for(int i=0;i<numCourses;++i)
            if(!visited[i])
                dfs(adj,i,visited,mystack);
        
        while(!mystack.empty())
        {
            ans.push_back(mystack.top());
            mystack.pop();
        }
        return ans;
    }
};

/*------------------------------------------------Kahn's Algorithmn--------------------------------------------------------*/
class Solution{
    //Topological Sort
    bool kahnsAlgo(vector<vector<int>>& adj,int n,vector<int>& indegree ,vector<int>& ans){
        //Step 2- Take a queue and push all vertices with indegree=0;
        queue<int> q;
        for(int i=0;i<n;i++)
           if(indegree[i]==0)
              q.push(i);
        
        //Step 3- Process all nodes with indegree=0 and keep decrementing other node's indegree while processing
        int count=0; //Keep a count of no. of processed nodes(for cycle detection in graph)
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto a: adj[curr]){
                indegree[a]-=1;
                if(indegree[a]==0)
                   q.push(a);
            }

            ans.push_back(curr);//Push current node (forms topological ordering)
            count+=1; //Keeps count of no. of processed vertices
        }
        if(count!=n) //No. of processed nodes != No. of nodes
           return false; //Graph is not a DAG
        return true;
    }
	public:
	    vector<int> findOrder(int numCourses,vector<vector<int>>& prerequisites){
	    	int n = prerequisites.size();
            vector<vector<int>> adj(numCourses);
            vector<int> indegree(numCourses,0);//Stores indegree of each node

            //Make Adjacency List
            for(int i=0;i<n;i++){
                adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
                indegree[prerequisites[i][0]] += 1; //Step-1
            }

            //Kahn's Algorithm
            vector<int> ans;
            if(kahnAlgo(adj,numCourses,indegree,ans))
                return ans;
            
            vector<int> empty;
            return empty;
	    }
};
