class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

       vector<vector<int>> adjList(n);
       vector<int>indg(n,0);
       int cnt=0;

       for(auto edge : edges){

          adjList[edge[0]].push_back(edge[1]);
          indg[edge[1]]++;
       }
       
       int node;
       for(int i=0;i<indg.size();i++){
        if(indg[i] == 0){
            node=i;
            cnt++;
        }
       }

       if(cnt >= 2) return -1;
       else return node;
    }
};