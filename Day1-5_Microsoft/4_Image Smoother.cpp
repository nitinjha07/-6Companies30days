//Leetcode submission link: https://leetcode.com/problems/image-smoother/submissions/1494961439/


//Approach 1
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();

        vector<int> x = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> y = {-1, 0, 1, -1, 1, -1, 0, 1};

        vector<vector<int>> result(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int totalSum = img[i][j];
                int count = 1;
                for(int k = 0; k < 8; k++){
                    int newX = i + x[k];
                    int newY = j + y[k];
                    if(newX >= 0 && newX < n && newY >= 0 && newY < m){
                        totalSum += img[newX][newY];
                        count++;
                    }
                }
                result[i][j] = (totalSum/count);
            }
        }
        return result;
    }
};

//Time Complexity: O(n*m)
//Space Complexity: O(n*m)

//Approach 2
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();

        vector<int> prevRow(m);
        int prevCorner = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                //current cell
                int totalSum = img[i][j];
                int count = 1;

                //bottom row
                if(i+1 < n){
                    if(j-1 >= 0){
                        totalSum += img[i+1][j-1];
                        count++;
                    }

                    totalSum += img[i+1][j];
                    count++;

                    if(j+1 < m){
                        totalSum += img[i+1][j+1];
                        count++;
                    }
                }

                //right
                if(j+1 < m){
                    totalSum += img[i][j+1];
                    count++;
                }

                //left
                if(j-1 >= 0){
                    totalSum += prevRow[j-1];
                    count++;
                }

                //top row
                if(i-1 >= 0){
                    if(j-1 >= 0){
                        totalSum += prevCorner;
                        count++;
                    }

                    totalSum += prevRow[j];
                    count++;

                    if(j+1 < m){
                        totalSum += prevRow[j+1];
                        count++;
                    }
                }

                if(i-1 >= 0){
                    prevCorner = prevRow[j];
                }
                prevRow[j] = img[i][j];
                img[i][j] = totalSum/count;
            }
        }
        return img;
    }
};

//Time Complexity: O(n*m)
//Space Complexity: O(m)
