class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites){
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> adj(numCourses);
        for(auto i:prerequisites){
            indegree[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }

        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int finish = 0;
        vector<int> output(numCourses);
        while(!q.empty()){
            int node = q.front(); q.pop();
            output[numCourses - finish - 1] = node;
            finish++;
            for(int nei : adj[node]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }

        if(finish != numCourses){
            return {};
        }
        return output;
    }

};
