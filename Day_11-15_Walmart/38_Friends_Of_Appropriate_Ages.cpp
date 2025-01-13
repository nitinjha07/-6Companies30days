//Leetcode submission link: https://leetcode.com/problems/friends-of-appropriate-ages/submissions/1507462428/

class Solution {
    bool isPossible(int a, int b){
        return !((b <= 0.5*a + 7) || (b > a) || (b > 100 && a < 100));
    }
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        int count = 0;
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            mp[ages[i]]++;
        }

        for(int ageA = 1; ageA <= 120; ageA++){
            for(int ageB = 1; ageB <= 120; ageB++){
                if(mp.find(ageA) == mp.end() || mp.find(ageB) == mp.end()) continue;
                if(isPossible(ageA, ageB)){
                    if(ageA != ageB) count += (mp[ageA]*mp[ageB]);
                    else count += (mp[ageA]*(mp[ageA]-1));
                }
            }
        }
        return count;
    }
};

//Time complexity: O(n)
//Space complexity: O(120) = O(1)