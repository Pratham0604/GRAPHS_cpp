class Solution {

    void dfs(int src, vector<vector<int>>& rooms, vector<bool>& visited){

        visited[src]=true;

        for(auto &neighbour : rooms[src]){
            if(!visited[neighbour]){
                dfs(neighbour,rooms,visited);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int V = rooms.size();
        vector<bool>visited(V,0);

        dfs(0,rooms,visited);

        for(auto x : visited){
            if(!x) return false;
        }

        return true;
    }
};