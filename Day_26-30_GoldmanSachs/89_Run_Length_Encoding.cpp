//Problem Link: https://www.geeksforgeeks.org/problems/run-length-encoding/1
//GFG Profile Link: https://www.geeksforgeeks.org/user/nitinkumaf2c2/

class Solution {
  public:
    string encode(string s) {
        int n = s.size();
        string encoded = "";

        for(int i=0;i<n;i++){
            int cnt = 1;
            while(i < n - 1 && s[i] == s[i+1]){
                cnt++;
                i++;
            }
            encoded += s[i];
            encoded += to_string(cnt);
        }
        return encoded;

    }
};

//Time complexity: O(n)
//Space complexity: O(1)