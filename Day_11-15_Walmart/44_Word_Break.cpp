//Leetcode submission link: https://leetcode.com/problems/word-break/submissions/1509197646/

class Solution {
    vector<int> dp;
    bool solve(int idx, string& s, unordered_set<string>& st){
        if(idx >= s.size()) return true;
        if(dp[idx] != -1) return dp[idx];

        string curr = "";
        for(int i = idx; i < s.size(); i++){
            curr.push_back(s[i]);
            if(st.count(curr) && solve(i+1, s, st)){
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto word : wordDict) st.insert(word);

        dp.resize(s.size()+1, -1);

        return solve(0, s, st);
    }
};

// Time Complexity: O(N^2)
// Space Complexity: O(N)