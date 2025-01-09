//My Gfg profile link: https://www.geeksforgeeks.org/user/nitinkumaf2c2/
//Gfg problem link: https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1

class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        unordered_set<char> st;
        vector<char> order = {'!', '#', '$', '%', '&', '*', '?', '@', '^'};

        for(int i = 0; i < n; i++){
            st.insert(nuts[i]);
        }

        int idx = 0;
        for(int i = 0; i < order.size(); i++){
            if(st.count(order[i]) == 0) continue;
            nuts[idx] = order[i];
            idx++;
        }

        st.clear();

        idx = 0;

        for(int i = 0; i < n; i++){
            st.insert(bolts[i]);
        }

        for(int i = 0; i < order.size(); i++){
            if(st.count(order[i]) == 0) continue;
            bolts[idx] = order[i];
            idx++;
        }

        return;
    }
};

//Time complexity: O(n)
//Auxiliary Space: O(n)