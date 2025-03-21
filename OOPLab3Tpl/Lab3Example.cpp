#if !defined(_MSC_VER)
#define CODING_VS_CODE
#endif
#include <iostream>
#include <math.h>
#if !defined(CODING_VS_CODE)
	#include <clocale>
#endif
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

// Ключове слово static 

class foo
{
private:
	static int count; // загальне поле всім об'єктів
	// (У сенсі "оголошення")
public:
	foo() { incObj(); } // інкрементування під час створення об'єкта
	static int incObj() { return ++count; }
	int getcount() { return count; }
};
int  foo::count = 0;
// Ключове слово static ставиться перед типом способу.В основному використовуються
//для роботи зі статичними полями класу.

/*  Example 3
Створити тип даних - клас вектор, який має поля x, y та z типу float і змінну стану. У класі визначити
o	конструктор без параметрів(інінціалізує поля в нуль);
o	конструктор з одним параметром типу float (інінціалізує поля x, y та z значенням параметру);
o	конструктор з одним параметром вказівник на тип (інінціалізує поля x, y та z значенням масиву за вказівником, якщо вказівник NULL (nulptr) то встановити код помилки);
o	деструктор із виведенням інформації про стан вектора;
o	визначити функцію, яка присвоює полю x, y або z деяке значення (параметр за замовчуванням);
o	функцію яка одержує деякий елемент з полів x, y та z;
o	конструктор копій та операцію присвоєння; // !!!
o	визначити функції друку, додавання, віднімання, векторний добуток які здійснюють ці арифметичні операції з даними цього класу;
o	функцію ділення на ціле типу short(при діленні на 0 змінити стан, а ділення не виконувати)
o	визначити функції порівняння: більше, менше або рівно, які повертають true або false
У змінну стани встановлювати код помилки, діленні на 0, при передачі NULL (nulptr) в конструкторі із вказівником. Передбачити можливість підрахунку числа об'єктів даного типу. Написати програму тестування всіх можливостей цього класу.
*/
#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

enum STATE {
    OK, BAD_INIT, BAD_DIV
};

class Vector3 {
private:
    float x, y, z;
    int state;
    static int count;

public:
    Vector3() : x(0), y(0), z(0) { state = OK; count++; }
    Vector3(float val) : x(val), y(val), z(val) { state = OK; count++; }
    Vector3(float ix, float iy, float iz);
    Vector3(float* v);
    ~Vector3() {
        count--;
        cout << " state Vector3 " << state;
        cout << " Vector3 deleted\n";
    }
    Vector3(const Vector3&);
    Vector3 Add(Vector3& d);
    Vector3 Sub(Vector3& d);
    Vector3 Mul(float d);
    Vector3 Div(float d);
    void Input();
    void Output();
    bool CompLessAll(Vector3& s);
    static int getCount() { 
        if (count <= 0) cout << " No Vector3 objects ";
        return count; 
    }
    int getState() { return state; }
};

int Vector3::count = 0;

Vector3::Vector3(float ix, float iy, float iz) {
    x = ix; y = iy; z = iz;
    state = OK;
    count++;
}

Vector3::Vector3(const Vector3& s) {
    if (this == &s) return;
    x = s.x; y = s.y; z = s.z; state = OK;
    count++;
}

Vector3::Vector3(float* v) {
    if (v == nullptr) {
        state = BAD_INIT; x = 0; y = 0; z = 0;
    } else {
        x = v[0]; y = v[1]; z = v[2];
        state = OK;
    }
    count++;
}

void Vector3::Input() {
    cout << " Input x y z ";
    cin >> x >> y >> z;
}

void Vector3::Output() {
    cout << " x =" << x << " y = " << y << " z = " << z << " state " << state << endl;
}

Vector3 Vector3::Add(Vector3& s) {
    Vector3 tmp;
    tmp.x = x + s.x;
    tmp.y = y + s.y;
    tmp.z = z + s.z;
    return tmp;
}

Vector3 Vector3::Sub(Vector3& s) {
    Vector3 tmp;
    tmp.x = x - s.x;
    tmp.y = y - s.y;
    tmp.z = z - s.z;
    return tmp;
}

Vector3 Vector3::Mul(float d) {
    Vector3 tmp;
    tmp.x = x * d;
    tmp.y = y * d;
    tmp.z = z * d;
    return tmp;
}

Vector3 Vector3::Div(float d) {
    Vector3 tmp;
    if (fabs(d) < 1.e-25) {
        tmp.state = BAD_DIV;
        cout << " Error div \n";
        return *this;
    }
    tmp.x = x / d;
    tmp.y = y / d;
    tmp.z = z / d;
    return tmp;
}

bool Vector3::CompLessAll(Vector3& s) {
    return (x < s.x && y < s.y && z < s.z);
}

int main() {
    setlocale(LC_CTYPE, "ukr");
    cout << "Тестування створеного класу \n";
    cout << "Тестування конструкторів \n";
    Vector3 ObjCDef;
    ObjCDef.Output();
    Vector3 ObjP1(10.0);
    ObjP1.Output();
    float a = 1.0, b = 2.0, c = 3.0;
    Vector3 ObjP2(a, b, c);
    ObjP2.Output();
    Vector3 ObjCopy(ObjP2);
    float* v = nullptr, v2[] = { 1.2, 3.3, 4.5 };
    Vector3 ObjP3(v2);
    if (ObjP3.getState() != OK) cout << " ObjP3 x= 0 y= 0 z= 0 \n";
    Vector3 ObjP4(v2);
    if (ObjP4.getState() != OK) cout << " ObjP4 x= 0 y= 0 z= 0 \n";
    cout << " Кількість створених об'єктів Vector3 " << Vector3::getCount() << endl;
    cout << "Тестування введення \n";
    ObjCDef.Input();
    cout << "Тестування функцій \n";
    ObjCDef = ObjCDef.Add(ObjP2);
    ObjCDef.Output();
    cout << " \n Кількість створених об'єктів Vector3 до Sub " << Vector3::getCount() << endl;
    ObjCDef = ObjCDef.Sub(ObjP2);
    cout << " \n Кількість створених об'єктів Vector3 після Sub " << Vector3::getCount() << endl;
    ObjCDef.Output();
    ObjCDef = ObjCDef.Mul(5);
    ObjCDef.Output();
    ObjCDef = ObjCDef.Div(1.3);
    if (ObjCDef.getState() == STATE::BAD_DIV) cout << "BAD_DIV \n";
    ObjCDef.Output();
    ObjCDef = ObjCDef.Div(0.0);
    if (ObjCDef.getState() == STATE::BAD_DIV) cout << "BAD_DIV \n";
    ObjCDef.Output();
    cout << "ObjCopy state " << ObjCopy.getState() << endl;
    if (ObjCopy.CompLessAll(ObjCDef)) cout << "ObjCopy less ObjDef " << endl;
    cout << "Завершення тестування \n";
    return 0;
}


