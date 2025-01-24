//Leetcode submission link: https://leetcode.com/problems/count-collisions-on-a-road/submissions/1518875968/

class Solution {
public:
    int countCollisions(string directions) {
        int r = 0;
        int l = 0;
        bool obs = false;
        int result = 0;

        for(int i = 0; i < directions.size(); i++){
            char dir = directions[i];

            if(dir == 'R'){
                r++;
            }
            else if(dir == 'S'){
                result += r;
                r = 0;
                obs = true;
            }
            else{
                if(r > 0){
                    result += r+1;
                    r = 0;
                    obs = true;
                }
                else if (obs){
                    result++;
                }
            }
        }
        return result;
    }
};

//Time complexity: O(n)
//Space complexity: O(1)