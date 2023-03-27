#include "UserInteraction.h"

bool MatrixType(bool& flgBimatrix) {
	string flg;
	cout << "������� ��� ������� (b - ���������; m - ������� �������): " << endl;
	cin >> flg;
	if (flg == "b") flgBimatrix = true;
	else if (flg == "m") flgBimatrix = false;
	else {
		cout << "������������ ��� �������" << endl;
		return false;
	}
	return true;
}

bool CInput(bool& flgBimatrix, vector<vector<float>>& game) {
	int n = 0; //������
	int m = 0; //�������

	cout << "������� ������ ������� (������ �����: ������ �������): ";
	cin >> n >> m;
	if (!CheckFormat) return false;

	cout << "������� �������:" << endl;
	ReadMatr(game, n, m);
	return true;
}

bool FInput(bool& flgBimatrix, vector<vector<float>>& game) {
	string fileName;
	int n = 0;
	int m = 0;

	cout << "������� ��� �����:" << endl;
	cin >> fileName;

	ifstream file{ fileName };
	if (!file) {
		cout << "��������� ������� ���� ��� ������" << endl;
		return false;
	}
	while (file) {
		file >> n >> m;
		if (!CheckFormat) return false;

        ReadMatr(game, n, m, file);
	}

	if (game.size() != n || game[n-1].size() != m) {
		cout << "������� �������� ������� �������" << endl;
		return false;
	}
	return true;
}

void ReadMatr(vector<vector<float>>& game, int n, int m, istream& file) {
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

bool CheckFormat(int n, int m) {
	if (n == 0 || m == 0) {
		cout << "�������� ������ �������" << endl;
		return false;
	}
	return true;
}

void ReadBimatr(vector<vector<float>>& game, int n, int m, istream& file) {

}





