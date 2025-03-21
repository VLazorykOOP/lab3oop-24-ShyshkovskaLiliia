#include <iostream>
#include <cmath>
using namespace std;

class Rhombus {
    double side;
    double diagonal1;
    double diagonal2;
    unsigned int color;

public:
    // Конструктори
    Rhombus() : side(1.0), diagonal1(sqrt(2)), diagonal2(sqrt(2)), color(0) {}
    explicit Rhombus(double s) : side(s), color(0) { updateDiagonals(); }
    explicit Rhombus(int c) : side(1.0), color((c >= 0 && c <= 10000) ? c : 0) { updateDiagonals(); }
    Rhombus(double s, double d1, double d2, int c) {
        setSide(s);
        setDiagonals(d1, d2);
        setColor(c);
    }

    // Встановлення значень
    void setSide(double s) {
        if (s > 0 && s < 1.e+100) {
            side = s;
            updateDiagonals();
        } else {
            cout << "Помилка: некоректне значення сторони!\n";
        }
    }

    void setDiagonals(double d1, double d2) {
        if (d1 > 0 && d2 > 0 && d1 < 1.e+100 && d2 < 1.e+100 && isValidDiagonals(d1, d2)) {
            diagonal1 = d1;
            diagonal2 = d2;
        } else {
            cout << "Помилка: некоректне значення діагоналей!\n";
        }
    }

    void setColor(int c) {
        if (c >= 0 && c <= 10000) {
            color = c;
        } else {
            cout << "Помилка: некоректне значення кольору!\n";
        }
    }

    // Отримання значень
    double getSide() const { return side; }
    double getDiagonal1() const { return diagonal1; }
    double getDiagonal2() const { return diagonal2; }
    unsigned int getColor() const { return color; }

    double area() const {
        return (diagonal1 * diagonal2) / 2;
    }

    double perimeter() const {
        return 4 * side;
    }

    void printInfo() const {
        cout << "\nРомб:";
        cout << "\nСторона: " << side;
        cout << "\nДіагоналі: " << diagonal1 << ", " << diagonal2;
        cout << "\nКолір: " << color;
        cout << "\nПлоща: " << area();
        cout << "\nПериметр: " << perimeter() << "\n";
    }

private:
    void updateDiagonals() {
        diagonal1 = diagonal2 = side * sqrt(2); // Оцінка для ромба зі сторонами та рівними діагоналями
    }

    bool isValidDiagonals(double d1, double d2) const {
        return (d1 * d1 + d2 * d2) / 4 == side * side;
    }
};

int main() {
    Rhombus obj;
    obj.printInfo();
    
    double in_side, in_diag1, in_diag2;
    int in_color;
    cout << "Введіть сторону, дві діагоналі та колір ромба: ";
    cin >> in_side >> in_diag1 >> in_diag2 >> in_color;
    
    Rhombus obj1(in_side), obj2(in_color), obj3(in_side, in_diag1, in_diag2, in_color);
    obj1.printInfo();
    obj2.printInfo();
    obj3.printInfo();
    
    // Тестування обмежень
    obj.setSide(-5);
    obj.setSide(5);
    obj.setSide(2.e100);
    
    obj.setColor(-10);
    obj.setColor(10);
    obj.setColor(10001);
    
    cout << "Тестування завершено.\n";
    return 0;
}
