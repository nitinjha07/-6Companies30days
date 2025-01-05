//Leetcode submission link: https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/submissions/1498229465/

class Solution {
    bool isPal(string s){
        int n = s.length();
        int i = 0;
        int j = n-1;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int idx, string& s, string s1, string s2, int& ans){
        if(idx == s.size()){
            if(isPal(s1) && isPal(s2)){
                int curr = s1.size() * s2.size();
                ans = max(ans, curr);
            }
            return;
        }

        s1.push_back(s[idx]);
        solve(idx+1, s, s1, s2, ans);
        s1.pop_back();

        s2.push_back(s[idx]);
        solve(idx+1, s, s1, s2, ans);
        s2.pop_back();

        solve(idx+1, s, s1, s2, ans);
    }
public:
    int maxProduct(string s) {
        string s1 = "";
        string s2 = "";
        int ans = 0;
        solve(0, s, s1, s2, ans);
        return ans;
    }
};

//Time complexity: O(3^n*k)
//Space complexity: O(n)