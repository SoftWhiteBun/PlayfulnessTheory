#include <iostream>
#include "UserInteraction.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    bool flgInteract, flgBimatrix;
	vector<vector<pair<float, float>>> Bgame;
	vector<vector<float>> Mgame;
	bool ExitApp = false;

	while (!MatrixType(flgBimatrix));
	while (!ExitApp) {
		string UInp;
;
		if (!flgBimatrix) {
			cout << "Для выбора действия введите: " << endl;
			cout << "c - ввод и вывод данных через консоль;" << endl;
			cout << "f - ввод и вывод данных через файл" << endl;
			// другие действия с матричной моделью

			cin >> UInp;
			if (UInp == "c") {
				flgInteract = true;;
				while (!CInput(flgBimatrix, Mgame));

				//std::cout << "Введите действие: " << std::endl;
				//MainMenu(flgBimatrix, flgInteract, game);
				continue;
			}
			if (UInp == "f") {
				flgInteract = false;
				while (!FInput(flgBimatrix, Mgame));
				continue;
			}

		}
		//---------------------------------------------------------------------
		else {
			cout << "Меню для биматрицы" << endl;
		}
	}

	

    return 0;
}


