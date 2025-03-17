#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Rhombus {
private:
	double side;    
	double diagonal;
	string color; 

public:
	// Конструктори
	Rhombus() : side(1.0), diagonal(sqrt(2)), color("white") {} // Конструктор за замовчуванням
	Rhombus(double s, double d, string c) { // Конструктор з параметрами
		setSide(s);
		setDiagonal(d);
		setColor(c);
	}

	// Методи встановлення значень
	void setSide(double s) {
		if (s > 0 && s < 1.e+100) {
			side = s;
		}
		else {
			cout << "Error: Invalid side value (" << s << "). Must be between 0 and 1.e+100.\n";
		}
	}

	void setDiagonal(double d) {
		if (d > 0 && d < 2 * side) {
			diagonal = d;
		}
		else {
			cout << "Error: Invalid diagonal value (" << d << "). Must be positive and smaller than twice the side length ("
				<< 2 * side << ").\n";
		}
	}

	void setColor(string c) {
		color = c;
	}

	// Методи отримання значень (гетери)
	double getSide() const { return side; }
	double getDiagonal() const { return diagonal; }
	string getColor() const { return color; }

	// Обчислення площі та периметру
	double area() const {
		return (diagonal * diagonal) / 2;
	}

	double perimeter() const {
		return 4 * side;
	}

	// Функція друку (використовує гетери для отримання значень)
	void printInfo() const {
		cout << "\nSide: " << getSide() << ", Diagonal: " << getDiagonal() << ", Color: " << getColor();
		cout << ", Area: " << area() << ", Perimeter: " << perimeter() << endl;
	}
};

int mainExample1() {
	// Тестування класу
	Rhombus obj1; // Використання конструктора за замовчуванням
	obj1.printInfo();

	Rhombus obj2(3.0, 4.0, "blue"); // Використання конструктора з параметрами
	obj2.printInfo();
	obj1.setSide(2.5);
	obj1.setDiagonal(3.5);
	obj1.setColor("red");
	obj1.printInfo();

	// Спроба встановлення некоректних значень
	obj1.setSide(-1.0);
	obj1.setDiagonal(10.0);
	obj1.printInfo();

	// Отримання значень через методи доступу
	cout << "\nTesting get methods:\n";
	cout << "Side: " << obj2.getSide() << ", Diagonal: " << obj2.getDiagonal()
		<< ", Color: " << obj2.getColor() << endl;

	cout << "End testing\n";
	return 0;
}
