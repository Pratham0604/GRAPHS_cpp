class Solution {

    void dfs(int u, vector<vector<int>>& adjlist, vector<bool>& visited){

        visited[u]=1;

        for(int& v : adjlist[u]){
           if(!visited[v]){
            dfs(v,adjlist,visited);
           }
        }
    }

    bool isSimilar(string& x,string& y){
        int diff=0;
        int n=x.size();

        for(int i=0;i<n;i++){
            if(x[i] != y[i]) diff++;
        }

        return diff==2 || diff==0;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        
        int V = strs.size();
        vector<vector<int>>adjlist(V);
        vector<bool>visited(V,0);

        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){

                if(isSimilar(strs[i],strs[j])){
                   adjlist[i].push_back(j);
                   adjlist[j].push_back(i);
                }

            }
        }
        int count=0;

        for(int i=0;i<V;i++){
            if(!visited[i]){
                count++;
                dfs(i,adjlist,visited);
            }
        }

        return count;        

    }
};