#include <iostream>
#include <vector>
using namespace std;

int bordercheck(int a, int b, int c) { //проверка ограничений
    if (c > a || a > b) {
        for (; 0 > a || a > b;) {
            cout << "Недопустимое значение!" << endl;
            cout << "Введите число заново:" << endl;
            cin >> a;
        }
    }
    return a;
}

int typecheck() { //проверка на тип
    int a;
    for (;;) {
        cin >> a;
        if (cin.good()) {
            cin.ignore(10, '\n');
            return a;
        }
        else {
            cin.clear();
            cout << "Недопустимый тип данных! Введие число заново:" << endl;
            cin.ignore(10, '\n');
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, y, d, q, x, chislo, schet = 100000;
    int* b;
    b = new int (schet);
    cout << "Введите необходимое количество строк:" << endl;
    n = typecheck();
    n = bordercheck(n, 20000, 0);
    vector <vector <int>> arr(n);
    vector <vector <int>>::iterator it = arr.begin();
    for (int i = 0; i < n; i++) {
        cout << "Введите необходимое количество чисел в строке: " << i + 1 << endl;
        d = typecheck();
        d = bordercheck(d, 50000, -1);
        if (d <= *b) {
            it[i].resize(d);
            *b -= d;
        }
        else {
            cout << "Превышено общее количество чисел" << endl;
            cout << "Введите число для продолжение:" << endl;
            cout << "2 - для изменения количества чисел в строке: " << i + 1 << endl;
            cout << "1 - для выхода" << endl;
            int a = typecheck();
            a = bordercheck(a, 2, -1);
            switch (a)
            {
            case 2:
                cout << "Введите необходимое количество чисел в строке: " << i + 1 << endl;
                d = typecheck();
                d = bordercheck(d, 50000, -1);
                if (d <= *b) {
                    it[i].resize(d);
                }
            case 1:
                if (*b < 100000) {
                    continue;
                }
                else {
                    cout << "В строках нет чисел и запросы невозможны";
                    exit(0);
                }
            }
        }
        
        if (d != 0) {
            cout << "Введите числа для сроки: " << i + 1 << endl;
            for (int j = 0; j < d; j++) {
                for (;;) {
                    cin >> chislo;
                    if (cin) {
                        it[i][j] = chislo;
                        cin.clear();
                        break;
                    }
                    else {
                        cin.clear();
                        cout << "Недопустимый тип данных! Введие число(а) заново:" << endl;
                        cin.ignore(10, '\n');
                    }
                }
            }
        }
    }
    cout << "Введите необходимое количество запросов:" << endl;
    q = typecheck();
    q = bordercheck(q, 1000, 0);
    for (int l = 0; l < q; l++) {
        cout << "Введите номер необходимой строки и номер необходимой позиции:" << endl;
        for (;;) {
            cin >> x >> y;
            if (cin) {
                cin.clear();
                break;
            }
            else {
                cin.clear();
                cout << "Недопустимый тип данных! Введие числа заново:" << endl;
                cin.ignore(10, '\n');
            }
        }
        if (x - 1 <= n) {
            try {
                cout << "arr = " << arr.at(x - 1).at(y - 1) << endl;
            }
            catch (int i) {
                cout << "ОШИБКА!" << endl;
            }
            catch (...) {
                cout << "ОШИБКА!" << endl;
            }
        }
        else cout << "ОШИБКА!" << endl;
    }
    return 0;
}
