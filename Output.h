#include <iostream>
#include <vector>
#include <fstream>
//#include <iomanip>

using namespace std;

void COutput(vector<vector<float>>& game, ostream& file = cout);
bool FOutput(vector<vector<float>>& game);
bool OutDomin(vector<vector<float>>& game, vector<vector<float>>(*SDomin)(vector<vector<float>>&));