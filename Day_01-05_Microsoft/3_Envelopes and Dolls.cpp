//Leetcode Problem: 354. Russian Doll Envelopes
//Leetcode submission link: https://leetcode.com/problems/russian-doll-envelopes/submissions/1494828277/

class Solution {
    static bool compare(const vector<int>& p1, const vector<int>& p2){
        if(p1[0] != p2[0]){
            return p1[0] < p2[0];
        }
        else{
            return p1[1] > p2[1];
        }
    }

    int lis(vector<vector<int>>& envelopes){
        vector<int> ans;
        ans.push_back(envelopes[0][1]);

        for(int i = 1; i < envelopes.size(); i++){
            if(envelopes[i][1] > ans.back()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                int idx = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
                ans[idx] = envelopes[i][1];
            }
        }

        return ans.size();
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);

        return lis(envelopes);
    }
};

//Time complexity: O(nlogn)
//Space complexity: O(n)