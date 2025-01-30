//Leetcode submission link: https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/submissions/1525645823/

class Solution {
public:
    int solve(int s, int i, int j, int k, int e, vector<vector<int>>& dp, int m) {
        if(i==k && j==e) return 1;
        else if(i==k && j!=e) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int left = solve(s, i + 1, j - 1, k, e, dp, m);
        int right = solve(s, i + 1, j + 1, k, e, dp, m);

        return dp[i][j] = (left + right) % m;
    }

    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(k + 1, vector<int>(10000, -1));
        int m = 1e9 + 7;
        return solve(startPos + 1000, 0, startPos + 1000, k, endPos + 1000, dp, m) % m;
    }
};

//Time complexity: O(k)
//Space complexity: O(k)