// // example of constuctor in derived class
// class A
// {
// private:
//     int a;
//      public : A(int x)
//     {
//         a = x;
//     }
// };

// class B:public A
// {
// private:
//     int b;

// public:
//     B(int x, int y) : A(x)
//     {
//         b = y;
//     }
// };

// int main()
// {
//     B *p;
//     p = new B(10, 20);
//     return 0;
// }

// example of pure virtual function in derived class

// #include <iostream>
// using namespace std;

// class A
// {
// public:
//     virtual void fp() = 0;
//     void f()
//     {
//         cout << "Hello";
//     }
// };

// class B : public A
// {
// public:
//     void fp()
//     {
//         cout << "Hi";
//     }
// };

// int main()
// {
//     B b;
//     A a;  //see the error here

//     b.fp();
//     return 0;
// }

#include <iostream>
#include<string.h>
using namespace std;

class product
{

    int product_id;
    string product_name;
    string product_manufacturer;
    float product_price;

public:
    virtual void putdata() = 0;
    product() {}
    product(int product_id, string product_name, string product_manufacturer, float product_price)
    {
        // cout << product_id << " : " << product_name
        //      << " : " << product_manufacturer
        //      << " : " << product_price << endl;
    }
};

class smartwatch : public product
{

    float dial_size;

public:
    void putdata() {}
    smartwatch() {}
    smartwatch(int product_id, string product_name, string product_manufacturer, float product_price, float dial_size) : product(product_id, product_name, product_manufacturer, product_price)
    {
        cout << product_id << " : " << product_name
             << " : " << product_manufacturer
             << " : " << product_price << " : " << dial_size << endl;
    }
};

class bedsheet : public product
{

    float Width;
    float Height;

public:
    void putdata() {}
    bedsheet(int product_id, string product_name, string product_manufacturer, float product_price, float Width, float Height) : product(product_id, product_name, product_manufacturer, product_price)
    {
        cout << product_id << " : " << product_name
             << " : " << product_manufacturer
             << " : " << product_price << " : " << Width
             << " : " << Height << endl;
    }
};

int main()
{
    int product_id;
    string product_name;
    string product_manufacturer;
    float product_price;
    float Width;
    float Height;
    float dial_size;
    int k;
    cout << "Enter 1 : smartwatch menu" << endl;
    cout << "Enter 2 : bedsheet menu" << endl;
    cout << "Enter your choice : ";
    cin >> k;
    cin.ignore();
    switch (k)
    {
    case 1:
        cout << "***** ENTER SMART WATCH DATA *****" << endl;
        cout << "Enter Product ID:";
        cin >> product_id;
        cin.ignore();
        cout << "Enter Product Name:";
        getline(cin, product_name);
        cin.ignore();
        cout << "Enter Product Manufacturer:";
        getline(cin, product_manufacturer);
        cin.ignore();
        cout << "Enter Product Price:";
        cin >> product_price;
        cin.ignore();
        cout << "Enter Product Dial Size:";
        cin >> dial_size;
        cin.ignore();
        smartwatch *s;
        cout<<"----------------------------------------------------------------------------------------"<<endl;        
        s = new smartwatch(product_id, product_name, product_manufacturer, product_price, dial_size);
        cout<<"----------------------------------------------------------------------------------------"<<endl;        
        break;
    case 2:
        cout << "***** ENTER BEDSHEET DATA *****" << endl;
        cout << "Enter Product ID:";
        cin >> product_id;
        cin.ignore();
        cout << "Enter Product Name:";
        getline(cin, product_name);
        cin.ignore();
        cout << "Enter Product Manufacturer:";
        getline(cin, product_manufacturer);
        cin.ignore();
        cout << "Enter Product Price:";
        cin >> product_price;
        cin.ignore();
        cout << "Enter Product Width:";
        cin >> Width;
        cin.ignore();
        cout << "Enter Product Height:";
        cin >> Height;
        cin.ignore();
        bedsheet *b;
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        b = new bedsheet(product_id, product_name, product_manufacturer, product_price, Width, Height);
        cout<<"----------------------------------------------------------------------------------------"<<endl;        
        break;
    default:
        cout << "Enter valie number between 1 and 2 only";
    }
    return 0;
}
