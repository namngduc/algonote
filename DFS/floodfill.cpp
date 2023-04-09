#include<bits/stdc++.h>

bool isValid(int x, int y, std::vector<std::vector<int>>& image){
    return x>=0 && x < image.size() && y>=0 && image[0].size();
}

void fill(std::vector<std::vector<int>>& image, int x, int y, int origiColor, int newColor) {
    if (not isValid(x, y, image)) return;
    if (image[x][y] != origiColor) return;
    if (image[x][y] == -1) return;
    image[x][y] = -1;
    fill(image, x-1, y, origiColor, newColor);
    fill(image, x+1, y, origiColor, newColor);
    fill(image, x, y-1, origiColor, newColor);
    fill(image, x, y+1, origiColor, newColor);
    image[x][y] = newColor;
}

int main() {
    std::vector<std::vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1},
    };
    int sr=1, sc=1, newColor=2;
    fill(image, sr, sc, image[sr][sc], newColor);
    for (int i = 0; i < image.size(); i++){
        for (int j = 0; j < image[i].size(); j++){
            std::cout << image[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}