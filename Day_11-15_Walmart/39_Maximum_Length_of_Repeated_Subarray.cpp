//Approach-1
//Leetcode submission link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/submissions/1507539973/

class Solution {
    vector<vector<int>> dp;
    int solve(int idx1, int idx2, vector<int>& nums1, vector<int>& nums2){
        if(idx1 >= nums1.size()) return 0;
        if(idx2 >= nums2.size()) return 0;

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(nums1[idx1] == nums2[idx2]){
            dp[idx1][idx2] = 1 + solve(idx1 + 1, idx2 + 1, nums1, nums2);
        }
        else dp[idx1][idx2] = 0;

        return dp[idx1][idx2];
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        dp.resize(n, vector<int>(m, -1));
        int maxi = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                maxi = max(maxi, solve(i, j, nums1, nums2));
            }
        }
        return maxi;
    }
};

//Time complexity: O(n*m)
//Space complexity: O(n*m)


//Approach-2

//Leetcode submission link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/submissions/1507551242/
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        int maxi = 0;

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else{
                    if(nums1[i-1] == nums2[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                        maxi = max(maxi, dp[i][j]);
                    }
                    else dp[i][j] = 0;
                }
            }
        }
        return maxi;
    }
};

//Time complexity: O(n*m)
//Space complexity: O(n*m)