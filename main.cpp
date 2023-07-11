#include<iostream>
#include<fstream>
using namespace std;

class shopping
{
    private:
        int pcode;
        string pname;
        float price;
        float dis;

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

void shopping :: menu()
{
    m:
    int choice;
    string email, password;

    cout<<"\t\t\t\t________________________\n";
    cout<<"\t\t\t\t                        \n";
    cout<<"\t\t\t\t       Main Menu        \n";
    cout<<"\t\t\t\t                        \n";
    cout<<"\t\t\t\t________________________\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t|  1) Administrator    |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t|  2) Buyer            |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t|  3) Exit             |\n";
    cout<<"\t\t\t\t|______________________|\n";
    cout<<"\t\t\t\t Please Select: ";
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
            cout<<"\t\t\t\t Please Login: \n";
            cin>>email;
            cout<<"\t\t\t\t Password: \n";
            cin>>password;

            if(email=="abc@gmail.com" && password=="1234567890")
            {
                administrator();
            }
            else{
                cout<<"\t\t\t\t Invalid email/password \n";
            }
             break;
        }

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
            cout<<"\t\t\t\tPlease select from the given options\n";
        }
    }
    goto m;
}

void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\n\t\t\t\t Administrator Menu \n";
    cout<<"\t\t\t\t|____1) Add the product _______|\n";
    cout<<"\t\t\t\t|____2) Modify the product ____|\n";
    cout<<"\t\t\t\t|____3) Delete the product ____|\n";
    cout<<"\t\t\t\t|____4) Back to main menu______|\n";
    cout<<"\t\t\t\tPlease Select: \n";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            add();
            break;
        }
        case 2:
        {
            edit();
            break;
        }
        case 3:
        {
            rem();
            break;
        }
        case 4:
        {
            menu();
            break;
        }
        default:
        {
            cout<<"\t\t\t\tPlease select from the given options\n";
        }
    }
    goto m;
}

void shopping :: buyer()
{
    m:
    int choice;
    cout<<"\n\n\t\t\t\t ____Buyer's Menu____\n";
    cout<<"\t\t\t\t                     \n";
    cout<<"\t\t\t\t|____1) Buy product__\n";
    cout<<"\t\t\t\t                     \n";
    cout<<"\t\t\t\t|____2) Go Back______\n";
    cout<<"\t\t\t\t Enter your choice: \n";
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
            receipt();
            break;
        }
        case 2:
        {
            menu();
        }
        default:
        {
            cout<<"\t\t\t\tPlease select from given options\n";
        }
    }
    goto m;
}

void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t\t Add new product \n";
    cout<<"\t\t\t\t Product code of product: \n";
    cin>>pcode;
    cout<<"\t\t\t\t Name of product: \n";
    cin>>pname;
    cout<<"\t\t\t\t Price of product: \n";
    cin>>price;
    cout<<"\t\t\t\t Discount on product: \n";
    cin>>dis;

    data.open("database.txt", ios::in);
    if(!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    }

    if(token==1)
    {
        goto m;
    }
    else
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    cout<<"\t\t\t\t Record inserted \n";
}

void shopping :: edit()
{
    fstream data, data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t\t Modify the Record \n";
    cout<<"\t\t\t\t Product code: \n";
    cin>>pkey;
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"\t\t\t\tFile doesnt exist!\n";
    }
    else
    {
        data1.open("database1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t\t\t Product new code: \n";
                cin>>c;
                cout<<"\t\t\t\t Name: \n";
                cin>>n;
                cout<<"\t\t\t\t Price: \n";
                cin>>p;
                cout<<"\t\t\t\t Discount: \n";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\t\t\t\t Record Edited \n";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
    }
    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt", "database.txt");

    if(token==1)
    {
        cout<<"\n\t\t\t\t Record not found.\n";
    }
}

void shopping :: rem()
{
    fstream data, data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t\t\t\t Delete product\n";
    cout<<"\t\t\t\t Enter the product code: ";
    cin>>pkey;
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"\t\t\t\t File doesnt exist. \n";
    }
    else
    {
        data.open("database1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\t\t\t\t Product Deleted. \n";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis;
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token==0)
        {
            cout<<"Record not found \n";
        }
    }
}

void shopping :: list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout<<"\n\n\t\t\t\t_______________________________________\n";
    cout<<"\t\t\t\tPro No. \t Name \t Price \n";
    cout<<"\n\n\t\t\t\t_______________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<"\t\t\t\t"<<pcode<<" \t "<<pname<<" \t "<<price<<" \t "<<dis<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping :: receipt()
{
    m:
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t RECIEPT \n";
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"\t\t\t\t Empty Database \n";
    }
    else
    {
        data.close();
        list();
        cout<<"\n________________________________\n";
        cout<<"\n                                \n";
        cout<<"\n      Please Place the order    \n";
        cout<<"\n                                \n";
        cout<<"\n________________________________\n";

        do
        {
            cout<<"\t\t\t\t Enter Product code: ";
            cin>>arrc[c];
            cout<<"\t\t\t\t Enter Quantity: ";
            cin>>arrq[c];
            for(int i=0; i<c; i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\t\t\t\t Duplicate Product code \n";
                    goto m;
                }
            }
            c++;
            cout<<"\t\t\t\t Do you want to but another product? Y for yes N for no\n";
            cin>>choice;
        }
        while(choice == 'y');

        cout<<"\n\n\t\t\t\t ________________RECIEPT______________\n";
        cout<<"Product no. \t Product name \t Price \t Amount \t Amount with discount \n";

        for(int i=0; i<c; i++)
        {
            data.open("database.txt", ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount = price*arrq[i];
                    dis = amount - (amount*dis)/100;
                    total = total + dis;
                    cout<<"\n"<<pcode<<" \t "<<pname<<" \t "<<arrq[i]<<" \t "<<price<<" \t "<<amount<<" \t "<<dis<<"\n";
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }
    cout<<"\n\n______________________________\n";
    cout<<"Total Amount: "<<total<<"\n";
}

int main()
{
    shopping s;
    s.menu();

    return 0;
}