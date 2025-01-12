//Leetcode submission link: https://leetcode.com/problems/valid-sudoku/submissions/1501996483/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //validate each row

        for(int i = 0; i < 9; i++){
            unordered_map<char, int> mp;
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                else if(mp.find(board[i][j]) != mp.end()) return false;
                else mp[board[i][j]]++;
            }
        }

        //validate each column
        for(int i = 0; i < 9; i++){
            unordered_map<char, int> mp;
            for(int j = 0; j < 9; j++){
                if(board[j][i] == '.') continue;
                else if(mp.find(board[j][i]) != mp.end()) return false;
                else mp[board[j][i]]++;
            }
        }

        //validate each subboard
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                unordered_map<char, int> mp;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char curr = board[row * 3 + i][col * 3 + j];
                        if (curr == '.') continue;
                        if (mp.find(curr) != mp.end()) return false;
                        else mp[curr]++;
                    }
                }
            }
        }

        return true;
    }
};

//Time complexity: O(81+81+81)=O(243) = O(1)
//Space complexity: O(9) = O(1)