#include "stdafx.h"
#include <iostream>
#include "Combi.h"
#include "Knapsack.h"
#include "Auxil.h"
#include <ctime>

#define NN 18

int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");
    int V = 300,    // ����������� �������              
        v[NN],      // ������ �������� ������� ����  
        c[NN];      // ��������� �������� ������� ���� 
    short m[NN];    // ���������� ��������� ������� ����  {0,1}   

    auxil::start();

    for (int i = 0; i < NN; i++)
    {
        v[i] = auxil::iget(10, 300);
        c[i] = auxil::iget(5, 55);
    }

    clock_t  t1 = 0, t2 = 0;

    t1 = clock();

    int maxcc = knapsack_s(

        V,   // [in]  ����������� ������� 
        NN,  // [in]  ���������� ����� ��������� 
        v,   // [in]  ������ �������� ������� ����  
        c,   // [in]  ��������� �������� ������� ����     
        m    // [out] ���������� ��������� ������� ����  
    );

    t2 = clock();

    std::cout << std::endl << "-------- ������ � ������� --------- ";
    std::cout << std::endl << "- ���������� ��������� : " << NN;
    std::cout << std::endl << "- ����������� �������  : " << V;
    std::cout << std::endl << "- ������� ���������    : ";

    for (int i = 0; i < NN; i++) 
        std::cout << v[i] << " ";

    std::cout << std::endl << "- ��������� ���������  : ";

    for (int i = 0; i < NN; i++) 
        std::cout << v[i] * c[i] << " ";

    std::cout << std::endl << "- ����������� ��������� �������: " << maxcc;
    std::cout << std::endl << "- ��� �������: ";

    int s = 0;

    for (int i = 0; i < NN; i++)
        s += m[i] * v[i];

    std::cout << s;
    std::cout << std::endl << "- ������� ��������: ";

    for (int i = 0; i < NN; i++)
        std::cout << " " << m[i];

    std::cout << std::endl << std::endl;

    for (int i = 0; i < NN; i++)
        if (m[i] == 1) {
            std::cout << i + 1 << "-st �������\n";
            std::cout << "\t������: " << v[i] << std::endl;
            std::cout << "\t���: " << c[i] << std::endl << std::endl;
        }

    std::cout << std::endl << "����������������� (�.�):   " << (t2 - t1);
    std::cout << std::endl << "                  (���):   "
        << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
    std::cout << std::endl;

    system("pause");
    return 0;
}