class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<int> indegree(V,0);
        vector<vector<int>> adjList(V);
        vector<int> ans;
        
        for(auto& edge : edges){
            int src=edge[0];
            int dest=edge[1];
            indegree[dest]++;
            adjList[src].push_back(dest);
        }
        
        queue<int>que;
        
        for(int i=0;i<V;i++){
            if(indegree[i] == 0) que.push(i);
        }
        
        while(!que.empty()){
            
            int node=que.front();
            ans.push_back(node);
            que.pop();
            
            for(auto it : adjList[node]){
                indegree[it]--;
                if(indegree[it] == 0) que.push(it);
            }
        }
        
        return ans;
    }
};