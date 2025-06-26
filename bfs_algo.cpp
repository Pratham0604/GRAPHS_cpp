class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        
        int V = adj.size();
        
        vector<bool> visited(V,false);
        
        vector<int> ans;
        
        queue<int>que;
        
        visited[0]=true;
        
        que.push(0);
        
        while(!que.empty()){
            
            int node=que.front();
            que.pop();
            
            ans.push_back(node);
            
            for(auto& x : adj[node]){
                if(visited[x] == false){
                    visited[x]=true;
                    que.push(x);
                }
            }
        }
        
        return ans;
        
        
    }
};