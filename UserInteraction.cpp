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
		return false;
	}
	if (!CheckFormat(n, m)) return false;

	cout << "������� �������:" << endl;
	if (!ReadMatr(game, n, m)) return false;
	return true;
}

bool GInput(bool& flgBimatrix, vector<vector<float>>& game) {
	game.clear();
	int n = 0; //������
	int m = 0; //�������
	float min, max;
	bool flgInt;
	string str1, str2;

	cout << "������� ������ ������� (������ �����: ������ �������): ";
	cin >> str1 >> str2;
	try {
		n = std::stoi(str1);
		m = std::stoi(str2);
	}
	catch (std::invalid_argument e) {
		cout << "�������� ������ - ������ ��������� ������ ��� ������" << endl;
		return false;
	}
	if (!CheckFormat(n, m)) return false;

	cout << "������� ������� ��������� ��������� �������� (������ �����: ���. ����.): ";
	cin >> str1 >> str2;
	try {
		min = std::stof(str1);
		max = std::stof(str2);
	}
	catch (std::invalid_argument e) {
		cout << "�������� ������ - ������ ��������� ������ ��� ������" << endl;
		return false;
	}

	cout << "������� i - ��� ��������� ������������� ��������; f - � ��������� �������: ";
	cin >> str1;
	if (str1 == "i") flgInt = true;
	else if (str1 == "f") flgInt = false;
	else {
		cout << "������ �������� ������ ��������" << endl;
		return false;
	}

	int i = 0;
	while ( i < n) {
			vector<float> jvec;
			int j = 0;
			while ( j < m) {
				float elem;
				if (flgInt) elem = min + (rand() % static_cast<int>(max - min + 1));
				else elem = (double)rand() / (double)RAND_MAX * (max - min) + min;
				jvec.push_back(elem);
				++j;
			}
			game.push_back(jvec);
			++i;
	}
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
			return false;
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

	case HFInput:
		cout << endl;
		cout << "������ ����� ������� ����� ����:\n<���������� �����> <���������� ��������>\n<�������� �������> " << endl;
		cout << "������:\n3 4\n1 2 3 4\n5 6 7 8\n9 7 4 8" << endl;
		break;
	}
}
