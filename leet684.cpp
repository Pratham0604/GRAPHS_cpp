class Solution {

    vector<int>rank;
    vector<int>parent;

     int find(int i){

        if(i == parent[i]) return i;

        return parent[i]=find(parent[i]);
    }

    void Union(int x,int y){

        int x_par=find(x);
       int y_par=find(y);

        if(x_par == y_par) return;

       if(rank[x_par] > rank[y_par]) parent[y_par]=x_par;

       if(rank[y_par] > rank[x_par]) parent[x_par]=y_par;

       if(rank[x_par] == rank[y_par]){
        parent[x_par]=y_par;
        rank[y_par]++;
       }

    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        parent.resize(n+1,0);
        rank.resize(n+1);

        for(int i=1;i<=n;i++){
            parent[i]=i;
            rank[i]=0;
        }
        vector<int>ans(2);

        for(auto& edge : edges){

           if(find(edge[0]) == find(edge[1])) {
            ans[0]=edge[0];
            ans[1]=edge[1];
            break;
           }
           Union(edge[0],edge[1]);
        }

        return ans;
    }
};