#include "UserInteraction.h"

void MainMenu(bool &flgInteract, vector<vector<float>> &game) {
	cout << "��� ������ �������� �������: " << endl;
	cout << "c - ���� � ����� ������ ����� �������;" << endl;
	cout << "f - ���� � ����� ������ ����� ����" << endl; //std::cout << "" << std::endl;

	string UInp;
	cin >> UInp;
	if (UInp == "c") {
		flgInteract = true;
		CInput(game);
		//std::cout << "������� ��������: " << std::endl;
		MainMenu(flgInteract, game);
	}
	if (UInp == "f") {
		flgInteract = false;
		FInput(game);
		MainMenu(flgInteract, game);
	}
}

void CInput(vector<vector<float>> &game) {
	int n = 0; //������
	int m = 0; //�������
	//vector<vector<float>> matrix;

	cout << "������� ������ ������� (������ �����: ������ �������): ";
	cin >> n >> m;
	if (n == 0 || m == 0) {
		cout << "�������� ������ �������" << endl;
		CInput(game);
	}

	cout << "������� �������:" << endl;
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
	cout << "������� ��� �����:" << endl;
	cin >> fileName;

	ifstream file{ fileName };
	if (!file) {
		cout << "��������� ������� ���� ��� ������" << endl;
		return false;
	}
	while (file) {
		file >> n >> m;

		if (n == 0 || m == 0) {
			cout << "�������� ������ �������" << endl;
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
		cout << "������� �������� ������� �������" << endl;
		return false;
	}
	return true;
}