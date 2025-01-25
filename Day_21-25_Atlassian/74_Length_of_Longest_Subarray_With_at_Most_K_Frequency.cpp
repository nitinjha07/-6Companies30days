//Leetcode submission link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/submissions/1520113160/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int i = 0;
        int j = 0;
        int maxLen = 1;
        while(j < n){
            mp[nums[j]]++;

            while(i < j && mp[nums[j]] > k){
                mp[nums[i]]--;
                i++;
            }

            maxLen = max(maxLen, j-i+1);
            j++;
        }

        return maxLen;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)