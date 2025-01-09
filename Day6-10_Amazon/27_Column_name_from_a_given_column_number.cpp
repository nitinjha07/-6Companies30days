//Leetcode submission link: https://leetcode.com/problems/excel-sheet-column-title/submissions/1502628006/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";

        while(columnNumber > 0){
            columnNumber--;
            int remainder = columnNumber%26;
            char ch = 'A' + remainder;
            s.push_back(ch);

            columnNumber /= 26;
        }

        reverse(s.begin(), s.end());

        return s;
    }
};

// Time complexity: O(logn)
// Space complexity: O(1)