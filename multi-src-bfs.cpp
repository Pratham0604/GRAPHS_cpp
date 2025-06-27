class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

      int m=grid.size();        int n=grid[0].size();
       vector<vector<int>> visited(m,vector<int>(n,0));

      // que  {{row,col},time}
      queue<pair<pair<int,int>,int>> que;

      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 2){
                visited[i][j]=2;
                que.push({{i,j},0});
            }
          
        }
      }  

      int delrow[] = {-1,0,1,0};
      int delcol[] = {0,1,0,-1};

      int time=0;

      while(!que.empty()){

        int row = que.front().first.first;
        int col = que.front().first.second;
        int t = que.front().second;
        que.pop();

        time = max(time,t);

            for(int i=0;i<4;i++){

            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && visited[nrow][ncol] != 2){
                       que.push({{nrow,ncol},t+1});
                       visited[nrow][ncol]=2;
                 }
            }
      }

      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j] == 0 && grid[i][j] == 1)
            return -1;
        }
      }

      return time;
    }
};