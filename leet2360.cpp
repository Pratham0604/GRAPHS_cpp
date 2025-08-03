class Solution {
    int res=-1;

    void dfs(int u,vector<int>& edges,vector<bool>& visit,vector<int>& count,vector<bool>& recstk){
       
       if(u != -1){

          visit[u]=1;
          recstk[u]=1;

          int v=edges[u];

          if(v!=-1 && !visit[v]){
            count[v]=count[u]+1;
            dfs(v,edges,visit,count,recstk);
          }
          else if(v!=-1 && recstk[v]==1){             //there is a cycle
            res=max(res,count[u]-count[v]+1);
          }      

          recstk[u]=0;
       }
    }
public:
    int longestCycle(vector<int>& edges) {
        
        int n=edges.size();

        vector<bool>visit(n,0);
        vector<int>count(n,1);
        vector<bool>recstk(n,0);

        for(int i=0;i<n;i++){
            if(!visit[i]){
                dfs(i,edges,visit,count,recstk);
            }
        }
        return res;
    }
};