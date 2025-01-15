//Leetcode submittion link: https://leetcode.com/problems/sort-characters-by-frequency/submissions/1509102275/

class compare{
    public:
    bool operator()(const pair<char, int>& a, const pair<char, int>& b){
        return a.second > b.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char ch : s) mp[ch]++;

        vector<pair<char, int>> freq(mp.begin(), mp.end());

        sort(freq.begin(), freq.end(), compare());

        string ans = "";
        for(auto [ch, fr] : freq){
            if(fr == 0) break;
            while(fr > 0){
                ans.push_back(ch);
                fr--;
            }
        }

        return ans;
    }
};

//Time complexity: O(nlogn)
//Space complexity: O(n)