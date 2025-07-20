class Solution {

    long long dfs(int sr, int sc, vector<vector<int>>& grid, vector<vector<bool>>& vis,int dr[],int dc[]){

        vis[sr][sc]=1;
        long long ans = grid[sr][sc];

        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<4;i++){
            int nr = sr + dr[i];
            int nc = sc + dc[i];

            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]>0){
                ans += dfs(nr,nc,grid,vis,dr,dc);
            }
        }
        return ans;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,0));

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        long long sum=0;
        int count=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] >0){
                   sum = dfs(i,j,grid,vis,dr,dc);
                   if(sum % k == 0) count++;
                }
            }
        }
        return count;
    }
};