#include <iostream>
#include <iomanip>
using namespace std;

struct EmpDetail
{
private:
    int EmpId;
    string EmpName, EmpQuali, EmpExp;
    double ContactNum;

public:
    void GetDetail()
    {
        cout << "Enter EmpId: ";
        cin >> EmpId;
        cout << "Enter EmpName: ";
        cin >> EmpName;
        cout << "Enter EmpQuali: ";
        cin >> EmpQuali;
        cout << "Enter EmpExp: ";
        cin >> EmpExp;
        cout << "Enter ContactNum: ";
        cin >> ContactNum;
    }
    int check(int k)
    {
        if(k==EmpId)
        {
            PrintDetail();
            return EmpId;
        }
        return -1; // Return a value indicating not found
        
    }
private:
    void PrintDetail()
    {
        //  cout << "EmpId: " << EmpId << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "Employee Name : " << EmpName << endl;
        cout << "Qualification : " << EmpQuali << endl;
        cout << "Experience    : " << EmpExp << endl;
        cout << "Contact Number: " << ContactNum << endl;
        cout << "-----------------------------------------------------------" << endl;
    }
};

int main()
{
    EmpDetail EmpNo[1000];
    int n, i, EmpID;
    char k;

    cout << "Enter no of Employee: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        EmpNo[i].GetDetail();
    }
    system("cls");
    do
    {
        cout << "Enter an employee id: ";
        cin >> EmpID;

        for (i = 0; i < n; i++)
        {
            if (EmpID ==EmpNo[i].check(EmpID))
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
    } while (k == 'Y' || k == 'y');

    return 0;
}
