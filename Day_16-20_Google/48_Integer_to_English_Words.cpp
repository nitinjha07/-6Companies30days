//Leetcode submission link: https://leetcode.com/problems/integer-to-english-words/submissions/1510360522/

class Solution {
    vector<string> belowTwenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                                      "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                      "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string solve(int num){
        if(num < 20) return belowTwenty[num];

        if(num < 100){
            return tens[num/10] + ((num%10 != 0) ? " " + solve(num%10) : "");
        }

        if(num < 1000){
            return solve(num/100) + " Hundred" + ((num%100 != 0) ? " " + solve(num%100) : "");
        }

        if(num < 1000000){
            return solve(num/1000) + " Thousand" + ((num%1000 != 0) ? " " + solve(num%1000) : "");
        }

        if(num < 1000000000){
            return solve(num/1000000) + " Million" + ((num%1000000 != 0) ? " " + solve(num%1000000) : "");
        }

        return solve(num/1000000000) + " Billion" + ((num%1000000000 != 0) ? " " + solve(num%1000000000) : "");
    }
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        return solve(num);
    }
};

//Time complexity: O(log10(num))
//Space complexity: O(log10(num))