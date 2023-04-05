#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib> // содержит srand() и rand()

using namespace std;

enum HelpFlg {
	HMaxMin = 0,
	HSDomin,
	HWDomin,
	//HNLO
	HFInput
};

bool CInput(bool& flgBimatrix, vector<vector<float>>& game);
bool FInput(bool& flgBimatrix, vector<vector<float>>& game);
bool GInput(bool& flgBimatrix, vector<vector<float>>& game);
//bool MatrixType(bool& flgBimatrix);
bool ReadMatr(vector<vector<float>>& game, int n, int m, istream& file = cin);
bool CheckFormat(int n, int m);
void Help(HelpFlg flg);