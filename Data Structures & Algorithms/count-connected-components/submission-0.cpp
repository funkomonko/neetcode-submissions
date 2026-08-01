class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        int res = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                dfs(adj, visited, i);
                res++;
            }
        }

        return res;
    }

    void dfs(vector<vector<int>> &adj, vector<bool> &visit, int node){
        visit[node] = true;
        for(int nei:adj[node]){
            if(!visit[nei]){
                dfs(adj, visit, nei);
            }
        }
    }
};