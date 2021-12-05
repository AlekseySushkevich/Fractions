#include <iostream>
#include "Fraction.h"
using namespace std;

void enterFraction(Fraction& fr1) {
    cout << "Ввод числителя и знаменателя предполагается через '/'(иначе ответ будет неверным)." << endl << "Введите дробь: ";
    cin >> fr1;
}

int main() {
    setlocale(0, "");
    cout << "Введите номер операции:" << endl;
    cout << "(1) - Операции сравнения дробей." << endl;
    cout << "(2) - Арифметические операции." << endl;
    cout << "(3) - Операции изменения знака." << endl;
    cout << "> ";
    Fraction fr1, fr2, result;
    char op;
    bool f = true;
    cin >> op;
    system("cls");
    switch (op) {
    case '1':
        enterFraction(fr1);
        cout << "Введите 2ую дробь: "; cin >> fr2;
        fr1.Сomparison(fr1, fr2);
        break;
    case '2':
        enterFraction(fr1);
        cout << "Введите 2ую дробь: "; cin >> fr2;
        cout << "Введите знак операции: "; cin >> op;
        switch (op) {
        case '+':
            result = fr1 + fr2;
            break;
        case '-':
            result = fr1 - fr2;
            break;
        case '*':
            result = fr1 * fr2;
            break;
        case '/':
            result = fr1 / fr2;
            break;
        default:
            cout << "Неизвестная операция." << endl;
            f = false;
        }
        if (f)
            cout << "Результат: " << result << endl;
        break;
    case '3': 
        enterFraction(fr1);
        fr1.signChange();
        cout << "Новая дробь: " << fr1;
        break;
    default: 
        cout << "Неизвестная операция." << endl;
    }
}
