//Leetcode submission link: https://leetcode.com/problems/number-of-people-aware-of-a-secret/submissions/1525635473/

class Solution {
public:
    int mod = 1e9 + 7;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n + 1, -1);
        return solve(1, delay, forget, n, dp);
    }

    int solve(int start, int delay, int forget, int n, vector<int>& dp) {
        if (start > n) return 0;
        if (dp[start] != -1) return dp[start];

        int aware = (start + forget > n) ? 1 : 0;

        int end_day = min(start + forget - 1, n);

        for (int day = start + delay; day <= end_day; ++day) {
            aware = (aware + solve(day, delay, forget, n, dp)) % mod;
        }

        dp[start] = aware;
        return aware;
    }
};

//Time complexity: O(n)
//Space complexity: O(n)