class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

       vector<int>indg(n);

       for(auto edge : roads){
        indg[edge[0]]++;
        indg[edge[1]]++;
       } 

       sort(indg.begin(),indg.end());

       long long sum=0;
       long long val=1;

       for(auto i : indg){
        sum += i*val;
        val++;
       }

       return sum;
    }
};