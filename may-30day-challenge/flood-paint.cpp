#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        int image_row = image.size(); //sr
        int image_col = image[0].size(); //sc
        // vector<pair <int, int> > neighbrs; //<x, y> of neighbours

        //paint starting node with given color
        //backup old color before painting
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        if ((sr - 1 >= 0) && (image[sr-1][sc] == oldColor)) { // (i-1, j) case
        floodFill(image, sr-1, sc, newColor);
        }
        if ((sr + 1 < image_row) && (image[sr+1][sc] == oldColor)) { // (i-1, j) case
        floodFill(image, sr+1, sc, newColor);
        }
        if ((sc - 1 >= 0) && (image[sr][sc-1] == oldColor)) { // (i-1, j) case
        floodFill(image, sr, sc-1, newColor);
        }
        if ((sc + 1 < image_col) && (image[sr][sc+1] == oldColor)) { // (i-1, j) case
        floodFill(image, sr, sc+1, newColor);
        }

        return image;

    }
};
