//Leetcode submission link: https://leetcode.com/problems/sum-of-scores-of-built-strings/submissions/1513766869/

class Solution {
public:
    long long sumScores(string s) {
        vector<int> pre(s.size(), -1);
        vector<int> cnt(s.size(), 1);

        for(int i = 1; i < s.size(); i++) {
            int j = pre[i - 1];
            while(j != -1 && s[i] != s[j + 1]) {
                j = pre[j];
            }
            pre[i] = s[i] == s[j+1] ? ++j : j;
            cnt[i] = j == -1 ? 1 : cnt[j] + 1;
        }

        return accumulate(cnt.begin(), cnt.end(), 0LL);
    }
};

//Time complexity: O(n)
//Space complexity: O(n)