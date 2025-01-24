//Leetcode submission link: https://leetcode.com/problems/query-kth-smallest-trimmed-number/submissions/1512170978/

//Approach-1
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> ans;

        for(auto query : queries){  //o(m)
            priority_queue<pair<string, int>> pq;
            int trim = query[1];
            int k = query[0];

            for(int i = 0; i < n; i++){ //o(n)
                string num = nums[i];
                string newNum = num.substr(num.size()-trim);    //o(p), p is the length of num

                pq.push({newNum, i});   //o(log(k))
                if(pq.size() > k) pq.pop();
            }

            ans.push_back(pq.top().second);
        }

        return ans;
    }
};

//Time complexity: (n*m*(p+log(k)))
//Space complexity: O(k+m+p)


//Approach-2
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

//Time complexity: O(maxTrim⋅n⋅logn+m)
//Space complexity: O(n⋅maxTrim)