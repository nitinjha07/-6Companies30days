//Leetcode submission link: https://leetcode.com/problems/query-kth-smallest-trimmed-number/submissions/1521210847/

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> ans;

        int maxTrim = 0;
        for(auto& query : queries){
            maxTrim = max(maxTrim, query[1]);
        }

        unordered_map<int, vector<pair<string, int>>> mp; //precomputed trimmed strings
        for(int t = 1; t <= maxTrim; t++){
            vector<pair<string, int>> trimmed;
            for(int i = 0; i < n; i++){
                trimmed.push_back({nums[i].substr(nums[i].size()-t), i});
            }
            sort(trimmed.begin(), trimmed.end());
            mp[t] = trimmed;
        }

        for(auto& q : queries){
            int trim = q[1];
            int k = q[0];
            ans.push_back(mp[trim][k-1].second);
        }

        return ans;
    }
};

//Time complexity: O(n*m*log(n))
//Space complexity: O(n*m)