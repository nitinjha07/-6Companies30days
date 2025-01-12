//Leetcode submission link: https://leetcode.com/problems/count-the-number-of-square-free-subsets/submissions/1506360665/

class Solution {
public:
    int MOD = 1e9 + 7;
    int memo[1001][1024];
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    int dfs(int idx, int mask, vector<int>& nums) {
        if (idx == nums.size()) return 1;
        if (memo[idx][mask] != -1) return memo[idx][mask];

        int currMask = mask, isValid = 1;
        int num = nums[idx];
        for (int i = 0; i < primes.size(); i++) {
            int count = 0;
            while (num % primes[i] == 0) num /= primes[i], count++;
            if (count > 1 || (count == 1 && (mask & (1 << i)))) {
                isValid = 0;
                break;
            }
            if (count == 1) currMask |= (1 << i);
        }

        if (isValid) {
            return memo[idx][mask] = (dfs(idx + 1, mask, nums) + dfs(idx + 1, currMask, nums)) % MOD;
        } else {
            return memo[idx][mask] = dfs(idx + 1, mask, nums);
        }
    }

    int squareFreeSubsets(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return (dfs(0, 0, nums) - 1 + MOD) % MOD;
    }
};


// Time Complexity: O(N * 2^P), where N is the number of elements in the input array and P is the number of prime numbers used in the solution.
// Space Complexity: O(N * 2^P)