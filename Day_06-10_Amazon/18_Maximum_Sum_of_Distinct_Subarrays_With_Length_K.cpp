//Leetcode submission link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/submissions/1499659600/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int i = 0;
        int j = 0;

        long long maxSum = 0;
        long long currSum = 0;
        while(j < n){
            mp[nums[j]]++;
            currSum += nums[j];

            if((j-i+1) == k){
                if(mp.size() == k){
                    maxSum = max(maxSum, currSum);
                }
                mp[nums[i]]--;
                currSum -= nums[i];
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            j++;
        }

        return maxSum;
    }
};

//Time complexity: O(n)
//Space complexity: O(n)