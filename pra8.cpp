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

protected:
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
        if (k == Employee_Id) // yaha in heritance hoga toh yeh check bhi chil class mai hi krega
        {
            // putempydata();
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
    }

public:
    static float getAverageExperience()
    {
        if (Total_Employees == 0)
            return 0;
        return Average_Experience / Total_Employees;
    }
};
float Employee::Average_Experience = 0;
int Employee::Total_Employees = 0;

class TeachingEmp : protected Employee
{
    string Designation;
    string Specialization;
    string PayScale;

public:
    int searchtemp(int a)
    {
        int t = searchemp(a);
        return t;
    };

    void gettempdata()
    {
        getempdata();
        cout << "Enter Designation: ";
        cin >> Designation;
        cout << "Enter Specialization: ";
        cin >> Specialization;
        cout << "Enter Pay Scale: ";
        cin >> PayScale;
    }

    void puttempdata() // yaha change kiya
    {
        putempydata();
        cout << "Designation   : " << Designation << endl;
        cout << "Specialization: " << Specialization << endl;
        cout << "Pay Scale     : " << PayScale << endl;
        cout << "-----------------------------------------------------------" << endl;
    }
};
class NonTeachingEmp : protected Employee
{
    int Salary;

public:
    int searchntemp(int a)
    {
        int t = searchemp(a);
        return t;
    }
    void getntempydata()
    {
        getempdata();
        cout << "Enter Salary: ";
        cin >> Salary;
    }
    void putntempydata()
    {
        putempydata();
        cout << "Salary        : " << Salary << endl;
        cout << "-----------------------------------------------------------" << endl;
    }
};

int main()
{
    int n, m, i, j, EmpID;
    char k;

    cout << "Enter no of Teaching Employee: ";
    cin >> n;
    TeachingEmp TEmpNo[n];

    for (i = 0; i < n; i++)
    {
        TEmpNo[i].gettempdata();
    }

    cout << "Enter no of Non Teaching Employee: ";
    cin >> m;
    NonTeachingEmp NTEmpNo[m];

    for (i = 0; i < m; i++)
    {
        NTEmpNo[i].getntempydata();
    }

    system("cls");
    cout << "Average Experience of all employees: " << Employee::getAverageExperience() << endl;
    do
    {
        cout << "Enter an employee id: ";
        cin >> EmpID;

        for (i = 0; i < n; i++)
        {
            if (EmpID == TEmpNo[i].searchtemp(EmpID))
            {
                TEmpNo[i].puttempdata();
                break;
            }
        }
        for (j = 0; j < m; j++)
        {
            if (EmpID == NTEmpNo[j].searchntemp(EmpID))
            {
                NTEmpNo[j].putntempydata();
                break;
            }
        }

        if (i == n && j == m)
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
