

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        int m = source.size();

        vector<vector<int>> dist(26, vector<int>(26, INT_MAX/2));

        for(int i = 0; i < 26; i++){
            dist[i][i] = 0;
        }

        for(int i = 0; i < n; i++){
            dist[original[i] - 'a'][changed[i] - 'a'] = min(cost[i], dist[original[i] - 'a'][changed[i] - 'a']);
        }

        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        long long ans = 0;
        for(int i = 0; i < m; i++){
            if(source[i] != target[i]){
                long long c = dist[source[i] - 'a'][target[i] - 'a'];
                if(c == INT_MAX/2) return -1;
                else ans += c;
            }
        }
        return ans;
    }
};

// Time Complexity: o(26^3+m)
// Space Complexity: o(26^2)
