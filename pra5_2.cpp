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
    Circle *dynamicCircle1 = new Circle;
    cout << "Dynamic Circle 1 Area: " << dynamicCircle1->calculate_area() << endl;
    Circle *dynamicCircle2 = new Circle(20.0);
    cout << "Dynamic Circle 2 Area: " << dynamicCircle2->calculate_area() << endl;
   // delete dynamicCircle1;
    // delete dynamicCircle2;
    Circle *dynamicCircle3 = new Circle(*dynamicCircle1);
    cout << "Dynamic Circle 3 Area: " << dynamicCircle3->calculate_area() << endl;
    delete dynamicCircle1;
    delete dynamicCircle2;
    delete dynamicCircle3;
    return 0;
}
