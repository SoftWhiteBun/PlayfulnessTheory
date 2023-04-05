#include "NBA.h"

vector<vector<float>>NBA1(vector<vector<float>>& game) {
	vector<vector<float>> dop = game;
	vector<int> index;
	int n = game.size();
	int m = game[n - 1].size();
	auto iter = dop.cbegin();
	int chet1, chet2;

	for (int k = 0; k < n - 1; k++) {

		for (int i = k + 1; i < n; i++) {
			chet1 = 0;
			chet2 = 0;
			for (int j = 0; j < m; j++) {

				if (game[k][j] < game[i][j]) {
					chet1++;
				}
				if (game[k][j] > game[i][j]) {
					chet2++;
				}
			}
			if (chet1 != 0 and chet2 !=0) {
				if (!count(index.begin(), index.end(), k))
					index.push_back(k);	//добавл€ем индексы тех строк, которые надо удалить
			}

		}

	}

	int sizeIndex = index.size();
	if (sizeIndex > 0) {
		sort(index.begin(), index.end());
		for (int i = sizeIndex - 1; i >= 0; i--) {
			iter = dop.cbegin() + index[i];
			dop.erase(iter);
		}
	}

	if (dop.size() == game.size()) {
		cout << "ЌЋќ стратегий не обнаружено" << endl;
		dop.clear();
	}

	return dop;
}

vector<vector<float>> NBA2(vector<vector<float>>& game) {
	vector<vector<float>> dop = game;
	vector<int> index;
	int n = game.size();
	int m = game[n - 1].size();
	auto iter = dop[0].cbegin();
	int chet1, chet2;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dop[i][j] = -1 * dop[i][j];
		}
	}


	for (int k = 0; k < m - 1; k++) {

		for (int i = k + 1; i < m; i++) {
			chet1 = 0;
			chet2 = 0;
			for (int j = 0; j < n; j++) {

				if (dop[j][k] < dop[j][i]) {
					chet1++;
				}
				if (dop[j][k] > dop[j][i]) {
					chet2++;
				}
			}
			if (chet1 != 0 and chet2 != 0) {
				if (!count(index.begin(), index.end(), k))
					index.push_back(k);	//добавл€ем индексы тех строк, которые надо удалить
			}
		}

	}

	int sizeIndex = index.size();
	if (sizeIndex > 0) {
		sort(index.begin(), index.end());
		for (int i = sizeIndex - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				iter = dop[j].cbegin() + index[i];
				//dop.erase(iter);		//тут крашитс€
				dop[j].erase(iter);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < dop[n - 1].size(); j++) {
			dop[i][j] = -1 * dop[i][j];
		}
	}

	if (dop[n - 1].size() == game[n - 1].size()) {
		cout << "—трого доминируемых стратегий не обнаружено" << endl;
		dop.clear();
	}

	return dop;
}


