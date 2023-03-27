#include "UserInteraction.h"

void MainMenu(bool &flgInteract, vector<vector<float>> &game) {
	cout << "Для выбора действия введите: " << endl;
	cout << "c - ввод и вывод данных через консоль;" << endl;
	cout << "f - ввод и вывод данных через файл" << endl; //std::cout << "" << std::endl;

	string UInp;
	cin >> UInp;
	if (UInp == "c") {
		flgInteract = true;
		CInput(game);
		//std::cout << "Введите действие: " << std::endl;
		MainMenu(flgInteract, game);
	}
	if (UInp == "f") {
		flgInteract = false;
		FInput(game);
		MainMenu(flgInteract, game);
	}
}

void CInput(vector<vector<float>> &game) {
	int n = 0; //строки
	int m = 0; //столбцы
	//vector<vector<float>> matrix;

	cout << "Введите размер матрицы (формат ввода: строки столбцы): ";
	cin >> n >> m;
	if (n == 0 || m == 0) {
		cout << "Неверный формат матрицы" << endl;
		CInput(game);
	}

	cout << "Введите матрицу:" << endl;
	game.clear();
	for (int i = 0; i < n; ++i) {
		vector<float> jvec;
		for (int j = 0; j < m; ++j) {
			float elem;
			cin >> elem;
			jvec.push_back(elem);
		}
		game.push_back(jvec);
	}
}

bool FInput(vector<vector<float>> &game) {
	string fileName;
	int n = 0;
	int m = 0;
	cout << "Введите имя файла:" << endl;
	cin >> fileName;

	ifstream file{ fileName };
	if (!file) {
		cout << "Неудалось открыть файл для чтения" << endl;
		return false;
	}
	while (file) {
		file >> n >> m;

		if (n == 0 || m == 0) {
			cout << "Неверный формат матрицы" << endl;
			//FInput(game);
			return false;
		}

		game.clear();
		for (int i = 0; i < n; ++i) {
			vector<float> jvec;
			for (int j = 0; j < m; ++j) {
				float elem;
				file >> elem;
				jvec.push_back(elem);
			}
			game.push_back(jvec);
		}
	}
	if (game.size() != n || game[n].size() != m) {
		cout << "Введены неверные размеры матрицы" << endl;
		return false;
	}
	return true;
}