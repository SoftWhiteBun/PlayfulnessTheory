#include "cassert"
#include <iostream>
#include <locale.h>
#include "Output.h"
#include "UserInteraction.h"
#include "MaxMin.h"
#include "StrictlyDominated.h"

using namespace std;


//void Alltests()
//{
//	vector<vector<float>> myvect0 = { {0, 1}, {1, 0} };
//	vector<vector<float>> myvect1 = { {0, 1}, {1, 0} };
//	assert(StrictlyDominated1(myvect0) == myvect1);
//
//	myvect0 = { {0, 1, 2}, {2, 5, 4} };
//	myvect1 = { {2, 5, 4}, {} };
//	assert(StrictlyDominated1(myvect0) == myvect1);
//
//	cout << "Тесты прошли успешно, всё заебись!";
//}

int main()
{
	setlocale(LC_ALL, "Russian");
	bool flgInteract, flgBimatrix;
	vector<vector<pair<float, float>>> Bgame;
	vector<vector<float>> Mgame;
	Bgame.clear(); Mgame.clear();
	bool ExitApp = false;

//	Alltests();

	while (!MatrixType(flgBimatrix));
	while (!ExitApp) {
		string UInp;
		;
		if (!flgBimatrix) {
			cout << endl;
			cout << "Для выбора действия введите: " << endl;
			cout << "c - ввод матрицы через консоль" << endl;
			cout << "f - ввод матрицы через файл" << endl;
			cout << "m - получить максимин и минимакс" << endl;
			cout << "d - удалить строго доминируемые стратегии" << endl;
			cout << "w - удалить слабо доминируемые стратегии" << endl;
			cout << "cc - вывод матрицы в консоль" << endl;
			cout << "ff - вывод матрицы в файл" << endl;
			// другие действия с матричной моделью
			cout << "е - выход" << endl;
			cout << endl;

			cin >> UInp;
			if (UInp == "c") {
				flgInteract = true;;
				//while (!CInput(flgBimatrix, Mgame));
				CInput(flgBimatrix, Mgame);
				continue;
			}
			if (UInp == "f") {
				flgInteract = false;
				//while (!FInput(flgBimatrix, Mgame));
				FInput(flgBimatrix, Mgame);
				continue;
			}
			if (UInp == "m") {
				if (Mgame.size() == 0) {
					cout << "Матрица не введена" << endl;
					continue;
				}
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
			if (UInp == "d") {
				if (Mgame.size() == 0) {
					cout << "Матрица не введена" << endl;
					continue;
				}
				vector<vector<float>> Strictly = StrictlyDominated1(Mgame);	//для первого игрока
				vector<vector<float>> Strictly2 = StrictlyDominated2(Mgame);	//для второго игрока
				COutput(Strictly);		//ТУТ ДОБАВИТЬ ВЫБОР ДЛЯ КАКОГО ИГРОКА УДАЛЯТЬ СТРАТЕГИИ, АНАЛОГИЧНО СДЕЛАТЬ ДЛЯ СЛАБО ДОМИНИРУМЫХ

			}

			if (UInp == "w") {
				if (Mgame.size() == 0) {
					cout << "Матрица не введена" << endl;
					continue;
				}
				vector<vector<float>> Strictly = StrictlyDominated1(Mgame);
				COutput(Strictly);
			}


			if (UInp == "cc") {
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
