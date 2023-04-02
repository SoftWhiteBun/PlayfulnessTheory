#include "UserInteraction.h"

bool CInput(bool& flgBimatrix, vector<vector<float>>& game) {
	int n = 0; //������
	int m = 0; //�������
	string str1, str2;

	cout << "������� ������ ������� (������ �����: ������ �������): ";
	cin >> str1 >> str2;
	try {
		n = std::stoi(str1);
		m = std::stoi(str2);
	}
	catch (std::invalid_argument e) {
		cout << "�������� ������ - ������ ��������� ������ ��� ������" << endl;
	}
	if (!CheckFormat(n, m)) return false;

	cout << "������� �������:" << endl;
	ReadMatr(game, n, m);
	return true;
}

bool FInput(bool& flgBimatrix, vector<vector<float>>& game) {
	string fileName;
	int n = 0;
	int m = 0;
	string str1, str2;

	cout << "������� ��� �����:" << endl;
	cin >> fileName;

	ifstream file{ fileName };
	if (!file) {
		cout << "��������� ������� ���� ��� ������" << endl;
		return false;
	}
	do {
		file >> str1 >> str2;
		try {
			n = std::stoi(str1);
			m = std::stoi(str2);
		}
		catch (std::invalid_argument e) {
			cout << "�������� ������ - ������ ��������� ������ ��� ������" << endl;
		}
		if (!CheckFormat(n, m)) return false;

		ReadMatr(game, n, m, file);
	} while (!file.eof());

	if (game.size() != n || game[n - 1].size() != m) {
		cout << "������� �������� ������� �������" << endl;
		return false;
	}
	return true;
}

void ReadMatr(vector<vector<float>>& game, int n, int m, istream& file) {
	game.clear();
	int i = 0;
	while (!file.eof() && i < n) {
		vector<float> jvec;
		int j = 0;
		while (!file.eof() && j < m) {
			float elem;
			file >> elem;
			jvec.push_back(elem);
			++j;
		}
		game.push_back(jvec);
		++i;
	}
}

bool CheckFormat(int n, int m) {
	if (n <= 0 || m <= 0) {
		cout << "�������� ������ �������" << endl;
		return false;
	}
	return true;
}

//-----------------------------------------------------

bool MatrixType(bool& flgBimatrix) {
	string flg;
	cout << "������� ��� �������" << endl;
	cout << "b - ���������" << endl;
	cout << "m - ������� �������" << endl;
	cout << "e - �����" << endl;
	cin >> flg;
	if (flg == "b") flgBimatrix = true;
	else if (flg == "m") flgBimatrix = false;
	else if (flg == "e") exit(0);
	else {
		cout << "������������ ��� �������" << endl;
		return false;
	}
	return true;
}