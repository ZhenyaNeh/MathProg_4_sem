#include <iostream>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>

#include "Levenshtein.h"
#include "MultiMatrix.h"

using namespace std;

#define N 6
#define FIRST_LEN 300
#define SECOND_LEN 200

char* first_Task(int size) 
{
    char* str = new char[size];

    for (int i = 0; i < size; i++) 
        str[i] = rand() % 26 + 'a';

    return str;
}

//main
void second_Task(char* s1, char* s2)
{
	clock_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	int  lx = sizeof(s1) - 1, ly = sizeof(s2) - 1;

	cout << endl;
	cout << endl << "-- расстояние Левенштейна -----" << endl;
	cout << endl << "--длина --- рекурсия -- дин.програм. ---" << endl;

	int s1_Dist[]{ FIRST_LEN / 25, FIRST_LEN / 20, FIRST_LEN / 15, FIRST_LEN / 10, FIRST_LEN / 5, FIRST_LEN / 2, FIRST_LEN };
	int s2_Dist[]{ SECOND_LEN / 25, SECOND_LEN / 20, SECOND_LEN / 15, SECOND_LEN / 10, SECOND_LEN / 5, SECOND_LEN / 2, SECOND_LEN };

	for (int i = 0; i < min(lx, ly); i++)
	{
		t1 = clock();
		levenshtein_r(s1_Dist[i], s1, s2_Dist[i], s2);
		t2 = clock();

		t3 = clock();
		levenshtein(s1_Dist[i], s1, s2_Dist[i], s2);
		t4 = clock();

		cout << right << setw(2) << s2_Dist[i] << "/" << setw(2) << s1_Dist[i]
			<< "\t\t" << left << setw(10) << (t2 - t1)
			<< "\t" << setw(10) << (t4 - t3) << endl;
	}

	system("pause");
	return;
}

void fifth_Task() 
{
	setlocale(LC_ALL, "rus");

	clock_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	/*Mc[N + 1] = { 5,10,15,20,25,30,35 }*/
	int Mc[N + 1] = { 9,12,20,23,30,40,51 }, Ms[N][N], r = 0, rd = 0;

	memset(Ms, 0, sizeof(int) * N * N);

	t1 = clock();
	r = OptimalM(1, N, N, Mc, OPTIMALM_PARM(Ms));
	t2 = clock();

	cout << endl;
	cout << endl << "-- расстановка скобок (рекурсивное решение) " << endl;
	cout << endl << "размерности матриц: ";

	for (int i = 1; i <= N; i++)
		cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";

	cout << endl << "минимальное количество операций умножения: " << r;
	cout << endl << endl << "матрица S" << endl;

	for (int i = 0; i < N; i++)
	{
		cout << endl;
		for (int j = 0; j < N; j++)
			cout << Ms[i][j] << "  ";
	}

	cout << "\n\nИтоговое время выполнения Рекурсивного решения: " << (t2 - t1) << endl;
	cout << endl;

	memset(Ms, 0, sizeof(int) * N * N);

	t3 = clock();
	rd = OptimalMD(N, Mc, OPTIMALM_PARM(Ms));
	t4 = clock();

	cout << endl << "\n-- расстановка скобок (динамичеое программирование) " << endl;
	cout << endl << "размерности матриц: ";

	for (int i = 1; i <= N; i++)
		cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";

	cout << endl << "минимальное количество операций умножения: " << rd;
	cout << endl << endl << "матрица S" << endl;

	for (int i = 0; i < N; i++)
	{
		cout << endl;
		for (int j = 0; j < N; j++)
			cout << Ms[i][j] << "  ";
	}

	cout << "\n\nИтоговое время выполнения Динамического программирования: " << (t3 - t4) << endl;
	cout << endl << endl;

	system("pause");

	return;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	cout << "First string: \n";
	char* s1 = first_Task(FIRST_LEN);

	for (int i = 0; i < FIRST_LEN; i++) 
		cout << s1[i];

	cout << endl;

	cout << "\nSecond string: \n";
	char* s2 = first_Task(SECOND_LEN);

	for (int i = 0; i < SECOND_LEN; i++) 
		cout << s2[i];

	cout << endl << endl;

	second_Task(s1, s2);

	fifth_Task();

	system("pause");
	return 0;
}
