#include <iostream>
using namespace std;

class EmployeeExperience
{
private:
    float experience;

public:
    EmployeeExperience() {}
    EmployeeExperience(float x)
    {
        experience = x;
    }

    void convertToExperience()
    {
        int years = experience;
        int months = (experience - years) * 12;

        cout << "Employee experience is " << years << " years and " << months << " months" << endl;
    }
};

int main()
{
    float input;
    EmployeeExperience K;
    cout << "Enter employee experience: ";
    cin >> input;
    K = input;
    K.convertToExperience();
    return 0;
}
