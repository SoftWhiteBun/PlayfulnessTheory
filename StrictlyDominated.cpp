#include "StrictlyDominated.h"

vector<vector<float>>StrictlyDominated1(vector<vector<float>>& game) {
	vector<vector<float>> dop = game;
	int n = game.size();
	int m = game[n - 1].size();
	auto iter = dop.cbegin();
	int chet1, chet2;

	for (int k = 0; k < n - 1; k++) {

		for (int i = k + 1; i < n; i++) {
			chet1 = 0;
			chet2 = 0;
			for (int j = 0; j < m; j++) {
				if (dop[k][j] < dop[i][j])
					chet1++;
				if (dop[k][j] > dop[i][j])
					chet2++;

			}
			if (chet1 == m) {
				advance(iter, k);
				dop.erase(iter);
					int n = dop.size();
			}
			if (chet2 == m) {
				advance(iter, i);
				dop.erase(iter);
					int n = dop.size();
			}
		}
	}
	return dop;
}

vector<vector<float>> StrictlyDominated2(vector<vector<float>>& game) {
	vector<vector<float>> dop = game;
	int n = game.size();
	int m = game[n - 1].size();
	auto iter = dop.cbegin();
	int chet1, chet2;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dop[i][j] = -1 * dop[i][j];
		}
	}


	for (int k = 0; k < n - 1; k++) {

		for (int i = k + 1; i < n; i++) {
			chet1 = 0;
			chet2 = 0;
			for (int j = 0; j < m; j++) {
				if (dop[k][j] < dop[i][j])
					chet1++;
				if (dop[k][j] > dop[i][j])
					chet2++;

			}
			if (chet1 == m) {
				for (int l = 0; l < m; l++) {
					advance(iter, k);
					dop.erase(iter);
				}
				
				int n = dop.size();
			}
			if (chet2 == m) {
				advance(iter, i);
				dop.erase(iter);
				int n = dop.size();
			}
		}
	}
	return dop;
}
