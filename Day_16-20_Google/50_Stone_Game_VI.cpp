//Leetcode submission link: https://leetcode.com/problems/stone-game-vi/submissions/1511167244/

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int, int>> total;

        for(int i = 0; i < n; i++){
            total.push_back({aliceValues[i] + bobValues[i], i});
        }

        sort(total.rbegin(), total.rend());

        int alicePoints = 0;
        int bobPoints = 0;

        for(int i = 0; i < n; i++){
            int idx = total[i].second;
            if(i%2 == 0){   //alice trun
                alicePoints += aliceValues[idx];
            }
            else bobPoints += bobValues[idx];
        }

        if(alicePoints > bobPoints) return 1;
        else if(alicePoints < bobPoints) return -1;
        else return 0;
    }
};

//Time complexity: O(nlogn)
//Space complexity: O(n)