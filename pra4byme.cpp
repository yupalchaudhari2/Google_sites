#include <iostream>
#include <iomanip>
using namespace std;

void AreaCalculation(int r)
{
    cout << 3.14 * r * r;
}
void AreaCalculation(int l, int b)
{
    cout << l * b;
}
void AreaCalculation(int l, int b, int h)
{
    cout << 2 * ((l * b) + (b * h) + (h * l));
}
int main()
{
    float a, b, c;
    cout << "Enter the radius of a circle:";
    cin >> a;
    cout << "The area of a circle is"<< AreaCalculation(a);
    a = 0;
    cout << "Enter the height of a rectangle:";
    cin >> a;
    cout << "Enter the width of a rectangle:";
    cin >> b;
     cout << "The area of a rectangle is"; AreaCalculation(a, b);
    a = 0;
    b = 0;
    cout << "Enter the height of a cuboid:";
    cin >> a;
    cout << "Enter the width of a cuboid:";
    cin >> b;
    cout << "Enter the depth of a cuboid:";
    cin >> c;
    AreaCalculation(a, b, c);
    return 0;
}