class Solution {

    int dfs(int sr, int sc, vector<vector<int>>& grid, vector<vector<bool>>& vis, int dr[], int dc[]){

        vis[sr][sc]=1;
        int m = grid.size();
        int n = grid[0].size();

        int fish = grid[sr][sc];

        for(int i=0;i<4;i++){
          int nr = sr + dr[i];
          int nc = sc + dc[i];

          if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0 && !vis[nr][nc]){
                fish += dfs(nr,nc,grid,vis,dr,dc);
          }
        }
        return fish;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        
        int maxVal=0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,0));

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        int val=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] > 0 && !vis[i][j]){
                   val=dfs(i,j,grid,vis,dr,dc);
                   maxVal=max(val,maxVal);
                }
            }
        }

        return maxVal;

    }
};