#include <iostream>
using namespace std;

class Elevator {
private:
    int nowFloor;
    int minFloor;
    int maxFloor;
    bool work;

public:
    Elevator(int l, int u, int cur, bool w) {
        minFloor = l;
        maxFloor = u;
        nowFloor = cur;
        work = w;
    }

    void SetMinFloor(int l) { minFloor = l; }
    void SetMaxFloor(int u) { maxFloor = u; }

    void SetNowFloor(int f) {
        if (f >= minFloor && f <= maxFloor) {
            nowFloor = f;
        } else {
            cout << "Этаж " << f << " не подходит, вне диапазона." << endl;
        }
    }

    void SetWork(bool w) { work = w; }
    bool GetWork() const { return work; }
    int GetNowFloor() const { return nowFloor; }

    void SetRange(int l, int u) {
        if (l > u) {
            cout << "Ошибка: нижний этаж больше верхнего." << endl;
            return;
        }
        SetMinFloor(l);
        SetMaxFloor(u);
        cout << "Теперь лифт работает от " << minFloor << " до " << maxFloor << " этажа." << endl;
    }

    void On() {
        if (!work) {
            work = true;
            cout << "Лифт запущен." << endl;
        } else {
            cout << "Лифт уже работает." << endl;
        }
    }

    void Off() {
        if (work) {
            work = false;
            cout << "Лифт остановлен." << endl;
        } else {
            cout << "Лифт уже выключен." << endl;
        }
    }

    void Call(int f) {
        if (!work) {
            cout << "Лифт выключен. Вызов невозможен." << endl;
            return;
        }
        if (f == nowFloor) {
            cout << "Лифт уже стоит на " << f << " этаже." << endl;
            return;
        }
        cout << "Лифт едет с " << nowFloor << " на " << f << " этаж..." << endl;
        SetNowFloor(f);
        cout << "Приехал на " << nowFloor << " этаж." << endl;
    }
};

int main() {
    Elevator e(1, 10, 1, true);

    cout << "Лифт сейчас на " << e.GetNowFloor() << " этаже." << endl;
    cout << "Состояние: " << (e.GetWork() ? "работает" : "выключен") << endl;

    cout << "\nВызов лифта:" << endl;
    e.Call(4);

    cout << "\nПитание:" << endl;
    e.Off();
    e.Call(2);

    cout << "\nНовый диапазон:" << endl;
    e.SetRange(1, 12);
    e.Call(9);
}
