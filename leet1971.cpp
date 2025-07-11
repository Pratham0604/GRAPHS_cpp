class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

      if(n == 1) return true;

      vector<vector<int>> adjList(n);
      queue<int>que;
      vector<int>visited(n,0);

      for(auto edge : edges){

        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
      }

      que.push(source);
      visited[source]=1;

      while(!que.empty()){
          
          int node=que.front();
          que.pop();

          for(auto edge : adjList[node]){

              if(visited[edge] == 0){
                visited[edge]=1;
                que.push(edge);
              }

              if(edge == destination){
                return true;
              }
          }
           
      }
      return false;

    }
};