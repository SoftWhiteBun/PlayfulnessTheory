// PlaufullnessTheory.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "cassert"
#include <iostream>
#include <locale.h>
#include "Output.h"
#include "UserInteraction.h"
#include "MaxMin.h"
#include "StrictlyDominated.h"

using namespace std;

void Alltests()
{
	vector<vector<float>> myvect0 = { {0, 1}, {1, 0} };
	vector<vector<float>> myvect1 = { {0, 1}, {1, 0} };
	assert(StrictlyDominated1(myvect0) == myvect1);

	myvect0 = { {0, 1, 2}, {2, 5, 4} };
	myvect1 = { {2, 5, 4}, {} };
	assert(StrictlyDominated1(myvect0) == myvect1);

	cout << "Тесты прошли успешно, всё заебись!";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	bool flgInteract, flgBimatrix;
	vector<vector<pair<float, float>>> Bgame;
	vector<vector<float>> Mgame;
	bool ExitApp = false;

	Alltests();

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
			cout << "d - удалить строго доминируемые ходы" << endl;
			cout << "cc - вывод матрицы в консоль" << endl;
			cout << "ff - вывод матрицы в консоль" << endl;
			// другие действия с матричной моделью
			cout << "е - выход" << endl;
			cout << endl;

			cin >> UInp;
			if (UInp == "c") {
				flgInteract = true;;
				//while (!CInput(flgBimatrix, Mgame));
				CInput(flgBimatrix, Mgame);
				//std::cout << "Введите действие: " << std::endl;
				//MainMenu(flgBimatrix, flgInteract, game);
				continue;
			}
			if (UInp == "f") {
				flgInteract = false;
				//while (!FInput(flgBimatrix, Mgame));
				FInput(flgBimatrix, Mgame);
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
			if (UInp == "d") {
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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
