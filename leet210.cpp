class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
       vector<vector<int>> adjList(numCourses);
       vector<int>indg(numCourses,0);
       queue<int>que;
       vector<int>ans;
       int count=0;

       for(auto& edge : prerequisites){
        adjList[edge[1]].push_back(edge[0]);
        indg[edge[0]]++;
       }

       for(int i=0;i<indg.size();i++){
         if(indg[i] == 0) que.push(i);
       }

       while(!que.empty()){

        int node=que.front();
        count++;
        ans.push_back(node);
        que.pop();

        for(auto& u :adjList[node]){
            if(--indg[u] == 0){
                que.push(u);
            }
        }

       }

       if(numCourses != count) return {};
       else return ans;
    }
};