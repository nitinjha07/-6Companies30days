//Leetcode submission link: https://leetcode.com/problems/construct-the-longest-new-string/submissions/1520127680/

class Solution {
    int dp[51][51][51][4] = {};
    int solve(int x, int y, int z, int prev){
        if(dp[x][y][z][prev] != 0) return dp[x][y][z][prev];

        int res = 0;
        if(x > 0 && prev != 1) res = max(res, 2 + solve(x-1, y, z, 1));
        if(y > 0 && prev != 2 && prev != 3) res = max(res, 2 + solve(x, y-1, z, 2));
        if(z > 0 && prev != 1) res = max(res, 2 + solve(x, y, z-1, 3));

        return dp[x][y][z][prev] = res;
    }
public:
    int longestString(int x, int y, int z) {
        return solve(x, y, z, 0);
    }
};

//Time complexity: O(51*51*51*4)
//Space complexity: O(51*51*51*4)