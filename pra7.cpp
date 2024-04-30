#include <iostream>
using namespace std;

class Math
{
private:
    int Real, Imag,dm;

public:
    void getdata()
    {
        cout << "Enter real part : ";
        cin >> Real;
        cout << "Enter imaginary part : ";
        cin >> Imag;
    }
    // constructor (two args)
    Math()
    { }
    Math(int r, float i) : Real(r), Imag(i)  //return type cost ko acess karne ke liye
    {
    }
    Math(int r, float i,float d) : Real(r), Imag(i), dm(d) //return type cost ko acess karne ke liye
    {
    }
    Math operator+(Math t)
    {
        int r1 = Real + t.Real;
        int i1 = Imag + t.Imag;
        return Math(r1, i1);
    }

    Math operator-(Math t)
    {
        int r1 = Real - t.Real;
        int i1 = Imag - t.Imag;
        return Math(r1, i1);
    }

    Math operator*(Math t)
    {
         int r1 = (Real*t.Real)-(Imag*t.Imag);
         int i1 = (Real*t.Imag)+(Imag*t.Real);
        return Math(r1, i1);
    }

    Math operator/(Math t)
    {
            int r1=(Real*t.Real)+(Imag*t.Imag);
            int i1=(Imag*t.Real)-(Real*t.Imag);
            int dn=(t.Real*t.Real)+(t.Imag*t.Imag);
        return Math(r1, i1,dn);
    }
    Math operator!()
    {
            Real=-Real;
            Imag=-Imag;
        return Math(Real, Imag);
    }

    void putdata()
    {
        cout << "(" << Real << ")"
             << " + "
             << "(" << Imag << ")i" << endl;
    }
     void forslash()
        {
            cout << "(" << Real << "/" << dm <<")" << " + " << "(" << Imag << "/" << dm <<")i"<<endl;
        }
};

int main()
{
    Math a, b, c;
    char choise, ch;
    a.getdata();
    b.getdata();

    do
    {
        cout << "Chose operation" << endl
             << "(+) addition" << endl
             << "(-) substraction" << endl
             << "(*) multiplication" << endl
             << "(/) division" << endl
             << "(!) negation" << endl;
        cout << "Enter your choise : ";
        cin >> choise;
        switch (choise)
        {
        case '+':
            c = a + b;
            c.putdata();
            break;
        case '-':
            c = a - b;
            c.putdata();
            break;
        case '*':
            c = a * b;
            c.putdata();
            break;
        case '/':
            c = a / b;
            c.forslash();
            break;
        case '!':
            c = !a;
            c.putdata();
            c = !b;
            c.putdata();
        }
        cout<<"Enter y for another process:";
        cin >> ch;
    } while (ch == 'y');
}