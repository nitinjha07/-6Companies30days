//Leetcode submission link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/submissions/1506347774/

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(int i=0;i<nums.size();i++)
        {
            q.push({nums[i],i});
            if(q.size()>k)
            {
                q.pop();
            }
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>aux;
        while(!q.empty())
        {
            aux.push({q.top().second,q.top().first});
            q.pop();
        }

        vector<int>ans;
        while(!aux.empty())
        {
            ans.push_back(aux.top().second);
            aux.pop();
        }

        return ans;
    }
};

// Time Complexity: O(NlogK)
// Space Complexity: O(K)