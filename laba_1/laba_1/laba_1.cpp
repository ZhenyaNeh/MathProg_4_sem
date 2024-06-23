#include "pch.h"
#include <iostream>
#include <vector>
//#include "Auxil.h"                            // вспомогательные функции 
//#include <iostream>
//#include <ctime>
//#include <locale>
//
//#define  CYCLE  1000000                       // количество циклов 

int fibonachi(int);

int main()
{
	double  av1 = 0, av2 = 0;
	clock_t  t1 = 0, t2 = 0;

	setlocale(LC_ALL, "rus");

	auxil::start(); 

	t1 = clock();                            
	for (int i = 0; i < CYCLE; i++)
	{
		av1 += (double)auxil::iget(-100, 100); 
		av2 += auxil::dget(-100, 100);         
	}
	t2 = clock();                            

	std::cout << std::endl << "количество циклов:         " << CYCLE;
	std::cout << std::endl << "среднее значение (int):    " << av1 / CYCLE;
	std::cout << std::endl << "среднее значение (double): " << av2 / CYCLE;
	std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
	std::cout << std::endl << "                  (сек):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl;

	///////////////////////////////////////////////--Task_3--/////////////////////////////////////////////////////////////

	t1 = 0, t2 = 0;

	t1 = clock();

	int checkNumber = 35;

	int result = fibonachi(checkNumber);

	t2 = clock();

	std::cout << std::endl << "количество циклов:         " << checkNumber;
	std::cout << std::endl << "результирующее значение:   " << result;
	std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
	std::cout << std::endl << "                  (сек):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl;
	system("pause");

	return 0;
}


int fibonachi(int number) 
{
	if (number <= 2)
		return 1;
	
	Sleep(0.01);
	return fibonachi(number - 1) + fibonachi(number - 2);
}