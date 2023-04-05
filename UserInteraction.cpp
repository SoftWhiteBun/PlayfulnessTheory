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
	if (!ReadMatr(game, n, m)) return false;
	return true;
}

bool FInput(bool& flgBimatrix, vector<vector<float>>& game) {
	string fileName;
	int n = 0;
	int m = 0;
	string str1, str2;

	cout << endl;
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

		if (!ReadMatr(game, n, m, file)) return false;
	} while (!file.eof());

	if (game.size() != n || game[n - 1].size() != m) {
		cout << "������� �������� ������� �������" << endl;
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
		cout << "�������� ������ - ������ ��������� ������ ��� ������" << endl;
		return false;
	}
	return true;
}

bool CheckFormat(int n, int m) {
	if (n <= 0 || m <= 0) {
		cout << "�������� ������ �������" << endl;
		return false;
	}
	return true;
}

//-----------------------------------------------------

//bool MatrixType(bool& flgBimatrix) {
//	string flg;
//	cout << "������� ��� �������" << endl;
//	cout << "b - ���������" << endl;
//	cout << "m - ������� �������" << endl;
//	cout << "e - �����" << endl;
//	cin >> flg;
//	if (flg == "b") flgBimatrix = true;
//	else if (flg == "m") flgBimatrix = false;
//	else if (flg == "e") exit(0);
//	else {
//		cout << "������������ ��� �������" << endl;
//		return false;
//	}
//	return true;
//}


void Help(HelpFlg flg) {
	switch (flg) {
	case HMaxMin: 
		cout << endl;
		cout << "�������� - ��� ��������� ������������\n(��������� ����������� ������� � ������ ���������, �� ���� �������� ���������� ������������).\n����� ������������� ���� ��������� ��� ��������� ��� ���� ������ ���������.\n\n��� ���� ��� ������� ������ ��������� ������� �������� ���������(��������� ������������ ������� � ������ ���������, �� ���� �������� ������ �����������)." << endl;
		break;
	case HSDomin:
		cout << endl;
		cout << "������ ������������ ���������� ��������� s', ������� � ����� ����������� ����� ����������� ��������� s\".\n � ��������� ���� ��� ������� ������ ��� �������������� ������ �� ��������, �������������� � �������.\n��� ������� ������ ������� ��������������� ����� ��� ������� �������� �������." << endl;
		break;
	case HWDomin:
		cout << endl;
		cout << "����� ������������ ���������� ��������� s', ������� � ����� ����������� ����� ����������� ��� ����� ����� ��������� s\".\n� ��������� ���� ��� ������� ������ ��� �������������� ������ �� ��������, �������������� � �������.\n��� ������� ������ ������� ��������������� ����� ��� ������� �������� �������.\n��������: ��� ���������������� ���������� ����� ������������ ���������, �������� ���������\n��������� ������� �� ������� ����������.\n��� ��������� ������� ���������� ������� ������/�������, ��������������� ����������, � ������ �������." << endl << endl;
		break;
	/*case HNLO:
	    cout << endl;
		cout << "��� ���������� ��������� ������� �� ������� ������, �.�. ��� �� ��������� s', ������� �� ��� ����� �����������\n�� ����� �������� ��������� �������. ������������ ����� ��� ������ ��� ��������� ������ ����� ������,\n ��� �� ������ �����-���� ������ �� ����� ���������." << endl << endl;
		break;*/
	case HFInput:
		cout << endl;
		cout << "������ ����� ������� ����� ����:\n<���������� �����> <���������� ��������>\n<�������� �������> " << endl;
		cout << "������:\n3 4\n1 2 3 4\n5 6 7 8\n9 10 11 12" << endl;
		break;
	}
}
