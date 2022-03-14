#include <iostream>
using namespace std;

int Len = 5, Mas[5];

class Sort
{
public:
    int BubbleSort()
    {
        _asm
        {
            dec Len;
        CycleExt:
            xor ebx, ebx;
            mov ecx, Len;
            mov esi, 0;
        CycleIn:
            mov edi, Mas[esi];
            cmp edi, Mas[esi + 4];
            jg Exchange;
            add esi, 4;
            loop CycleIn;
            jmp Check;
        Exchange:
            mov ebx, Mas[esi + 4];
            mov Mas[esi + 4], edi;
            mov Mas[esi], ebx;
            add esi, 4;
            loop CycleIn;
        Check:
            cmp ebx, 0;
            je Exit;
            jmp CycleExt;
        Exit:

        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Sort numbers;
    
    cout << "Пузырьковая сортировка по возрастанию" << endl;
    cout << "Кол-во элементов массива: " << Len << endl;
    for (int i = 0; i < Len; i++)
    {
        cout << "Mas[" << i + 1 << "]: ";
        cin >> Mas[i];
    };

    numbers.BubbleSort();
    Len = 5;
    cout << "Отсортированный массив:\n";
    for (int i = 0; i < Len; i++)
        cout << "Mas[" << i + 1 << "]: " << Mas[i] << endl;

    system("pause");
    return 0;
};


