class Solution {

    void dfs(vector<vector<int>>& adjList,int src,vector<bool>& visited){

        visited[src]=1;

        for(auto& edge : adjList[src]){
            if(!visited[edge]){
                dfs(adjList,edge,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int V=isConnected.size();
        vector<int>ans;
        vector<vector<int>> adjList(V);    
        int count=0;

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){

                if(i != j && isConnected[i][j]==1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<bool>visited(V,0);

        for(int i=0;i<V;i++){
            if(visited[i] == false){
               count++;
               dfs(adjList,i,visited);
            }
        }

        return count;
    }
};