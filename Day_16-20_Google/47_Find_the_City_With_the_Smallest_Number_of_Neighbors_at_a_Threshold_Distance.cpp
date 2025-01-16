//Leetcode Submission link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/submissions/1510241846/

class Solution {
    int dijkstra(int src, int n, vector<vector<pair<int, int>>>& adj, int thr){
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while(!pq.empty()){
            int node = pq.top().second;
            int nodeDist = pq.top().first;
            pq.pop();

            for(auto adjEle : adj[node]){
                int adjNode = adjEle.first;
                int edgeWeight = adjEle.second;
                if(dist[adjNode] > edgeWeight + nodeDist){
                    dist[adjNode] = edgeWeight + nodeDist;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        vector<int> valid;
        for(int i = 0; i < n; i++){
            if(dist[i] <= thr){
                valid.push_back(i);
            }
        }

        return valid.size()-1;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int city = -1;
        int connections = n;
        for(int i = 0; i < n; i++){
            int size = dijkstra(i, n, adj, distanceThreshold);
            cout<<size<<" ";
            if(connections >= size){
                city = i;
                connections = size;
            }
        }

        return city;
    }
};

//Time complexity: (V×(V+E)logV)
//Space complexity: O(V+E) + O(V) + O(V) = O(V+E)