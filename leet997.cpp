class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int>indg(n+1);
        vector<int>outdg(n+1);

       // if(trust.size()==0 && n==1) return 1;

        /*for(auto& edge : trust){
             
          adj[edge[0]].push_back(edge[1]);
          indg[edge[1]]++;
          outdg[edge[0]]++;
        }*/

        for(int i=0;i<trust.size();i++){
            outdg[trust[i][0]]++;
            indg[trust[i][1]]++;
        }

        for(int i=1;i<=n;i++){
            if(indg[i] == n-1 && outdg[i]==0) return i;
        }

        return -1;
    }
};