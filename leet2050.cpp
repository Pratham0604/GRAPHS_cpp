class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<int>indg(n,0);
        queue<int>que;

        // creating the adjacency list..

        vector<vector<int>>adjList(n);
        vector<int>waitingTime(n,0);

        for(auto edge : relations){

          adjList[edge[0]-1].push_back(edge[1]-1);
          indg[edge[1]-1]++;

        }

        for(int i=0;i<n;i++){
            if(indg[i]==0) {
                que.push(i);
                waitingTime[i]=time[i];
            }
        }

        while(!que.empty()){

            int node = que.front();
            que.pop();

            for(auto neighbour : adjList[node]){

                waitingTime[neighbour] = max(waitingTime[neighbour], waitingTime[node]+time[neighbour]);
                
                indg[neighbour]--;
                if(indg[neighbour] == 0) que.push(neighbour);
            }

        }

        return *max_element(waitingTime.begin(),waitingTime.end());

    }
};