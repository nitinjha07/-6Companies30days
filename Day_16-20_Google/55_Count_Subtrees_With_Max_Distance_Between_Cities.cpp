//Leetcode submission link: https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/submissions/1513617274/

class Solution {
    pair<int, int> bfs(unordered_set<int>& subtree, int start, unordered_map<int, vector<int>>& adj){
        vector<int> dist(adj.size()+1, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;

        int farNode = start, maxDist = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto adjNode : adj[node]){
                if(dist[adjNode] == -1 && subtree.count(adjNode)){
                    dist[adjNode] = dist[node] + 1;
                    q.push(adjNode);
                    if(maxDist < dist[adjNode]){
                        maxDist = dist[adjNode];
                        farNode = adjNode;
                    }
                }
            }
        }

        return {farNode, maxDist};
    }

    int calculateDiameter(unordered_set<int>& subtree, unordered_map<int, vector<int>>& adj){
        auto [oneEnd, dist] = bfs(subtree, *subtree.begin(), adj);
        auto [secEnd, diameter] = bfs(subtree, oneEnd, adj);

        return diameter;
    }
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> result(n-1, 0);

        for(int i = 0; i < (1<<n); i++){
            unordered_set<int> subtree;
            for(int j = 0; j < n; j++){
                if((i & (1<<j)) != 0){
                    subtree.insert(j+1);
                }
            }

            //check whether they are forming a graph
            int edgeCount = 0;
            for(auto e : edges){
                if(subtree.count(e[0]) && subtree.count(e[1])) edgeCount++;
            }

            if(edgeCount < 1 || subtree.size() != edgeCount + 1) continue;

            int diameter = calculateDiameter(subtree, adj);
            if(diameter > 0){
                result[diameter-1]++;
            }
        }

        return result;
    }
};

//Time complexity: O(2^n * n^2)
//Space complexity: O(n^2)