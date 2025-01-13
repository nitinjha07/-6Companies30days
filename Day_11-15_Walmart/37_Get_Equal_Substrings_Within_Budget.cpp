//Leetcode submission link: https://leetcode.com/problems/get-equal-substrings-within-budget/submissions/1507435934/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();

        int i = 0;
        int j = 0;
        int ans = 0;

        while(j < n){
            maxCost -= abs(s[j] - t[j]);

            while(maxCost < 0){
                maxCost += abs(s[i] - t[i]);
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)