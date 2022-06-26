#include <iostream>
#include <fstream>

using namespace std;

class shopping
{

private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping ::menu()
{
start:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t_________________________________\n";
    cout << "\t\t\t\t                                 \n";
    cout << "\t\t\t\t      Supermarket Main Menu      \n";
    cout << "\t\t\t\t                                 \n";
    cout << "\t\t\t\t_________________________________\n";
    cout << "\t\t\t\t                                 \n";
    cout << "\t\t\t\t|    1) Administrator     |\n";
    cout << "\t\t\t\t|                         |\n";
    cout << "\t\t\t\t|    2) Buyer             |\n";
    cout << "\t\t\t\t|                         |\n";
    cout << "\t\t\t\t|    3) Exit              |\n";
    cout << "\n\t\t\t Please select!";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t Please login    \n";
        cout << "\t\t\t Enter Email     \n";
        cin >> email;
        cout << "\t\t\t Enter Password  \n";
        cin >> password;

        if (email == "admin@gmail.com" && password == "admin123")
        {
            administrator();
        }
        else
        {
            cout << "Invalid email or password! \n";
        }
        break;

    case 2:
    {
        buyer();
    }

    case 3:
    {
        exit(0);
    }

    default:
    {
        cout << "Please Select a given option!";
    }
    }

    goto start;
}

void shopping ::administrator()
{
start:
    int choice;
    cout << "\n\n\n\t\t\t Administrator menu";
    cout << "\n\t\t\t|_______1) Add the product_______|";
    cout << "\n\t\t\t|                                |";
    cout << "\n\t\t\t|_______2) Modify the product____|";
    cout << "\n\t\t\t|                                |";
    cout << "\n\t\t\t|_______3) Delete the product____|";
    cout << "\n\t\t\t|                                |";
    cout << "\n\t\t\t|_______3) Back to main menu_____|";

    cout << "\n\n\y Pleas enter your choice ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        rem();
        break;

    case 4:
        menu();
        break;

    default:
        cout << "Invalid choice!";
    }

    goto start;
}

void shopping ::buyer()
{
start:
    int choice;
    cout << "\t\t\t       Buyer         \n";
    cout << "\t\t\t_____________________\n";
    cout << "                           \n";
    cout << "\t\t\t   1) Buy Product    \n";
    cout << "                           \n";
    cout << "\t\t\t   2) Go back        \n";
    cout << "\t\t\t  Enter your choice: \n";

    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;

    case 2:
        menu();
        break;

    default:
        cout << "Invalid choice!";
    }

    goto start;
}

void shopping ::add()
{
start:
    fstream data;
    int c;
    int token = 0;
    float p, d;
    string n;

    cout << "\n\n\t\t\t Add new product";
    cout << "\n\n\t Product code of the product ";
    cin >> pcode;
    cout << "\n\n Name of the product ";
    cin >> pname;
    cout << "\n\n\t Price of the product";
    cin >> price;
    cout << "\n\n\t Discount on the product";
    cin >> dis;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;

        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }

    if (token == 1)
    {
        goto start;
    }
    else
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }

    cout << "\n\n\t\t Record inserted! ";
}

void shopping ::edit()
{

    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p, d;
    string n;

    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code:    ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n File doesn't exist!";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;

        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t New code of Product :";
                cin >> c;
                cout << "\n\t\t Name of the Product :";
                cin >> n;
                cout << "\n\t\t Price of the Product :";
                cin >> p;
                cout << "\n\t\t Discount on the Product :";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t Record Edited ";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found!";
        }
    }
}

void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t Delete product";
    cout << "\n\n\t Enter Product Code: ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File doesn't exist!";
    }

    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t Product deleted successfully";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " "
                      << "dis"
                      << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found!";
        }
    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|______________________________________\n";
    cout << "ProNo \t\t Name\t\t Price \n";
    cout << "\n\n|______________________________________\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping ::receipt()
{
    
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total=0;


    cout << "\n\n\t\t\t\t RECIEPT ";
    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "\n\n Empty Database!";
    }

    else
    {
        data.close();
        list();
        cout << "\n________________________________________\n";
        cout << "\n                                        \n";
        cout << "\n        Please place your order         \n";
        cout << "\n                                        \n";
        cout << "\n________________________________________\n";
        do{
            start:
            cout<<"\n\n Enter Product code: ";
            cin>>arrc[c];
            cout<<"\n\n Enter the product Quantity :";
            cin>>arrq[c];
            for (int i=0; i<c; i++){
                if (arrc[c]==arrc[i]){
                    cout<<"\n\n Duplicate Product Code. Please try again";
                    goto start;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product? If yes then press Y else no";
            cin>>choice;
        }
        while(choice=='y');
        cout << "\n\n\t\t\t________________RECIEPT________________\n";
        cout<<"\nProduct No \t Product Name \t Product Quantity \t Price \t Amount \t Amount with discount \n";

        for(int i=0; i<c; i++){
            data.open("database.txt", ios::in);
            data>>pcode>>pname>>price>>dis;

            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    cout<<"\n\n__________________________________________________";
    cout<<"\n Total Amount : "<<total;
}

int main() {
    shopping s;
    s.menu();
}