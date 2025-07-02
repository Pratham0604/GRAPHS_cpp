class Solution {

    vector<int>rank;
    vector<int>parent;

    // path compression
    int find(int i){

        if(i == parent[i]) return i;

        return parent[i]=find(parent[i]);
    }

    // rank compression

    void Union(int x, int y){

        int xParent = find(x);
        int yParent = find(y);

        if(xParent == yParent) return;

        if(rank[xParent] > rank[yParent]){
            parent[yParent] = xParent;
        }

        else if(rank[xParent] < rank[yParent]){
            parent[xParent] = yParent;
        }

        else{
            parent[xParent] = yParent;
            rank[yParent]++;
        }

    }
public:
    bool equationsPossible(vector<string>& equations) {
        
        rank.resize(26,0);
        parent.resize(26);

        for(int i=0;i<26;i++){
            parent[i]=i;
        }

        for(string &s : equations){

            if(s[1] == '='){
                Union(s[0]-'a',s[3]-'a');
            }
        }

        for(string &s : equations){

            if(s[1] == '!'){
                char first = s[0];
                char second = s[3];

                int par_first=find(first-'a');
                int par_second=find(second-'a');

                if(par_first == par_second) return false;
            }
        }
        return true;
    }
};