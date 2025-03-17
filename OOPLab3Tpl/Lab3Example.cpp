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
#include <stdexcept>
using namespace std;

enum STATE { OK, BAD_INIT, BAD_DIV };

class Vector {
	double x, y, z;
	int state;
	static int count;

public:
	// Конструктори
	Vector() : x(0), y(0), z(0), state(OK) {
		count++;
		cout << "Vector created: " << *this << " (Default constructor)" << endl;
	}
	Vector(double iv) : x(iv), y(iv), z(iv), state(OK) {
		count++;
		cout << "Vector created: " << *this << " (Single value constructor)" << endl;
	}
	Vector(double ix, double iy, double iz) : x(ix), y(iy), z(iz), state(OK) {
		count++;
		cout << "Vector created: " << *this << " (Three values constructor)" << endl;
	}
	Vector(double* v);
	Vector(const Vector& other);

	// Деструктор
	~Vector() {
		count--;
		cout << "Vector destroyed: " << *this << " (State: " << state << ")" << endl;
	}

	// Оператор присвоєння
	Vector& operator=(const Vector& other);

	// Оператори
	Vector operator+(const Vector& other) const;
	Vector operator-(const Vector& other) const;
	Vector operator*(double scalar) const;
	Vector operator/(short scalar);
	bool operator==(const Vector& other) const;
	bool operator!=(const Vector& other) const;
	bool operator>(const Vector& other) const;
	bool operator<(const Vector& other) const;
	friend ostream& operator<<(ostream& os, const Vector& v);
	friend istream& operator>>(istream& is, Vector& v);

	// Додаткові методи
	void setValue(char field, double value = 0.0);
	double getValue(char field) const;
	Vector Cross(const Vector& other) const;
	static int getCount() { return count; }
};

int Vector::count = 0;

// Конструктор з вказівником
Vector::Vector(double* v) {
	if (!v) {
		state = BAD_INIT;
		x = y = z = 0;
	}
	else {
		x = v[0]; y = v[1]; z = v[2];
		state = OK;
	}
	count++;
	cout << "Vector created: " << *this << " (Pointer constructor)" << endl;
}

// Конструктор копій
Vector::Vector(const Vector& other) : x(other.x), y(other.y), z(other.z), state(other.state) {
	count++;
	cout << "Vector created: " << *this << " (Copy constructor)" << endl;
}

// Оператор присвоєння
Vector& Vector::operator=(const Vector& other) {
	if (this != &other) {
		x = other.x;
		y = other.y;
		z = other.z;
		state = other.state;
	}
	cout << "Vector assigned: " << *this << " (Assignment operator)" << endl;
	return *this;
}

// Оператори
Vector Vector::operator+(const Vector& other) const {
	return Vector(x + other.x, y + other.y, z + other.z);
}

Vector Vector::operator-(const Vector& other) const {
	return Vector(x - other.x, y - other.y, z - other.z);
}

Vector Vector::operator*(double scalar) const {
	return Vector(x * scalar, y * scalar, z * scalar);
}

Vector Vector::operator/(short scalar) {
	if (scalar == 0) {
		state = BAD_DIV;
		cerr << "Error: Division by zero" << endl;
		return *this;
	}
	return Vector(x / scalar, y / scalar, z / scalar);
}

bool Vector::operator==(const Vector& other) const {
	return (x == other.x && y == other.y && z == other.z);
}

bool Vector::operator!=(const Vector& other) const {
	return !(*this == other);
}

bool Vector::operator>(const Vector& other) const {
	return (x > other.x && y > other.y && z > other.z);
}

bool Vector::operator<(const Vector& other) const {
	return (x < other.x && y < other.y && z < other.z);
}

ostream& operator<<(ostream& os, const Vector& v) {
	os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}

istream& operator>>(istream& is, Vector& v) {
	cout << "Enter x, y, z: ";
	is >> v.x >> v.y >> v.z;
	return is;
}

// Встановлення значення поля
void Vector::setValue(char field, double value) {
	switch (field) {
	case 'x': x = value; break;
	case 'y': y = value; break;
	case 'z': z = value; break;
	default: throw invalid_argument("Error: Invalid field");
	}
}

// Отримання значення поля
double Vector::getValue(char field) const {
	switch (field) {
	case 'x': return x;
	case 'y': return y;
	case 'z': return z;
	default: throw invalid_argument("Error: Invalid field");
	}
}

// Векторний добуток
Vector Vector::Cross(const Vector& other) const {
	return Vector(y * other.z - z * other.y,
		z * other.x - x * other.z,
		x * other.y - y * other.x);
}

