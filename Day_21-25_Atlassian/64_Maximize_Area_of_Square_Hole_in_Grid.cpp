//Leetcode submission link: https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/submissions/1516533967/

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int count = 1;
        int maxH = 1;
        for(int i = 1; i < hBars.size(); i++){
            if(hBars[i] == hBars[i-1] + 1){
                count++;
            }
            else{
                count = 1;
            }
            maxH = max(maxH, count);
        }

        count = 1;
        int maxV = 1;
        for(int i = 1; i < vBars.size(); i++){
            if(vBars[i] == vBars[i-1] + 1){
                count++;
            }
            else{
                count = 1;
            }
            maxV = max(maxV, count);
        }

        int mini = min(maxH, maxV);
        return (mini+1)*(mini+1);
    }
};

//Time complexity: O(nlogn + mlogm)
//Space complexity: O(1)