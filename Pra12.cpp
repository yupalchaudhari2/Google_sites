#include<iostream>
#include<iomanip>
using namespace std;

class result;
class Student
{
    private:
    
    char stu_id[8];
    int semester, sum1 = 0, sum2 = 0, CreditSum = 0;
    float sgpa;
    string stu_name;

    public:

    void getdata_stu()
    {
    cout << "Enter student id:";
    cin >> stu_id;
    cout << "Enter Name of student:";
    cin >> stu_name;
    cout << "Enter the Semester:";
    cin >> semester;
    cin.ignore();
    
    }
    void putdata_stu()
    {
          cout.width(15);
    cout << left << "Student ID"
         << ":" << stu_id << endl;
    cout.width(15);
    cout << left << "Student Name"
         << ":" << stu_name << endl;
    cout.width(15);
    cout << left << "Semester"
         << ":" << semester << endl;
   
    }
    void getdata_result(result x);
    void putdata_result(result x);
};

class result
{
    private:

   int subject_credit[3],th_mark[3], pr_mark[3],sgpa;
   string th_grade[3], pr_grade[3],subject_name[3];

   public:
string Convert(int mark)
{
    if (mark >= 80)
        return "AA";
    if (mark >= 73)
        return "AB";
    if (mark >= 66)
        return "BB";
    if (mark >= 60)
        return "BC";
    if (mark >= 55)
        return "CC";
    if (mark >= 50)
        return "CD";
    if (mark >= 45)
        return "DD";
    return "FF"; // yaha ek se zyada return nhi karega toh ek ka true hua to baki ke true hone par bhi nhi batayega
}

int Sgpa(int mark)
{
    if (mark >= 80)
        return 10;
    if (mark >= 73)
        return 9;
    if (mark >= 66)
        return 8;
    if (mark >= 60)
        return 7;
    if (mark >= 55)
        return 6;
    if (mark >= 50)
        return 5;
    if (mark >= 45)
        return 4;
    return 0;
}

    friend void getdata_result(result x);
    friend void putdata_result(result x);
};

void student :: getdata_result(result x)
{
      for (int i = 0; i < 3; i++)
    {
        cout << "Enter " << i + 1 << " subject name:";
        cin.getline(subject_name[i], 30);
        cout << "Enter marks for " << subject_name[i] << " (Theory Practical): " << endl;
        cin >> th_mark[i] >> pr_mark[i];
        cin.ignore();
        th_grade[i] = Convert(th_mark[i]);
        pr_grade[i] = Convert(pr_mark[i]);
        sum1 += Sgpa(th_mark[i]) * th_credit[i];
        sum2 += Sgpa(pr_mark[i]) * pr_credit[i];
        CreditSum += th_credit[i] + pr_credit[i];
    }
    sgpa = (float)(sum1 + sum2) / CreditSum;
    system("cls");
}

void student::putdata_result(result x)
{
     cout << endl
         << left << setw(25) << "Subject" << setw(10) << "Theory"
         << "Practical" << endl;

    for (int i = 0; i < 3; i++)
        cout << left << setw(25) << Subject[i] << setw(10) << ThGrade[i] << setw(10) << PraGrade[i] << endl;

    cout << endl
         << "SGPA:" << setprecision(3) << sgpa;
}
