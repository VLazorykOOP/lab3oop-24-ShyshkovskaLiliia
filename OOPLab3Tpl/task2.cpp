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
