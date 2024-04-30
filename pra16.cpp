#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
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
    void GetDetailOfCar(string M, string F, float S, float Mi, string T, float Ta, int s, string A)
    {
        ModelName = M;
        FuelType = F;
        Transmission = T;
        ShowroomPrice = S;
        TankCapacity = Ta;
        Mileage = Mi;
        seating = s;
        Airbags = A;
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
    string ModelName, str, b;
    int c = 0;
    string FuelType, Transmission, Airbags;

    string ShowroomPrice, TankCapacity, Mileage;
    float ShowroomPricei, TankCapacityi, Mileagei;
    int seatingi;
    char R;
    int n;
    float k;
    string Code;

    string seating;

    ifstream f;
    f.open("cardata.txt");
    if (!f.is_open())
    {
        cout << "Error: Unable to open file." << endl;
        return 1;
    }
    else
        (cout << "file is successfully opened." << endl);
    //  while ( getline(f, b, ';'))
    // {
    //     c++;
    // }
    CarDetail CarInfo[10];
    // f.seekg(0,ios::beg);

    int x = 0, i; // sala MC i ki vajah se kab ka loch ho raha tha

    // check karo ki open hui ya nahi
    while (f.eof() == 0)
    {

        getline(f, ModelName, ',');
        getline(f, FuelType, ',');
        getline(f, ShowroomPrice, ',');
        getline(f, Mileage, ',');
        getline(f, Transmission, ',');
        getline(f, TankCapacity, ',');
        getline(f, seating, ',');
        getline(f, Airbags, ';');

        ShowroomPricei = stof(ShowroomPrice);
        TankCapacityi = stof(TankCapacity);
        Mileagei = stof(Mileage);
        seatingi = stod(seating);
        CarInfo[x].GetDetailOfCar(ModelName, FuelType, ShowroomPricei, Mileagei, Transmission, TankCapacityi, seatingi, Airbags);
        x++;
    }
    f.close();
    int a;
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
            for (i = 0; i < x - 1; i++)
            {
                cout << "(" << i + 1 << ")" << CarInfo[i].ListCars() << endl;
            }
            cout << "CHOOSE YOUR CAR TO GET DETAIL: ";
            while (!(cin >> n) || n < 1 || n > x - 1) // Check for invalid input and out-of-range values
            {
                cin.clear();                                         // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Invalid input. Please enter a valid number: ";
            }

            i = n - 1;
            cin.ignore();
            CarInfo[i].CarDetailFromNameTitle(); // class mai se access karne ke liye carinfo use krna padega
            // c mai toh struct mai tum function bana hi nahi pate the
            Code = CarInfo[i].CodeGenerator();
            CarInfo[i].SecurityCode(Code);
        }
        else if (a == 2)
        {
            cout << "TATA MOTORS ARE AVAILABLE WITH FUEL OPTIONS" << endl;
            cout << "(1) Petrol  (2) Diesel (3) CNG (4) Electric " << endl;
            cout << "ENTER YOUR FUEL PREFERENCE: ";
             while (!(cin >> n) || n < 1 || n > 4) // Check for invalid input and out-of-range values
            {
                cin.clear();                                         // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Invalid input. Please enter a valid number: ";
            }

            cin.ignore();
            CarInfo[n - 1].CarDetailFromNameTitle();
            switch (n)
            {
            case 1:
                for (i = 0; i < x - 1; i++)
                {
                    if (CarInfo[i].FuelAccess() == "Petrol" || CarInfo[i].FuelAccess() == "petrol")
                    {
                        Code = CarInfo[i].CodeGenerator();
                        CarInfo[i].SecurityCode(Code);
                    }
                }
                break;
            case 2:
                for (i = 0; i < x - 1; i++)
                {
                    if (CarInfo[i].FuelAccess() == "Diesel" || CarInfo[i].FuelAccess() == "diesel")
                    {
                        Code = CarInfo[i].CodeGenerator();
                        CarInfo[i].SecurityCode(Code);
                    }
                }
                break;
            case 3:
                for (i = 0; i < x - 1; i++)
                {
                    if (CarInfo[i].FuelAccess() == "CNG" || CarInfo[i].FuelAccess() == "cng")
                    {
                        Code = CarInfo[i].CodeGenerator();
                        CarInfo[i].SecurityCode(Code);
                    }
                }
                break;
            case 4:
                for (i = 0; i < x - 1; i++)
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
            for (i = 0; i < x - 1; i++)
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