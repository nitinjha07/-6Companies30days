//Leetcode Submission Link: https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/submissions/1495892548/

class Solution {
    vector<vector<int>> rects;
    vector<long long> cummulativeArea;
    long long totalArea;
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        totalArea = 0;

        for(auto rect : rects){
            long long area = (long long)(rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            totalArea += area;
            cummulativeArea.push_back(totalArea);
        }
    }

    vector<int> pick() {
        int random = rand() % totalArea + 1;    // rand()%totalArea => [0, totalArea-1]
        int rectIndex = lower_bound(cummulativeArea.begin(), cummulativeArea.end(), random) - cummulativeArea.begin();
        if (rectIndex >= rects.size()) {
            rectIndex = rects.size() - 1;
        }

        int a = rects[rectIndex][0];
        int b = rects[rectIndex][1];
        int x = rects[rectIndex][2];
        int y = rects[rectIndex][3];

        int randomX = a + rand()%(x-a+1);
        int randomY = b + rand()%(y-b+1);

        return {randomX, randomY};
    }
};

//Time Complexity: O(n+m⋅logn)
//Space Complexity: O(n)