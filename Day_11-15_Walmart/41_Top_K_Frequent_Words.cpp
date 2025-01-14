//Leetcode submission link: https://leetcode.com/problems/top-k-frequent-words/submissions/1508437026/

struct compare{
    bool operator() (const pair<int, string>& a, const pair<int, string>& b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        for(string word : words){
            mp[word]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;

        for(auto it : mp){
            pq.push({it.second, it.first});
            if(pq.size() > k) pq.pop();
        }

        vector<string> ans(k);
        int idx = k-1;
        while(!pq.empty()){
            ans[idx--] = pq.top().second;
            pq.pop();
        }

        return ans;
    }
};

//Time complexity: O(nlogk)
//Space complexity: O(n)