//https://leetcode.com/problems/battleships-in-a-board/submissions/1508444889/

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'X' && (i == 0 || board[i-1][j] == '.') && (j == 0 || board[i][j-1] == '.')){
                    ans++;
                }
            }
        }

        return ans;
    }
};

//Time complexity: O(n*m)
//Space complexity: O(1)