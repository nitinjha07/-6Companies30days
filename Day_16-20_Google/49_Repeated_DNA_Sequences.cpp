//Leetcode submission link: https://leetcode.com/problems/repeated-dna-sequences/submissions/1511115503/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;

        int n = s.size();
        int i = 0;
        int j = 0;

        string curr = "";
        vector<string> ans;
        while(j < n){
            curr += s[j];
            if(j-i+1 == 10){
                mp[curr]++;
                curr.erase(0, 1);
                i++;
            }
            j++;
        }

        for(auto ele : mp){
            if(ele.second > 1){
                ans.push_back(ele.first);
            }
        }

        return ans;
    }
};

//Time complexity: O(n)
//Space complexity: O(n)