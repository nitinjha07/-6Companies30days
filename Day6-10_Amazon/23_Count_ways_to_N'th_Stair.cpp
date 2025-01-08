//Leetcode submission link: https://leetcode.com/problems/find-number-of-ways-to-reach-the-k-th-stair/submissions/1501421723/

class Solution {
    unordered_map<string, int> mp;
    int solve(int curr, int k, bool canBack, int jump, vector<long long>& exp){
        if(curr > k+1) return 0;

        string key = to_string(curr) + "_" + to_string(canBack) + "_" + to_string(jump);

        if(mp.find(key) != mp.end()) return mp[key];

        int ans = 0;
        if(curr == k) ans += 1;

        if(curr > 0 && canBack) ans += solve(curr-1, k, false, jump, exp);
        ans += solve(curr + exp[jump], k, true, jump+1, exp);

        return mp[key] = ans;
    }
public:
    int waysToReachStair(int k) {
        mp.clear();

        vector<long long> exp(33, 0);

        for(int i = 0; i < 33; i++){
            exp[i] = pow(2, i);
        }

        return solve(1, k, true, 0, exp);
    }
};

//Time complexity: O(log(k))
//Space complexity: O(log(k))