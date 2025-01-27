//Leetcode submission link: https://leetcode.com/problems/combination-sum-iii/submissions/1521875158/

class Solution {
    void solve(int num, int k, int currSum, int n, vector<int>& curr, vector<vector<int>>& ans){
        if(k == 0 && currSum == n){
            ans.push_back(curr);
            return;
        }

        if(num > 9) return;

        curr.push_back(num);
        solve(num+1, k-1, currSum + num, n, curr, ans);
        curr.pop_back();

        solve(num+1, k, currSum, n, curr, ans);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        int currSum = 0;

        solve(1, k, currSum, n, curr, ans);

        return ans;
    }
};

//Time complexity: O(9^k)
//Space complexity: O(k)