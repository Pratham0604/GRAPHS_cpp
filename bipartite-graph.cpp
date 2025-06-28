class Solution {

    bool dfs(int node, int col, vector<vector<int>>& graph, vector<int>& color){

        color[node]=col;

        for(auto neighbour : graph[node]){
            if(color[neighbour] == -1){
                if(dfs(neighbour,1-col,graph,color) == false) return false;
            }
            else if(color[neighbour] == col) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int V = graph.size();
        vector<int>color(V,-1);

        for(int i=0;i<V;i++){

            if(color[i] == -1){

                if(dfs(i,0,graph,color) == false){
                    return false;
                }
            }
        }
         return true;
    }
};