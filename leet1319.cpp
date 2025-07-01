class Solution {

    void dfs(int src, vector<vector<int>>& adj, vector<bool>& vis){

        vis[src]=1;

        for(auto neighbour : adj[src]){
            if(!vis[neighbour]){
                dfs(neighbour,adj,vis);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int edges=connections.size();
        
        if(edges < n-1) return -1;

        vector<bool>vis(n,0);
        
        vector<vector<int>> adj(n);

        for(auto edge : connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int components=0;
        for(int i=0;i<n;i++){

            if(!vis[i]){
            components++;
            dfs(i,adj,vis);
            }
        }

        return components-1;
    }
};