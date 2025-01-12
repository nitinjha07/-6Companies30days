//Leetcode submission link: https://leetcode.com/problems/rotting-oranges/submissions/1503737146/

class Solution {
    bool isAllRotted(vector<vector<int>>grid, int m, int n){
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    return false;
                }
            }
        }
        return true;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();    //row
        int n = grid[0].size(); //column

        //{{row, col}, time}
        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){        //rotten oranges
                    q.push({{i,j}, 0});
                }
            }
        }

        while(!q.empty()){
            pair<pair<int, int>, int> front = q.front();
            q.pop();
            ans = front.second;

            int di[] = {-1, 0, 1, 0};
            int dj[] = {0, 1, 0, -1};

            for(int i=0; i<4; i++){
                int nrow = front.first.first + di[i];
                int ncol = front.first.second + dj[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == 1){
                    grid[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, ans+1});
                }
            }
        }

        if(isAllRotted(grid, m, n)){
            return ans;
        }
        else return -1;
    }
};


//Time complexity: O(m*n)
//Space complexity: O(m*n)