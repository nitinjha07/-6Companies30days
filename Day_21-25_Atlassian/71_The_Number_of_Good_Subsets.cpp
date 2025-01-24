//Leetcode submission link: https://leetcode.com/problems/the-number-of-good-subsets/submissions/1518854448/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    unordered_map<int, int> getPrimeMasks() {
        unordered_map<int, int> primeMask;
        for (int i = 1; i <= 30; ++i) {
            int mask = 0;
            int num = i;
            bool valid = true;
            for (int j = 0; j < primes.size(); ++j) {
                int prime = primes[j];
                if (num % prime == 0) {
                    if (num % (prime * prime) == 0) {
                        valid = false;
                        break;
                    }
                    mask |= (1 << j);
                }
            }
            if (valid) primeMask[i] = mask;
        }
        return primeMask;
    }

    int numberOfGoodSubsets(vector<int>& nums) {
        unordered_map<int, int> primeMask = getPrimeMasks();
        vector<int> count(31, 0);
        for (int num : nums) {
            count[num]++;
        }

        vector<long long> dp(1 << primes.size(), 0);
        dp[0] = 1;

        for (int num = 2; num <= 30; ++num) {
            if (count[num] == 0 || primeMask.find(num) == primeMask.end()) continue;

            int mask = primeMask[num];

            for (int j = (1 << primes.size()) - 1; j >= 0; --j) {
                if ((j & mask) == 0) {
                    dp[j | mask] = (dp[j | mask] + dp[j] * count[num]) % MOD;
                }
            }
        }

        long long answer = 0;
        for (int j = 1; j < (1 << primes.size()); ++j) {
            answer = (answer + dp[j]) % MOD;
        }

        long long powerOfOnes = 1;
        for (int i = 0; i < count[1]; ++i) {
            powerOfOnes = (powerOfOnes * 2) % MOD;
        }

        answer = (answer * powerOfOnes) % MOD;
        return (int)answer;
    }
};


// Time Complexity: O(n + 1024) ≈ O(n)
// Space Complexity: O(1024 + 30) ≈ O(1)