class Solution {
    
     void dfs(int sr, int sc, vector<vector<int>>& grid, vector<vector<int>>& status, int delrow[], int delcol[]){

        status[sr][sc]=1;

        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<4;i++){
            
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && status[nrow][ncol] != 1){

                dfs(nrow,ncol,grid,status,delrow,delcol);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>status(m,vector<int>(n,0));
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
      
      // boundary check..
      
      // check for boundary rows.
      
      for(int i=0;i<n;i++){
        
        if(grid[0][i] == 1 && status[0][i] == 0){
            
            dfs(0,i,grid,status,delrow,delcol);
        }
        
        if(grid[m-1][i] == 1 && status[m-1][i] == 0){
            
            dfs(m-1,i,grid,status,delrow,delcol);
        }
      }
      
      // check for boundary cols.
      
       for(int i=0;i<m;i++){
        
        if(grid[i][0] == 1 && status[i][0] == 0){
            
            dfs(i,0,grid,status,delrow,delcol);
        }
        
        if(grid[i][n-1] == 1 && status[i][n-1] == 0){
            
            dfs(i,n-1,grid,status,delrow,delcol);
        }
      } 
      
      // check for inner matrix.
      
      int count=0;
      
      for(int i=1;i<m-1;i++){
        for(int j=1;j<n-1;j++){
            
            if(grid[i][j] == 1 && status[i][j] == 0){
                
               count += grid[i][j];
            }
        }
      }
      
      return count;
    }
};