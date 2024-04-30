//             L
//         unique id
//           title
//             G P (function overiding)

//      EL                H
//     doi                copy
//      G P               G P

// book                magazine
// isbn                  isnn
// G P                   G  P
// virtual use karo  becoz insted of 5 get data function i need only 4
// one more variable to ask for type of book or magazine agar dusta dala toh firse puchna chahiye
// you have to make one more top variable top=-1 to trace data
// focus on calling function

#include <iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class litrature
{
    long id;
    string title;

public:
    virtual void getdata()
    {
        cout << "ID:";
        cin >> id;
        cout << "Title:";
        cin >> title;
    }
    void putdata()
    {
        cout <<id;
        cout << setw(25)<<title;
    }
};

class e_literature : public virtual litrature
{
    string doi;

public:
    void getdata()
    {
        cout << "DOI:";
        cin >> doi;
    }
    void putdata()
    {
         cout << setw(25)<<doi<<endl;
    }
};

class hard_copy : public virtual litrature
{
    int num;

public:
    void getdata()
    {
        cout << "In stock copies :";
        cin >> num;
    }
    void putdata()
    {
        cout<< setw(25)<< num<<endl;
    }
};

class book : public e_literature, public hard_copy
{
    long isbn;
    char z,j;

public:
    void getdata()
    {
        litrature::getdata();
        cout << "ISBN:";
        cin >> isbn;
        cout << "(E)copy or (H)ardbound :";
        cin >> z;
        cin.ignore();
        j=z;
        if (z == 'H'||z=='h')
        {
            hard_copy::getdata();
        }
        else if (z == 'E'||z=='e')
        {
            e_literature::getdata();
        }
        else
        {
            cout<<"Doba upar su lakyu che dekhatu nathi";
           // getdata();
        }
    }
    void putdata()
    {
        litrature::putdata();
        cout << setw(25) << isbn;
         if (j == 'H'||j=='h')
        {
          hard_copy::putdata();
        }
        else if (j == 'E'||j=='e')
        {
          e_literature::putdata();
        }
       
        
    }
};

class magazine : public e_literature, public hard_copy
{
    long isnn;
    char z,j;

public:
    void getdata()
    {

        litrature::getdata();
        cout << "ISNN:";
        cin >> isnn;
        cout << "(E)copy or (H)ardbound :";
        cin >> z;
        cin.ignore();
        j=z;
        if (z == 'H'||z=='h')
        {
            hard_copy::getdata();
        }
        else if (z == 'E'||z=='e')
        {
            e_literature::getdata();
        }
        else
        {
            cout<<"Doba upar su lakyu che dekhatu nathi";
           // getdata();
        }
    }
    void putdata()
    {
        litrature::putdata();
        cout << setw(5) << isnn;
         if (j == 'H'||j=='h')
        {
            hard_copy::putdata();
        }
        else if (j == 'E'||j=='e')
        {
          e_literature::putdata();
        }
    }
};

int main()
{
    book b[100];
    magazine m[100];
    int btop = -1, mtop = -1, k;
    char c;
    do
    {
        cout << "Enter 1 : Add book data" << endl;
        cout << "Enter 2 : Add magazine data" << endl;
        cout << "Enter 3 : List all books " << endl;
        cout << "Enter 4 : List all magazines " << endl;
        cout << "Enter you choice :" ;
        cin >> k;
        system("cls");

        switch (k)
        {

        case 1:
            cout<<"***** Add book data *****"<<endl;
            btop++;
            b[btop].getdata();
            cout<<"-------------------------------------------------------------------------"<<endl;
            cout << "Enter M to go to main menu.Press any key to exit:";
            cin >> c;
            system("cls");
            break;

        case 2:
            cout<<"***** Add magazine data *****"<<endl;
            mtop++;
            m[mtop].getdata();
            cout<<"-------------------------------------------------------------------------"<<endl;
            cout << "Enter M to go to main menu.Press any key to exit:";
            cin >> c;
            system("cls");
            break;

        case  3:
            cout<<"*****  List all books *****"<<endl;
            for (int i = 0; i <= btop ; i++)
            {
                b[i].putdata();
            }
       //     system("cls");  abe sale yaha tu karega to gir chala hi jayegana
            break;

        case 4 :
            cout<<"*****  List all magazines *****"<<endl;
            for(int i = 0 ;i <= mtop ; i++)
            {
                 m[i].putdata(); 
            } 
      //      system("cls");
            break;
            

        default:
            cout << "Invalid input";
        }
    } while (c == 'M');
    return 0;
}