//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int timer;
    vector<int> tin, low;
    vector<bool> visited;
    vector<vector<int>> adj;
    bool found;

    void dfs(int node, int parent, int c, int d) {
        visited[node] = true;
        tin[node] = low[node] = timer++;
        for (int neigh : adj[node]) {
            if (neigh == parent) continue;
            if (!visited[neigh]) {
                dfs(neigh, node, c, d);
                low[node] = min(low[node], low[neigh]);
                
                // Check if the edge is a bridge
                if (low[neigh] > tin[node]) {
                    if ((node == c && neigh == d) || (node == d && neigh == c)) {
                        found = true;
                    }
                }
            } else {
                low[node] = min(low[node], tin[neigh]);
            }
        }
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Build adjacency list
        adj.assign(V, vector<int>());
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        timer = 0;
        tin.assign(V, -1);
        low.assign(V, -1);
        visited.assign(V, false);
        found = false;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, -1, c, d);
            }
        }

        return found;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends