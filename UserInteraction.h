#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

bool CInput(bool& flgBimatrix, vector<vector<float>>& game);
bool FInput(bool& flgBimatrix, vector<vector<float>>& game);
bool MatrixType(bool& flgBimatrix);
bool ReadMatr(vector<vector<float>>& game, int n, int m, istream& file = cin);
bool CheckFormat(int n, int m);