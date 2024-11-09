class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        queue<int> q;
        int n = adj.size();
        vector<int> in(n, 0); 
        // 1. Calculate in-degrees for all vertices
        for (int u = 0; u < n; u++) {
            for (int v : adj[u]) {
                in[v]++;
            }
        }
        int cnt=0;
        // 2. Add vertices with in-degree 0 to the queue
        for (int i = 0; i < n; i++) {
            if (in[i] == 0){
                q.push(i);
                cnt++;
                
            }
        }

        // 3. Process vertices in topological order
        vector<int> ans;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);

            // Decrease in-degree for all neighbors of u
            for (int v : adj[u]) {
                in[v]--;
                // If in-degree becomes 0, add v to the queue
                if (in[v] == 0) {
                    q.push(v);
                    cnt++;
                }
            }
        }
        if(cnt==n) return false;
        
        return true;
    }
};
