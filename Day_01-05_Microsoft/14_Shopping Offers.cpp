//Leetcode submission link: https://leetcode.com/problems/shopping-offers/submissions/1498319128/

class Solution {
    int calculateDirectCost(vector<int>& price, vector<int>& needs){
        int cost = 0;
        for(int i = 0; i < needs.size(); i++){
            cost += (price[i]*needs[i]);
        }
        return cost;
    }
    map<vector<int>, int> mp;
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(mp[needs]) return mp[needs];

        int directCost = calculateDirectCost(price, needs);

        for(auto sp : special){
            vector<int> tempNeeds = needs;
            bool possible = true;
            for(int i = 0; i < tempNeeds.size(); i++){
                tempNeeds[i] -= sp[i];
                if(tempNeeds[i] <= -1){
                    possible = false;
                    break;
                }
            }

            if(possible){
                int offerCost = sp.back() + shoppingOffers(price, special, tempNeeds);
                directCost = min(offerCost, directCost);
            }
        }

        return mp[needs] = directCost;
    }
};

//Time complexity: O(2^n)
//Space complexity: O(2^n)