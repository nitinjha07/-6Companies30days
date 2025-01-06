//Leetcode submission link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/1499046638/


//Approach-1 Top Down DP
class Solution {
    vector<vector<vector<int>>> dp;
    int solve(int idx, bool canBuy, int k, vector<int>& prices){
        if(idx >= prices.size()){
            return 0;
        }

        if(k <= 0) return 0;

        if(dp[idx][canBuy][k] != -1) return dp[idx][canBuy][k];

        int buy = 0;
        int sell = 0;

        if(canBuy == true) buy = -prices[idx] + solve(idx+1, false, k, prices);
        if(canBuy == false) sell = prices[idx] + solve(idx+1, true, k-1, prices);
        int nothing = solve(idx+1, canBuy, k, prices);

        return dp[idx][canBuy][k] = max({buy, sell, nothing});
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.resize(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(0, true, k, prices);
    }
};

// Time complexity: O(n*k)
// Space complexity: O(n*k)


//Approach-2 Bottom Up DP

class Solution {
    vector<vector<vector<int>>> dp;
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.resize(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < k+1; j++){
                dp[n][i][j] = 0;
            }
        }

        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < 2; j++){
                dp[i][j][0] = 0;
            }
        }

        for(int idx = n-1; idx >= 0; idx--){
            for(int canBuy = 0; canBuy < 2; canBuy++){
                for(int kVal = k; kVal >= 1; kVal--){
                    int buy = 0, sell = 0;
                    if(canBuy == 1) buy = -prices[idx] + dp[idx+1][0][kVal];
                    if(canBuy == 0) sell = prices[idx] + dp[idx+1][1][kVal-1];
                    int nothing = dp[idx+1][canBuy][kVal];

                    dp[idx][canBuy][kVal] = max({buy, sell, nothing});
                }
            }
        }


        return dp[0][1][k];
    }
};

// Time complexity: O(n*k)
// Space complexity: O(n*k)