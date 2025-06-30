class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

       vector<vector<int>> adjList(numCourses);
       vector<int>indg(numCourses,0);
       vector<int>visited(numCourses,0);
       queue<int>que;
       int count=0;

       for(auto edge : prerequisites){
           // int src=edge[1];
           // int dest=edge[0];
           adjList[edge[1]].push_back(edge[0]);
           indg[edge[0]]++;
       }

       for(int i=0;i<indg.size();i++){
           if(indg[i] == 0) que.push(i);
       }

       while(!que.empty()){

        int node=que.front(); 
        count++;
        que.pop();

        for(auto edge : adjList[node]){
           // indg[edge]--;
            if(--indg[edge] == 0) que.push(edge);
        }
       }

       return numCourses==count;
    }
};