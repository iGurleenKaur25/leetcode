class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& pathVis,
             vector<int>& ans) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (int neighbour : adj[node]) {

            // Neighbour not visited
            if (!vis[neighbour]) {
                if (dfs(neighbour, adj, vis, pathVis, ans))
                    return true;
            }

            // Neighbour is in current DFS path
            else if (pathVis[neighbour]) {
                return true;
            }
        }

        // Leaving this node
        pathVis[node] = 0;

        // Store after all neighbours are processed
        ans.push_back(node);

        return false;
    }


    vector<int> findOrder(int numCourses,
                           vector<vector<int>>& prerequisites) {

        // Build graph
        vector<vector<int>> adj(numCourses);

        for (auto &p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];

            adj[prerequisite].push_back(course);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<int> ans;

        // Check every component
        for (int i = 0; i < numCourses; i++) {

            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis, ans)) {
                    return {};   // Cycle → impossible
                }
            }
        }

        // DFS gives reverse topological order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};