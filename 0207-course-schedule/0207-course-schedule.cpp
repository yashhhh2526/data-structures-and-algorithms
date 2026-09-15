class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for(auto v : adj[node]){
            if(vis[v] == 1){
                return false;
            }

            if(vis[v] == 0){
                if(!dfs(v, adj, vis)){
                    return false;
                }
            }
        }

        vis[node] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto& p : prerequisites){
            adj[p[0]].push_back(p[1]);
        }

        vector<int> vis(numCourses, 0);

        for(int i = 0; i < numCourses; i++){
            if(vis[i] == 0){
                if(!dfs(i, adj, vis)){
                    return false;
                }
            }
        }

        return true;
    }
};