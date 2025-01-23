//Leetcode submission link: https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/submissions/1517643501/

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int n = startWords.size();
        int m = targetWords.size();

        unordered_map<string, int> mp;
        for(int i = 0; i < m; i++){
            string word = targetWords[i];
            sort(word.begin(), word.end());
            mp[word]++;
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            string word = startWords[i];

            for(char ch = 'a'; ch <= 'z'; ch++){
                word.push_back(ch);
                sort(word.begin(), word.end());
                if(mp.find(word) != mp.end()){
                    count += mp[word];
                    mp[word] = 0;
                }
                word = startWords[i];
            }
        }

        return count;
    }
};

//Time complexity: O(n*m*26*log(26)) = O(n*m)
//Space complexity: O(m)