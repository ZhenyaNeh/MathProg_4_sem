#include <iostream>
#include "Combi.h"
#include <tchar.h>

int main()
{
    setlocale(LC_ALL, "rus");
    char  AA[][2] = { "A", "B", "C", "D" };
    std::cout << "\t\t��������� ��������� ���� �����������" << std::endl;
    std::cout << "�������� ���������:\n\t";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA) / 2; i++)
    {
        std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
    }
    std::cout << "}" << std::endl;
    std::cout << "��������� ���� �����������:";
    combi::subset s1(sizeof(AA) / 2);     // �������� ����������  
    int  n = s1.getfirst();                // ������ (������) ������������
    while (n >= 0)                         // ���� ���� ������������ 
    {
        std::cout << std::endl << "{ ";
        for (int i = 0; i < n; i++)
            std::cout << AA[s1.ntx(i)] << ((i < n - 1) ? ", " : " ");
        std::cout << "}";
        n = s1.getnext();                  // c�������� ������������ 
    };
    std::cout << std::endl << "\t�����:: " << s1.count() << std::endl;
    system("pause");
    return 0;
}