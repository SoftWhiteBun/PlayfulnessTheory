#include "UserInteraction.h"

bool CInput(bool& flgBimatrix, vector<vector<float>>& game) {
	int n = 0; //строки
	int m = 0; //столбцы
	string str1, str2;

	cout << "Введите размер матрицы (формат ввода: строки столбцы): ";
	cin >> str1 >> str2;
	try {
		n = std::stoi(str1);
		m = std::stoi(str2);
	}
	catch (std::invalid_argument e) {
		cout << "Неверный формат - введен строковый символ или строка" << endl;
	}
	if (!CheckFormat(n, m)) return false;

	cout << "Введите матрицу:" << endl;
	if (!ReadMatr(game, n, m)) return false;
	return true;
}

bool FInput(bool& flgBimatrix, vector<vector<float>>& game) {
	string fileName;
	int n = 0;
	int m = 0;
	string str1, str2;

	cout << endl;
	cout << "Введите имя файла:" << endl;
	cin >> fileName;

	ifstream file{ fileName };
	if (!file) {
		cout << "Неудалось открыть файл для чтения" << endl;
		return false;
	}
	do {
		file >> str1 >> str2;
		try {
			n = std::stoi(str1);
			m = std::stoi(str2);
		}
		catch (std::invalid_argument e) {
			cout << "Неверный формат - введен строковый символ или строка" << endl;
		}
		if (!CheckFormat(n, m)) return false;

		if (!ReadMatr(game, n, m, file)) return false;
	} while (!file.eof());

	if (game.size() != n || game[n - 1].size() != m) {
		cout << "Введены неверные размеры матрицы" << endl;
		return false;
	}
	return true;
}

bool ReadMatr(vector<vector<float>>& game, int n, int m, istream& file) {
	game.clear();
	int i = 0;
	try {
		while (!file.eof() && i < n) {
			vector<float> jvec;
			int j = 0;
			while (!file.eof() && j < m) {
				string str;
				file >> str;
				float elem = stof(str);
				jvec.push_back(elem);
				++j;
			}
			game.push_back(jvec);
			++i;
		}
	}
	catch (std::invalid_argument e) {
		cout << "Неверный формат - введен строковый символ или строка" << endl;
		return false;
	}
	return true;
}

bool CheckFormat(int n, int m) {
	if (n <= 0 || m <= 0) {
		cout << "Неверный формат матрицы" << endl;
		return false;
	}
	return true;
}

//-----------------------------------------------------

//bool MatrixType(bool& flgBimatrix) {
//	string flg;
//	cout << "Введите тип матрицы" << endl;
//	cout << "b - биматрица" << endl;
//	cout << "m - простая матрица" << endl;
//	cout << "e - выход" << endl;
//	cin >> flg;
//	if (flg == "b") flgBimatrix = true;
//	else if (flg == "m") flgBimatrix = false;
//	else if (flg == "e") exit(0);
//	else {
//		cout << "Некорректный тип матрицы" << endl;
//		return false;
//	}
//	return true;
//}


void Help(HelpFlg flg) {
	switch (flg) {
	case HMaxMin: 
		cout << endl;
		cout << "Максимин - это стратегия осторожности\n(находится минимальный выигрыш в каждой стратегии, из этих значений выбирается максимальное).\nИгрок максимизирует свой результат при наихудшем для него выборе соперника.\n\nПри этом для второго игрока стратегия следует признаку минимакса(находится максимальный выигрыш в каждой стратегии, из этих значений ищется минимальное)." << endl;
		break;
	case HSDomin:
		cout << endl;
		cout << "Строго доминируемой называется стратегия s', которая в любой подситуации будет проигрывать стратегии s\".\n В матричной игре для первого игрока она рассчитывается исходя из значений, представленных в матрице.\nДля второго игрока берется противоположное число для каждого элемента матрицы." << endl;
		break;
	case HWDomin:
		cout << endl;
		cout << "Слабо доминируемой называется стратегия s', которая в любой подситуации будет проигрывать или будет равна стратегии s\".\nВ матричной игре для первого игрока она рассчитывается исходя из значений, представленных в матрице.\nДля второго игрока берется противоположное число для каждого элемента матрицы.\nВНИМАНИЕ: При последовательном исключении слабо доминируемых стратегий, конечное множество\nстратегий зависит от порядка исключения.\nДля изменения порядка исключения введите строки/столбцы, соответствующие стратегиям, в другом порядке." << endl << endl;
		break;
	/*case HNLO:
	    cout << endl;
		cout << "НЛО называется стратегия никогда не лучшего ответа, т.е. это та стратегия s', которая ни при какой подситуации\nне будет являться наилучшим ответом. Рациональный игрок при выборе НЛО стратегии всегда будет жалеть,\n что не выбрал какую-либо другую из своих стратегий." << endl << endl;
		break;*/
	case HFInput:
		cout << endl;
		cout << "Формат ввода матрицы через файл:\n<Количество строк> <Количество столбцов>\n<Элементы матрицы> " << endl;
		cout << "Пример:\n3 4\n1 2 3 4\n5 6 7 8\n9 10 11 12" << endl;
		break;
	}
}
