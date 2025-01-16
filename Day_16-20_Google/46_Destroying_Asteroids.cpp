//Leetcode submission link: https://leetcode.com/problems/destroying-asteroids/submissions/1510240233/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long m = mass;
        sort(asteroids.begin(), asteroids.end());

        for(auto as : asteroids){
            if(as <= m){
                m += as;
            }
            else return false;
        }

        return true;
    }
};

//Time complexity: O(nlogn)
//Space complexity: O(1)