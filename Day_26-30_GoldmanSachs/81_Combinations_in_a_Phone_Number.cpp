//Leetcode submission link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/1522193122/

class Solution {
    void solve(int idx, string digits, string output, vector<string>& ans, string mapping[]){
        if(idx >= digits.size()){
            ans.push_back(output);
            return;
        }

        int num = digits[idx] - '0';
        string value = mapping[num];

        for(int i = 0; i < value.size(); i++){
            output.push_back(value[i]);
            solve(idx+1, digits, output, ans, mapping);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        if(digits.size() == 0) return ans;

        string output = "";
        solve(0, digits, output, ans, mapping);
        return ans;
    }
};

//Time complexity: O(4^n)
//Space complexity: O(n)