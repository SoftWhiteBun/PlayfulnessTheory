#include "cassert"
#include <iostream>
#include <locale.h>
#include "Output.h"
#include "UserInteraction.h"
#include "MaxMin.h"
#include "StrictlyDominated.h"
#include "WeaklyDominated.h"
#include "NBA.h"

using namespace std;


void Alltests()
{
	// Строгая доминация для 1 чела
	vector<vector<float>> myvect0 = { {0, 1}, {1, 0} };
	vector<vector<float>> myvect1 = { {0, 1}, {1, 0} };
	assert(StrictlyDominated1(myvect0) == myvect1);

	myvect0 = { {0, 1, 2}, {2, 5, 4} };
	myvect1 = { {2, 5, 4} };
	assert(StrictlyDominated1(myvect0) == myvect1);

	myvect0 = { {0, 1, 2}, {2, 5, 4}, {6, 7, 8} };
	myvect1 = { {6, 7, 8} };
	assert(StrictlyDominated1(myvect0) == myvect1);

	myvect0 = { {2, 9, 10}, {0, 1, 2}, {2, 5, 4}, {6, 7, 8} };
	myvect1 = { {2, 9, 10}, {6, 7, 8} };
	assert(StrictlyDominated1(myvect0) == myvect1);

	myvect0 = { {} };
	myvect1 = { {} };
	assert(StrictlyDominated1(myvect0) == myvect1);

	myvect0 = { {2, 9, 10}, {2, 9, 11} };
	myvect1 = { {2, 9, 10}, {2, 9, 11} };
	assert(StrictlyDominated1(myvect0) == myvect1);

	myvect0 = { {1, 2, 3}, {2, 9, 10}, {2, 9, 11}, {0, 0, 1} };
	myvect1 = { {2, 9, 10}, {2, 9, 11} };
	assert(StrictlyDominated1(myvect0) == myvect1);

	//myvect0 = { {0, 1, 2},
	//			{2, 5, 4} };

	//myvect1 = { {0, -1, -2} };
	//assert(StrictlyDominated2(myvect0) == myvect1);

	cout << "Тесты прошли успешно, всё заебись!";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	bool flgInteract, flgBimatrix;
	vector<vector<pair<float, float>>> Bgame;
	vector<vector<float>> Mgame;
	Bgame.clear(); Mgame.clear();
	bool ExitApp = false;

//	Alltests();

	//while (!MatrixType(flgBimatrix));
	while (!ExitApp) {

		string UInp;

		cout << endl;
		cout << "Для выбора действия введите: " << endl;
		cout << "c - ввод матрицы через консоль" << endl;
		cout << "f - ввод матрицы через файл" << endl;
		cout << "g - сгенерировать ланные" << endl;
		cout << "m - получить максимин и минимакс" << endl;
		cout << "d - удалить строго доминируемые стратегии" << endl;
		cout << "w - удалить слабо доминируемые стратегии" << endl;
		cout << "n - удалить слабо доминируемые стратегии" << endl;
		cout << "cc - вывод матрицы в консоль" << endl;
		cout << "ff - вывод матрицы в файл" << endl;
		// другие действия с матричной моделью
		cout << "h - помощь" << endl;
		cout << "е - выход" << endl;
		cout << endl;

		cin >> UInp;
		if (UInp == "c") {
			flgInteract = true;
			CInput(flgBimatrix, Mgame);
			continue;
		}
		if (UInp == "f") {
			flgInteract = false;
			Help(HFInput);
			FInput(flgBimatrix, Mgame);
			continue;
		}

		if (UInp == "g") {
			flgInteract = true;;
			GInput(flgBimatrix, Mgame);
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
			cout << "Индекс: [ " << (maxmin.first + 1) << " , " << (maxmin.second + 1) << " ]" << endl;
			cout << "Значение: " << Mgame[maxmin.first][maxmin.second] << endl << endl;

			cout << "Минимакс:" << endl;
			cout << "Индекс: [ " << (minmax.first + 1) << " , " << (minmax.second + 1) << " ]" << endl;
			cout << "Значение: " << Mgame[minmax.first][minmax.second] << endl << endl;
			cout << "Введите i - для вывода информации об алгоритме; любой другой символ - для возврата в меню: ";
			string input;
			cin >> input;
			if (input == "i") Help(HMaxMin);
		}

		if (UInp == "d") {
			if (Mgame.size() == 0) {
				cout << "Матрица не введена" << endl;
				continue;
			}
			cout << "Введите 1 - для выбора первого игрока; 2 - для второго: ";
			string player;
			cin >> player;
			if (player == "1") OutDomin(Mgame, StrictlyDominated1);
			else if (player == "2") OutDomin(Mgame, StrictlyDominated2);
			else {
				cout << "Введен некорректный номер игрока" << endl;
				continue;
			}
			cout << "Введите i - для вывода информации об алгоритме; любой другой символ - для возврата в меню: ";
			string input;
			cin >> input;
			if (input == "i") Help(HSDomin);
		}

		if (UInp == "w") {
			if (Mgame.size() == 0) {
				cout << "Матрица не введена" << endl;
				continue;
			}
			cout << "Введите 1 - для выбора первого игрока; 2 - для второго: ";
			string player;
			cin >> player;
			if (player == "1") OutDomin(Mgame, WeaklyDominated1); // Weak
			else if (player == "2") OutDomin(Mgame, WeaklyDominated2); // Weak
			else {
				cout << "Введен некорректный номер игрока" << endl;
				continue;
			}
			cout << "Введите i - для вывода информации об алгоритме; любой другой символ - для возврата в меню: ";
			string input;
			cin >> input;
			if (input == "i") Help(HWDomin);
		}

		if (UInp == "n") {
			if (Mgame.size() == 0) {
				cout << "Матрица не введена" << endl;
				continue;
			}
			cout << "Введите 1 - для выбора первого игрока; 2 - для второго: ";
			string player;
			cin >> player;
			if (player == "1") OutDomin(Mgame, NBA1);
			else if (player == "2") OutDomin(Mgame, NBA2);
			else {
				cout << "Введен некорректный номер игрока" << endl;
				continue;
			}
			cout << "Введите i - для вывода информации об алгоритме; любой другой символ - для возврата в меню: ";
			string input;
			cin >> input;
			if (input == "i") Help(HSDomin);
		}


		if (UInp == "cc") {
			COutput(Mgame);
		}
		if (UInp == "ff") {
			FOutput(Mgame);
		}

		if (UInp == "h") {
			Help(HMaxMin);
			Help(HSDomin);
			Help(HWDomin);
			//Help(HNLO);
			Help(HFInput);
		}

		if (UInp == "e") {
			ExitApp = true;
		}

	}



	return 0;
}
