#include <iostream>
#include <locale.h>

#include "UserInteraction.h"
#include "MaxMin.h"
#include "Output.h"
//#include "Log.h"

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
			cout << "c - ввод матрицы через консоль" << endl;
			cout << "f - ввод матрицы через файл" << endl;
			cout << "m - получить максимин и минимакс" << endl;
			cout << "d - удалить строго доминируемые ходы" << endl;
			cout << "cc - вывод матрицы в консоль" << endl;
			cout << "ff - вывод матрицы в консоль" << endl;
			// другие действия с матричной моделью
			cout << "е - выход" << endl;
			cout << endl;
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
			if (UInp == "m") {
				pair<int, int> maxmin = MaxMin(Mgame);
				pair<int, int> minmax = MinMax(Mgame);
				cout << endl;
				cout << "Максимин:" << endl;
				cout << "Индекс: [ " << maxmin.first << " , " << maxmin.second << " ]" << endl;
				cout << "Значение: " << Mgame[maxmin.first][maxmin.second] << endl << endl;

				cout << "Минимакс:" << endl;
				cout << "Индекс: [ " << minmax.first << " , " << minmax.second << " ]" << endl;
				cout << "Значение: " << Mgame[minmax.first][minmax.second] << endl << endl;
			}
			if (UInp == "cc") {
				auto iter = Mgame.cbegin(); // указатель на первый элемент
				Mgame.erase(iter + 1);
				COutput(Mgame);
			}
			if (UInp == "ff") {
				FOutput(Mgame);
			}

			if (UInp == "e") {
				ExitApp = true;
			}


		}
		//---------------------------------------------------------------------
		else {
			cout << "Меню для биматрицы" << endl;
		}
	}

	

    return 0;
}