// Тестування
int mainExample3() {
	try {
		cout << "Testing Vector class...\n";

		Vector v1;
		Vector v2(5.0);
		Vector v3(1.0, 2.0, 3.0);
		Vector v4 = v3;
		Vector v5 = v3 + v2;
		Vector v6 = v3 - v2;
		Vector v7 = v3 * 2.0;
		Vector v8 = v3 / 2;
		Vector v9 = v3.Cross(v2);

		cout << "v1: " << v1 << endl;
		cout << "v2: " << v2 << endl;
		cout << "v3: " << v3 << endl;
		cout << "v4 (copy of v3): " << v4 << endl;
		cout << "v5 (v3 + v2): " << v5 << endl;
		cout << "v6 (v3 - v2): " << v6 << endl;
		cout << "v7 (v3 * 2.0): " << v7 << endl;
		cout << "v8 (v3 / 2): " << v8 << endl;
		cout << "v9 (v3 x v2): " << v9 << endl;

		cout << "Is v3 > v2? " << (v3 > v2) << endl;
		cout << "Is v3 < v2? " << (v3 < v2) << endl;

		Vector v10;
		cin >> v10;
		cout << "v10 (user input): " << v10 << endl;

		cout << "Vector count: " << Vector::getCount() << endl;
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
	}

	return 0;
}
/*example  4
Створити тип даних - клас вектор, який має вказівник на ComplexDouble, число елементів і змінну стану. У класі визначити
o	 конструктор без параметрів( виділяє місце для одного елемента та інінціалізує його в нуль);
o	конструктор з одним параметром - розмір вектора( виділяє місце та інінціалізує масив значенням нуль);
o	конструктор із двома параметрами - розмір вектора та значення ініціалізації(виділяє місце (значення перший аргумент) та інінціалізує значенням другого аргументу).
o	конструктор копій та операцію присвоєння; // !!!
o	деструктор звільняє пам'ять;
o	визначити функції друку, додавання;
У змінну стани встановлювати код помилки, коли не вистачає пам'яті, виходить за межі масиву. Передбачити можливість підрахунку числа об'єктів даного типу. Написати програму тестування всіх можливостей цього класу.
*/

#include<complex>
using namespace std;
typedef complex<double> ComplexDouble;
#define _RE 0
#define _IM 1

class ComplexVector
{
	ComplexDouble* v;
	int num;   // default num=2
	int state = 0;
public:
	ComplexVector() : ComplexVector(2) {}
	ComplexVector(int n);
	ComplexVector(int n, ComplexDouble&);
	ComplexVector(int n, ComplexDouble*);
	ComplexVector(const ComplexVector& s);
	ComplexVector& operator=(const ComplexVector& s);
	~ComplexVector() {
		std::cout << " del vec";
		if (v) delete[] v;
	}
	void Output();
	void Input();
	ComplexVector Add(ComplexVector& b);

};

ComplexVector::ComplexVector(int n) {
	if (n <= 0)    n = 2;  // default num =2;
	num = n;
	v = new ComplexDouble[n];
	for (int i = 0; i < n; i++) {
			v[i] = 0.0;
			//v[i]._Val[_RE]=0.0; v[i]._Val[_IM]=0.0;  
		}

}
ComplexVector::ComplexVector(int n, ComplexDouble& b) : ComplexVector(n) {
	for (int i = 0; i < num; i++) {
		v[i] = b;
		//v[i]._Val[_RE]=0.0; v[i]._Val[_IM]=0.0;  
	}
}

ComplexVector::ComplexVector(int n, ComplexDouble* p) : ComplexVector(n) {
	if (p != nullptr) 
	for (int i = 0; i < num; i++) 
		v[i] = p[i];
	
}

ComplexVector::ComplexVector(const ComplexVector& s) {
	// if (this == &s) return;  // the expression is used in the old standard
	num = s.num;
	v = new ComplexDouble[num];
	state = 0;
	for (int i = 0; i < num; i++)   v[i] = s.v[i];
}

ComplexVector& ComplexVector::operator=(const ComplexVector& s) {

	if (num != s.num)
	{
		if (v) delete[] v;
		num = s.num;
		v = new ComplexDouble[num];
		state = 0;
	}
	for (int i = 0; i < num; i++)   v[i] = s.v[i];
	return *this;
}
void ComplexVector::Input() {
	int in_num=0;
		do {
			cout << "Input size Vec\n";
			cin >> in_num;
		} while (in_num <= 0);
		if (num != in_num ) {
			num = in_num;
			if (v) delete[] v;
		v = new ComplexDouble[num];
	}
	for (int i = 0; i < num; i++) {

#if defined(_MSC_VER)
cout << " v [ " << i << " ] real img  "; cin >> v[i] >> v[i]._Val[_IM];
#else 
double re,im;
cout << " v [ " << i << " ] real img  "; cin >> re>>im;
v[i].real(re); 
v[i].imag(im);
#endif		
		
		
	}
}

void ComplexVector::Output() {
	if (num != 0) {
		for (int i = 0; i < num; i++) {
			cout << " v [ " << i << " ]   " << v[i] << '\t';
			cout << endl;
		}
	}
}

ComplexVector ComplexVector::Add(ComplexVector& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	if (tnum >= 0) {
		ComplexVector tmp(tnum);
		for (int i = 0; i < tnum; i++) tmp.v[i] = v[i] + b.v[i];
		return tmp;
	}
	return ComplexVector(1);
}


int mainExample4()
{
	ComplexDouble a(1.0, 2), b, c;
	cout << a << endl;
#if defined(_MSC_VER)
    b._Val[_RE] = 21.3;
	b._Val[_IM] = 22.3;
#else 
    b.real( 21.3);
	b.imag (22.3);
#endif	
	
	cout << b << endl;
	c = a + b;
	cout << c << endl;
	cout << " Test  " << endl;
	ComplexVector VecObj, VecObj1(10);
	cout << "VecObj \n";
	VecObj.Output();
	cout << "VecObj1 \n";
	VecObj1.Output();
	cout << " Input a " << endl;

#if defined(_MSC_VER)
 cin >> a >> a._Val[_IM];
#else 
double re,im;
cin >> re>>im;
a.real(re); 
a.imag(im);
#endif		
	cout << a << endl;
	ComplexVector VecObj2(10, a);
	VecObj2.Output();

	VecObj.Input();
	cout << endl;
	VecObj.Output();
	VecObj1 = VecObj.Add(VecObj2);
	VecObj1.Output();

	return 1;
}

/// 

