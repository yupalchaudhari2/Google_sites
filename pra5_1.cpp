#include <iostream>
#include <iomanip>

using namespace std;  

class Circle {
private:
    static int total_circles;

public:
    int radius;

    Circle() {
        total_circles++;
        radius = 1;
    }

    Circle(int x) {
        total_circles++;
        radius = x;
    }

    Circle(Circle& y) {
        total_circles++;
        radius = y.radius;  
    }

    ~Circle() {
        cout<<"One object is deleted"<<endl;
        total_circles--;
        cout<<"Total active objects are "<<total_circles<<endl;
    }

    float calculate_area() {
        return 3.148 * radius * radius;
    }

    
};
int Circle::total_circles=0;
int main() {
    Circle staticCircle1;
    cout << "Circle with radius 1 has area " << staticCircle1.calculate_area() << endl;

    Circle staticCircle2(20.0);
    cout << "Circle with radius 20 has area " << staticCircle2.calculate_area() << endl;

    Circle staticCircle3(staticCircle1);
    cout << "Circle with radius 1 has area " << staticCircle3.calculate_area() << endl;

    return 0;
}
