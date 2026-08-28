class Solution {
public:

bool dfs(int node, int destination,
         vector<vector<int>>& adj,
         vector<int>& vis) {

    if(node == destination)
        return true;

    vis[node] = 1;

    for(int neighbour : adj[node]) {

        if(!vis[neighbour]) {

            if(dfs(neighbour, destination, adj, vis))
                return true;
        }
    }

    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
         vector<vector<int>> adj(n);

    for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n, 0);

    return dfs(source, destination, adj, vis);
    }
};