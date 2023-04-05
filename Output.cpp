#include "Output.h"

void COutput(vector<vector<float>>& game, ostream& file) {
	int n = game.size();
	int m;
	if (n == 0) {
		cout << "Матрица не введена" << endl;
		return;
	}

	m = game[n - 1].size();

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
	int m;
	if (n == 0) {
		cout << "Матрица не введена" << endl;
		return false;
	}

	m = game[n - 1].size();
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


bool OutDomin(vector<vector<float>>& game, vector<vector<float>>(*Domin)(vector<vector<float>>&)) {
	vector<vector<float>> Dominated = Domin(game);
	if (Dominated.size() == 0) return true;
	cout << "Для вывода результата в консоль введите - c; в файл введите - f: ";
	string out;
	cin >> out;
	if (out == "c") {
		cout << "Полученнная матрица:" << endl;
		COutput(Dominated);
	}
	else if (out == "f") FOutput(Dominated);
	else {
		cout << "Введен неверный формат вывода" << endl;
		return false;
	}
	return true;
}

