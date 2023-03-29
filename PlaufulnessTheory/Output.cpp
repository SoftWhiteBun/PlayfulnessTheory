#include "Output.h"

void COutput(vector<vector<float>> &game, ostream& file) {
	int n = game.size();
	int m = game[n - 1].size();

	file << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			file << game[i][j] << " ";
		}
		file << endl;
	}
}

bool FOutput(vector<vector<float>>& game) {
	int n = game.size();
	int m = game[n - 1].size();
	string filename;

	cout << "Введите имя файла:" << endl;
	cin >> filename;

	ofstream file{ filename };
	if (!file.is_open()) {
		cout << "Неудалось открыть файл для записи" << endl;
		return false;
	}

	COutput(game, file);

	return true;
}
