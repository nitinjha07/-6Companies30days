//Leetcode Submission Link: https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/submissions/1513761411/

class Solution {
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;

    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        vis[row][col] = true;

        for(int i = 0; i < 4; i++){
            int ni = row + dir[i][0];
            int nj = col + dir[i][1];

            if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && grid[ni][nj]){
                dfs(ni, nj, grid, vis);
            }
        }

        return;
    }

    int countIslands(vector<vector<int>>& grid){
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j]){
                    count++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return count;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int islands = countIslands(grid);
        if(islands == 0 || islands > 1) return 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    grid[i][j] = 0;
                    islands = countIslands(grid);
                    if(islands == 0 || islands > 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)