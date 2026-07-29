class Solution {
public:
    vector<int> out;
    unordered_set<int> visiting;
    unordered_set<int> in;
    int flag = 1;

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites){
        unordered_map<int, vector<int>> adj;
        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
        }

        for(int i = 0; i<numCourses && flag; i++){
            dfs(i, adj);
        }

        return out;
    }

    void dfs(int i, unordered_map<int, vector<int>> &adj){
        if(visiting.count(i)){
            out.clear();
            flag = 0;
            return;
        }
        if(in.count(i)){
            return;
        }
        if(adj[i].empty() && !in.count(i)){
            out.push_back(i);
            in.insert(i);
            return;
        }
        visiting.insert(i);
        for(int j = 0; j<adj[i].size() && flag; j++){
            dfs(adj[i][j], adj);
        }
        if(!flag){
            return;
        }
        out.push_back(i);
        in.insert(i);
        visiting.clear();
        adj[i].clear();
        return;
    }
};
