//Leetcode submission link: https://leetcode.com/problems/extra-characters-in-a-string/submissions/1509272898/

class Solution {
    vector<int> dp;
    int solve(int idx, string& s, unordered_set<string>& st){
        if(idx >= s.size()) return 0;
        if(dp[idx] != -1) return dp[idx];

        string currStr = "";
        int minExtra = s.size();

        for(int i = idx; i < s.size(); i++){
            currStr.push_back(s[i]);
            int currExtra = st.count(currStr) ? 0 : currStr.size();
            int nextExtra = solve(i+1, s, st);

            minExtra = min(minExtra, currExtra + nextExtra);
        }

        return dp[idx] = minExtra;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st;
        for(auto ele : dictionary) st.insert(ele);

        dp.resize(s.size()+1, -1);

        return solve(0, s, st);
    }
};

//Time complexity: O(N^2)
//Space complexity: O(N)