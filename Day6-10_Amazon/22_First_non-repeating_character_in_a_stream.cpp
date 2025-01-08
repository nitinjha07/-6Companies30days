//Leetcode submission link: https://leetcode.com/problems/first-unique-character-in-a-string/submissions/1501375560/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;

        for(char ch : s){
            mp[ch]++;
        }

        for(int i = 0; i < s.size(); i++){
            if(mp[s[i]] == 1){
                return i;
            }
        }

        return -1;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)