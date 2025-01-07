//My Gfg profile link: https://www.geeksforgeeks.org/user/nitinkumaf2c2/
//Gfg problem link: https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1

class Solution {
    vector<vector<pair<string, int>>> dp;
    pair<string, int> solve(int i, int j, vector<int>& arr){
        if(i == j){
            string st(1, 'A' + i - 1);
            return {st, 0};
        }

        if(dp[i][j].second != -1) return dp[i][j];

        int mini = INT_MAX;
        string st = "";

        for(int k = i; k < j; k++){
            pair<string, int> left = solve(i, k, arr);
            pair<string, int> right = solve(k+1, j, arr);
            int steps = arr[i-1]*arr[k]*arr[j] + left.second + right.second;
            string curr = "(" + left.first + right.first + ")";
            if(steps < mini){
                mini = steps;
                st = curr;
            }
        }


        return dp[i][j] = {st, mini};
    }
  public:
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        dp.resize(n+1, vector<pair<string, int>>(n+1, {"", -1}));

        pair<string, int> ans = solve(1, n-1, arr);

        return ans.first;
    }
};


//Time complexity: O(n^3)
//Space complexity: O(n^2)