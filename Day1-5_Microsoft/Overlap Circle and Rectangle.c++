// Leetcode solution submission: https://leetcode.com/problems/circle-and-rectangle-overlapping/submissions/1494137871

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int minX = max(x1, min(xCenter, x2));
        int minY = max(y1, min(yCenter, y2));

        int distX = minX - xCenter;
        int distY = minY - yCenter;

        return (distX * distX) + (distY * distY) <= radius * radius;
    }
};