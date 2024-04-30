#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
private:
    int Employee_Id;
    string Employee_Name, Qualification;
    float Experience;
    double Contact; //
    static float Average_Experience;
    static int Total_Employees;

public:
    void getempdata()
    {
        cout << "Enter EmpId: ";
        cin >> Employee_Id;
        cout << "Enter EmpName: ";
        cin >> Employee_Name;
        cout << "Enter EmpQuali: ";
        cin >> Qualification;
        cout << "Enter EmpExp: ";
        cin >> Experience;
        cout << "Enter ContactNum: ";
        cin >> Contact;
        Total_Employees++;
        Average_Experience += Experience;
    }

    int searchemp(int k)
    {
        if (k == Employee_Id)
        {
            putempydata();
            return Employee_Id;
        }
        return -1; // Return a value indicating not found
    }
    void putempydata()
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << "Employee Name : " << Employee_Name << endl;
        cout << "Qualification : " << Qualification << endl;
        cout << "Experience    : " << Experience << endl;
        cout << "Contact Number: " << Contact << endl;
        cout << "-----------------------------------------------------------" << endl;
    }

    static float getAverageExperience()
    {
        if (Total_Employees == 0)
            return 0;
        return Average_Experience / Total_Employees;
    }
};
float Employee::Average_Experience = 0;
int Employee::Total_Employees = 0;

int main()
{
    int n, m, i, j, EmpID;
    char k;

    cout << "Enter no of Employee: ";
    cin >> n;
    Employee EmpNo[n];

    for (i = 0; i < n; i++)
    {
        EmpNo[i].getempdata();
    }
    system("cls");
    cout << "Average Experience of all employees: " << Employee::getAverageExperience() << endl;
    do
    {
        cout << "Enter an employee id: ";
        cin >> EmpID;

        for (i = 0; i < n; i++)
        {
            if (EmpID == EmpNo[i].searchemp(EmpID))
            {
                break;
            }
        }

        if (i == n)
        {
            cout << "*****************************************************" << endl;
            cout << "ERROR: ENTERED EMPLOYEEMID DOES NOT EXIST." << endl;
            cout << "*****************************************************" << endl;
        }

        cout << "Press Y to get another employee detail,Press N to exit: " << endl;
        cin >> k;
        cin.ignore();
    } while (k == 'Y' || k == 'y');

    return 0;
}
