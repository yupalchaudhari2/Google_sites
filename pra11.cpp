#include <iostream>
using namespace std;

class EmployeeExperience
{
private:
    int Y,M;

public:
    EmployeeExperience() {}
    void getdata()
    {
        cout<<"Years:";
        cin>>Y;
        cout<<"Months:";
        cin>>M;
        
    }
    operator float()
{
    return (Y+(M/12.0));
}
};

int main()
{
    float input;
    EmployeeExperience K;
    cout << "Enter employee experience in years and months "<<endl;
    K.getdata();
    input=K;
    cout<<"Employee experience is :"<<input<<endl;
    return 0;
}
