#include <iostream>

using namespace std;


class AsmChill
{
public:
    int Add(int a, int b)
    {
        int c = 0;
        _asm
        {
            mov eax, a
            add eax, b
            mov c, eax
        }
        return c;
    }
    int Sub(int a, int b)
    {
        int c = 0;
        _asm
        {
            mov eax, a
            Sub eax, b
            mov c, eax
        }
        return c;
    }
    int Imul(int a, int b)
    {
        int c;
        _asm
        {
            mov eax, a
            mul b
            mov c, eax
        }
        return c;
    }
    int Idiv(int a, int b)
    {
        int c;
        _asm
        {
            mov eax, a
            mov edx, 0
            mov ebx, b
            idiv ebx
            mov c, eax
        }
        return c;
    }

    int moreThan(int a, int b)
    {
        int c;
        _asm
        {
            mov eax, a
            mov ebx, b
            mov edx, 1
            cmp eax, ebx
            ja above
            mov edx, 0
            above:
            mov c, edx
        }
        return c;
    }
    int moreThanEqual(int a, int b)
    {
        int c;
        _asm
        {
            mov eax, a
            mov ebx, b
            mov edx, 1
            cmp eax, ebx
            jae abeq
            mov edx, 0
            abeq:
            mov c, edx
        }
        return c;
    }
    int lessThan(int a, int b)
    {
        int c;
        _asm
        {
            mov eax, a
            mov ebx, b
            mov edx, 1
            cmp eax, ebx
            jb below
            mov edx, 0
            below:
            mov c, edx
        }
        return c;
    }
    int lessThanEqual(int a, int b)
    {
        int c;
        _asm
        {
            mov eax, a
            mov ebx, b
            mov edx, 1
            cmp eax, ebx
            jbe beeq
            mov edx, 0
            beeq:
            mov c, edx
        }
        return c;
    }
    int equal(int a, int b)
    {
        int c;
        _asm
        {
            mov eax, a
            mov ebx, b
            mov edx, 1
            cmp eax, ebx
            je equ
            mov edx, 0
            equ:
            mov c, edx
        }
        return c;
    }
    int notEqual(int a, int b)
    {
        int c;
        _asm
        {
            mov eax, a
            mov ebx, b
            mov edx, 1
            cmp eax, ebx
            jne nequ
            mov edx, 0
            nequ:
            mov c, edx
        }
        return c;
    }

    int comparisonOperations(int a, int b)
    {
        int c;
        _asm
        {
            mov eax, a
            mov ebx, b
            mov ecx, 1
            mov edx, 0
            cmp eax, ebx
            ja above
            jb below
            je equa
            above :
            mov c, 1
                cmp ecx, edx
                ja endd
                below :
            mov c, 0
                cmp ecx, edx
                ja endd
                equa :
            mov c, 2
                endd :
        }
        return c;
    }

    int Not(int a)
    {
        int c;
        _asm
        {
            mov eax, a
            not eax
            mov c, eax
        }
        return c;
    }
    int And(int a, int b)
    {
        int c;
        _asm
        {
            mov eax, a
            mov ebx, b
            and eax, ebx
            mov c, eax
        }
        return c;
    }
    int Or(int a, int b)
    {
        int c;
        _asm
        {
            mov eax, a
            mov ebx, b
            or eax, ebx
            mov c, eax
        }
        return c;
    }
    int Xor(int a, int b)
    {
        int c;
        _asm
        {
            mov eax, a
            mov ebx, b
            xor eax, ebx
            mov c, eax
        }
        return c;
    }

    int arrayIndex(int* a, int b)
    {
        int c;
        _asm
        {
            mov eax, a
            mov ebx, b
            mov ebx, [eax + 4 * ebx]
            mov c, ebx
        }
        return c;
    }

    int logicRight(int a, int b)
    {
        int c;
        _asm
        {
            mov eax, a
            mov ecx, b
            shr eax, cl
            mov c, eax
        }
        return c;
    }
    int logicLeft(unsigned char a, unsigned char b)
    {
        unsigned char c;

        _asm
        {
            mov al, a
            mov cl, b
            shl al, cl
            mov c, al
        }
        return c;
    }

    int cicleRight(unsigned char a, unsigned char b)
    {
        unsigned char c;

        _asm
        {
            mov al, a
            mov cl, b
            ror al, cl
            mov c, al
        }
        return c;
    }
    int cicleLeft(unsigned char a, unsigned char b)
    {
        unsigned char c;

        _asm
        {
            mov al, a
            mov cl, b
            rol al, cl
            mov c, al
        }
        return c;
    }
};

int main()
{
    AsmChill obj;
    cout << "sum 67 + 48 = " << obj.Add(67, 48) << "\n";                        // сложение
    cout << "difference 100 - 97 = " << obj.Sub(100, 97) << "\n";               // вычитание
    cout << "multiplication 21 * 22 = " << obj.Imul(21, 22) << "\n";            // умножение
    cout << "division 506 / 5 = " << obj.Idiv(506, 5) << "\n\n";                // деление

    cout << "we gonna check comparison operations,\nif it's true we gonna write '1' or '0' if it's not:\n";
    cout << "check 20 > 5: " << obj.moreThan(20, 5) << "\n";                    // больше
    cout << "check 49 >= 49: " << obj.moreThanEqual(49, 49) << "\n";            // больше или равно
    cout << "check 38 < 9: " << obj.lessThan(38, 9) << "\n";                    // меньше
    cout << "check 50 <= 50: " << obj.lessThanEqual(50, 50) << "\n";            // меньше или равно
    cout << "check 99 = 99: " << obj.equal(99, 99) << "\n";                     // равно
    cout << "check 99 != 99: " << obj.notEqual(99, 99) << "\n\n";               // не равно

    cout << "check 100 and 20: " << obj.comparisonOperations(100, 100) << endl << endl; // сравнение больше(1), меньше(0) или равно(2)

    cout << "not 59 is -60? " << obj.Not(59) << endl;                           // не
    cout << "59 and 15 is 11: " << obj.And(59, 15) << endl;                     // и
    cout << "59 or 15 is 63: " << obj.Or(59, 15) << endl;                       // или
    cout << "59 xor 15 is 52: " << obj.Xor(59, 15) << endl << endl;             // исключающее или

    int a[] = { 0, 10, 20, 30, 40, 50, 60 };
    // индексация массива парметры (массив, индекс искомого элемента)


    cout << "3rd position in { 0, 10, 20, 30, 40, 50, 60 } is for number: " << obj.arrayIndex(a, 3) << endl << endl;

    // беззнаковый переход или инт хз
    cout << "logic shift right (150 (10010110) on 2 pos is 37 (00100101)): " << obj.logicRight(150, 2) << endl;  // логический сдвиг вправо
    cout << "logic shift left (150 (10010110) on 2 pos is 88 (01011000)): " << obj.logicLeft(150, 2) << endl;    // логический сдвиг влево

    cout << "cicle shift right (150 (10010110) on 2 pos is 165 (10100101)): " << obj.cicleRight(150, 2) << endl; // циклический сдвиг вправо
    cout << "cicle shift left (150 (10010110) on 2 pos is 90 (01011010)): " << obj.cicleLeft(150, 2) << endl;    // Циклический сдвиг влево
}