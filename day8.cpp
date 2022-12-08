#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <string>

using namespace std;

auto rotate90(const vector<vector<int>>& matrix) {
    vector<vector<int>> rotated(matrix[0].size(), vector<int>(matrix.size()));
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            rotated[matrix[i].size() - 1 - j][i] = matrix[i][j];
        }
    }
    return rotated;
}

int main() {
    vector<vector<int>> trees;
    ifstream file("day8.txt");
    for (string line; getline(file, line);) {
        trees.push_back({});
        for (char c : line) {
            trees.back().push_back(c - '0');
        }
    }


    // Part 1: count the number of visible trees
    vector<vector<int>> visible(trees.size(), vector<int>(trees[0].size()));
    for (int i = 0; i < 4; ++i) {
        for (size_t row = 0; row < trees.size(); ++row) {
            int tallest = -1;
            for (size_t col = 0; col < trees[row].size(); ++col) {
                int height = trees[row][col];
                if (height > tallest) {
                    visible[row][col] = 1;
                    tallest = height;
                }
            }
        }
        trees = rotate90(trees);
        visible = rotate90(visible);
    }

    int visibleCount = accumulate(
        visible.begin(), visible.end(), 0, [](int sum, const vector<int>& row) {
            return sum + accumulate(row.begin(), row.end(), 0);
        });
    cout << visibleCount << " trees are visible from outside the grid\n";
    // Part 2: calculate the highest possible score
    vector<vector<int>> scores(trees.size(), vector<int>(trees[0].size(), 1));
    for (int i = 0; i < 4; ++i) {
        for (size_t row = 0; row < trees.size(); ++row) {
            array<int, 10> visDistForHeight = { 0 };
            for (size_t col = 0; col < trees[row].size(); ++col) {
                int height = trees[row][col];
                scores[row][col] *= visDistForHeight[height];
                fill(visDistForHeight.begin(),
                    visDistForHeight.begin() + height + 1, 1);
                for_each(visDistForHeight.begin() + height + 1,
                    visDistForHeight.end(), [](int& x) { ++x; });
            }
        }
        trees = rotate90(trees);
        scores = rotate90(scores);
    }

    int maxScore =
        accumulate(scores.begin(), scores.end(), 0,
            [](int maxval, const vector<int>& row) {
                return max(maxval, *max_element(row.begin(), row.end()));
            });
    cout << "The highest possible score is " << maxScore << '\n';

    return 0;
}
