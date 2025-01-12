//Leetcode Submission Link: https://leetcode.com/problems/bulls-and-cows/submissions/1496030455/

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;

        unordered_map<char, int> mp;
        for(int i = 0; i < secret.size(); i++){
            if(secret[i] != guess[i]){
                mp[secret[i]]++;
            }
        }

        for(int i = 0; i <guess.size(); i++){
            if(secret[i] == guess[i]){
                bulls++;
                continue;
            }
            else if(mp.find(guess[i]) != mp.end()) {
                mp[guess[i]]--;
                cows++;
                if(mp[guess[i]] == 0) mp.erase(guess[i]);
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

//Time Complexity: O(n) 
//Space Complexity: O(1) -> map will have at most 10 elements