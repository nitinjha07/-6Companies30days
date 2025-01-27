//Leetcode submission link: https://leetcode.com/problems/random-flip-matrix/submissions/1522156451/

class Solution {
public:
    int row, col, total;
    unordered_map<int, int> V;

    Solution(int m, int n) {
        row = m;
        col = n;
        total = m * n;
    }

    vector<int> flip() {
        if (total == 0) return {};

        int randIdx = rand() % total;
        total--;

        int chosenCell;
        if (V.count(randIdx)) {
            chosenCell = V[randIdx];
        } else {
            chosenCell = randIdx;
        }

        if (V.count(total)) {
            V[randIdx] = V[total];
        } else {
            V[randIdx] = total;
        }

        return {chosenCell / col, chosenCell % col};
    }

    void reset() {
        V.clear();
        total = row * col;
    }
};


//Time complexity: O(1)
//Space complexity: O(m*n)