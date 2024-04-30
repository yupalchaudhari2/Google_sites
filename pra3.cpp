#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class CarDetail
{
private:
    string ModelName;
    string FuelType, Transmission, Airbags;
    float ShowroomPrice, TankCapacity, Mileage;
    int seating;

    void CarDetailFromName()
    {
        cout << setw(10) << ModelName << setw(15) << FuelType << setw(15) << ShowroomPrice
             << setw(15) << Mileage << setw(15) << Transmission << setw(15) << TankCapacity
             << setw(10) << seating << setw(10) << Airbags << endl;
    }

public:
    void GetDetailOfCar()
    {
        cout << "Enter ModelName: ";
        cin >> ModelName;
        cout << "Enter FuelType: ";
        cin >> FuelType;
        cout << "Enter Transmission: ";
        cin >> Transmission;
        cout << "Enter ShowroomPrice: ";
        cin >> ShowroomPrice;
        cout << "Enter TankCapacity: ";
        cin >> TankCapacity;
        cout << "Enter Mileage: ";
        cin >> Mileage;
        cout << "Enter seating: ";
        cin >> seating;
        cout << "Does Car have Airbags(Yes/No): ";
        cin >> Airbags;
        cin.ignore();
    }

    void SecurityCode(string C)
    {
        if (C == "$5^^###&*()")
        {
            CarDetailFromName();
        }
    }

    string CodeGenerator()
    {
        return "$5^^###&*()";
    }

    string ListCars()
    {
        return ModelName;
    }

    string FuelAccess()
    {
        return FuelType;
    }

    int GetPrice()
    {
        return ShowroomPrice;
    }

    void CarDetailFromNameTitle()
    {
        cout << setw(10) << "Model" << setw(15) << "Fuel Type" << setw(15) << "Showroom Price"
             << setw(15) << "Mileage" << setw(15) << "Transmission" << setw(15) << "Tank Capacity"
             << setw(10) << "Seating" << setw(10) << "Airbags" << endl;
    }
};

int main()
{
    char R;
    int a, n, m, i;
    float k;
    string Code;
    cout << "Enter Number of Cars: ";
    cin >> m;
    CarDetail CarInfo[m];
    cin.ignore();
    for (i = 0; i < m; i++)
    {
        CarInfo[i].GetDetailOfCar();
    }
    system("cls");
    do
    {
        n = 0;
        cout << "WELCOME TO TATA MOTORS" << endl;
        cout << "GET THE CAR DETAILS AS PER YOUR PREFERENCE" << endl;
        cout << "(1) Model Name  (2) Fuel Type  (3) Price Range" << endl;
        cout << "ENTER YOUR OPTION: ";
        cin >> a;
        cin.ignore();

        if (a == 1)
        {
            cout << "LIST OF TATA CARS" << endl;
            for (i = 0; i < m; i++)
            {
                cout << "(" << i + 1 << ")" << CarInfo[i].ListCars() << endl;
            }
            cout << "CHOOSE YOUR CAR TO GET DETAIL: ";
            cin >> n;
            i = n - 1;
            cin.ignore();
            CarInfo[i].CarDetailFromNameTitle(); // class mai se access karne ke liye carinfo use krna padega
            //c mai toh struct mai tum function bana hi nahi pate the
            Code = CarInfo[i].CodeGenerator();
            CarInfo[i].SecurityCode(Code);
        }
        else if (a == 2)
        {
            cout << "TATA MOTORS ARE AVAILABLE WITH FUEL OPTIONS" << endl;
            cout << "(1) Petrol  (2) Diesel (3) CNG (4) Electric " << endl;
            cout << "ENTER YOUR FUEL PREFERENCE: ";
            cin >> n;
            cin.ignore();
            CarInfo[n - 1].CarDetailFromNameTitle();
            switch (n)
            {
            case 1:
                for (i = 0; i < m; i++)
                {
                    if (CarInfo[i].FuelAccess() == "Petrol" || CarInfo[i].FuelAccess() == "petrol")
                    {
                        Code = CarInfo[i].CodeGenerator();
                        CarInfo[i].SecurityCode(Code);
                    }
                }
                break;
            case 2:
                for (i = 0; i < m; i++)
                {
                    if (CarInfo[i].FuelAccess() == "Diesel" || CarInfo[i].FuelAccess() == "diesel")
                    {
                        Code = CarInfo[i].CodeGenerator();
                        CarInfo[i].SecurityCode(Code);
                    }
                }
                break;
            case 3:
                for (i = 0; i < m; i++)
                {
                    if (CarInfo[i].FuelAccess() == "CNG" || CarInfo[i].FuelAccess() == "cng")
                    {
                        Code = CarInfo[i].CodeGenerator();
                        CarInfo[i].SecurityCode(Code);
                    }
                }
                break;
            case 4:
                for (i = 0; i < m; i++)
                {
                    if (CarInfo[i].FuelAccess() == "Electric" || CarInfo[i].FuelAccess() == "electric")
                    {
                        Code = CarInfo[i].CodeGenerator();
                        CarInfo[i].SecurityCode(Code);
                    }
                }
                break;
            default:
                cout << "Invalid Input ";
                break;
            }
        }
        else if (a == 3)
        {
            cout << "ENTER YOUR MAXIMUM AFFORDABLE RANGE IN LAKHS: ";
            cin >> k;
            cin.ignore();
            CarInfo[0].CarDetailFromNameTitle();
            for (i = 0; i < m; i++)
            {
                if (CarInfo[i].GetPrice() <= k)
                {
                    Code = CarInfo[i].CodeGenerator();
                    CarInfo[i].SecurityCode(Code);
                }
            }
            // no found kaise find karenge ?
        }
        cout << "Do you want to check details One more time? (Press 1): ";
        cin >> R;
        cin.ignore();
    } while (R == '1');
    return 0;
}
