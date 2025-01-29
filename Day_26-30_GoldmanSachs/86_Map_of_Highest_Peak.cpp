//Leetcode submission link: https://leetcode.com/problems/map-of-highest-peak/submissions/1516497051/

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(isWater[i][j]){
                    q.push({{i, j}, 0});
                    ans[i][j] = 0;
                }
            }
        }

        vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int h = q.front().second;
            q.pop();


            for(int i = 0; i < 4; i++){
                int nr = row + dir[i].first;
                int nc = col + dir[i].second;

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && ans[nr][nc] == -1){
                    q.push({{nr, nc}, h+1});
                    ans[nr][nc] = h+1;
                }
            }
        }

        return ans;
    }
};

//Time complexity: O(n*m)
//Space complexity: O(n*m)