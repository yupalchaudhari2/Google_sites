#include <iostream>
using namespace std;

class Centimeter; // Forward declaration

class Millimeter
{
private:
    double m;

public:
    Millimeter() {}
    Millimeter(Centimeter x);
    double sendmm() { return m; }
    void getmm() { cin >> m; }
    void putmm() { cout << m; }
};

class Centimeter
{
private:
    double m;

public:
    Centimeter() {}
    Centimeter(Millimeter y);
    double sendcm() { return m; }
    void getcm() { cin >> m; }
    void putcm() { cout << m; }
};

// Define constructors outside the class definition
// becoz yaha agar ham isko class mai likhte hai toh yeh process karne lagega jabki
// centimeter x toh tab banega jab vaha pe compiler aayega na isiliye dono ke baad kiya
Millimeter::Millimeter(Centimeter x)
{
    m = x.sendcm() * 10.0;
}

Centimeter::Centimeter(Millimeter y)
{
    m = y.sendmm() / 10.0;
}

int main()
{
    Millimeter M;
    Centimeter C;
    int k;
    cout << "Enter 1 : mm to cm converter"<<endl;
    cout << "Enter 2 : cm to mm converter"<<endl;
    cin >> k;
    if (k == 1)
    {
        cout << "Enter measurement in millimeters: ";
        M.getmm();
        C = M;
        cout << "Equivalent measurement in centimeters: ";
        C.putcm();
        cout << " cm" << endl;
    }
    else if (k == 2)
    {
        cout << "Enter measurement in centimeters: ";
        C.getcm();
        M = C;
        cout << "Equivalent measurement in millimeters: ";
        M.putmm();
        cout << " mm" << endl;
    }
    else
    {
        cout << "wrong input";
    }

    return 0;
}
