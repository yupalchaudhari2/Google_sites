
#include <iostream>
#include <iomanip>
using namespace std;

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

void PrintMarksheet()
{
    char StuId[8], NameOfStu[20], Subject[3][30];
    int semester, sum1 = 0, sum2 = 0, CreditSum = 0;
    float sgpa;
    string ThGrade[3], PraGrade[3];
    int ThMark[3], PraMark[3], ThSgpa[3], PraSgpa[3], ThCredit[] = {3, 3, 3}, PraCredit[] = {1, 1, 1};

    cout << "Enter student id:";
    cin >> StuId;
    cout << "Enter Name of student:";
    cin >> NameOfStu;
    cout << "Enter the Semester:";
    cin >> semester;
    cin.ignore();
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter " << i + 1 << " subject name:";
        cin.getline(Subject[i], 30);
        cout << "Enter marks for " << Subject[i] << " (Theory Practical): " << endl;
        cin >> ThMark[i] >> PraMark[i];
        cin.ignore();
        ThGrade[i] = Convert(ThMark[i]);
        PraGrade[i] = Convert(PraMark[i]);
        sum1 += Sgpa(ThMark[i]) * ThCredit[i];
        sum2 += Sgpa(PraMark[i]) * PraCredit[i];
        CreditSum += ThCredit[i] + PraCredit[i];
    }
    sgpa = (float)(sum1 + sum2) / CreditSum;
    system("cls");
    cout.width(15);
    cout << left << "Student ID"
         << ":" << StuId << endl;
    cout.width(15);
    cout << left << "Student Name"
         << ":" << NameOfStu << endl;
    cout.width(15);
    cout << left << "Semester"
         << ":" << semester << endl;
    cout << endl
         << left << setw(25) << "Subject" << setw(10) << "Theory"
         << "Practical" << endl;

    for (int i = 0; i < 3; i++)
        cout << left << setw(25) << Subject[i] << setw(10) << ThGrade[i] << setw(10) << PraGrade[i] << endl;

    cout << endl
         << "SGPA:" << setprecision(3) << sgpa;
}

int main()
{
    PrintMarksheet();
    return 0;
}
