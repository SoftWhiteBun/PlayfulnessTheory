#include "MaxMin.h"

pair<int, int> MaxMin(vector<vector<float>>& game) {
    int n = game.size();
    int m = game[n - 1].size();
    int max, min;
    int indexJ, indexI;

    indexJ = 0;
    indexI = 0;

    for (int i = 0; i < n; i++)
    {
        min = game[i][0];
        for (int j = 1; j < m; j++)      {
           // if (j == 1) indexJ = 0;
            if (game[i][j] < min) {
                min = game[i][j];
                indexJ = j;
            }
        }
        if (i == 0 || max < min) {
            max = min;
            indexI = i;
        }
    }
    return { indexI, indexJ };
}

pair<int, int> MinMax(vector<vector<float>>& game) {
    int n = game.size();
    int m = game[n - 1].size();
    int max, min;
    int indexJ, indexI;

    indexJ = 0;
    indexI = 0;

    for (int j = 0; j < m; j++) {
        max = game[0][j];

        for (int i = 1; i < n; i++) {
            if (max < game[i][j]) {
                max = game[i][j];
                indexI = i;
            }
        }

        if (j == 0 || min > max) {
            min = max;
            indexJ = j;
        }
    }
    return { indexI, indexJ };
}