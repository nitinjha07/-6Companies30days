//Leetcode submission link: https://leetcode.com/problems/repeated-dna-sequences/submissions/1496934683/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, bool> mp;

        int n = s.size();
        int i = 0;
        int j = 0;

        string curr = "";
        vector<string> ans;
        while(j < n){
            curr += s[j];
            if(j-i+1 == 10){
                if(mp.find(curr) != mp.end()){
                    mp[curr] = true;
                }
                else{
                    mp[curr] = false;
                }

                //slide window
                curr.erase(0, 1);
                i++;
            }
            j++;
        }

        for(auto ele : mp){
            if(ele.second == true){
                ans.push_back(ele.first);
            }
        }

        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)