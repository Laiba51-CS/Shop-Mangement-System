#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <stdio.h>

using namespace std;

//_______________________________________Data structures__________________________________________________

const int users = 10;
string usernamea[2] = {"ADMIN", "CUSTOMER"};
string passworda[2] = {"123", "321"};
string rolea[2] = {"ADMIN", "CUSTOMER"};

string revie[20];
int rr = 0;
string password;
int count = 0;

const int size = 20;
string namea[size];
int pricea[size];
int quanta[size];
int counter = 0;

int n, stockprice1;
int check = 1;
string rev;

const int Asize = 20;
string p_name[Asize];
int p_quant[Asize];
int p_price[Asize];
int buy = 0;

string buyername[size];
string address[size];
string phoneNumber[size];
int bill = 0;

string cust[size];
string orderAdd[size], orderP[size], orderQuant[size];
int od = 0, orderOK[size];

float disc, tprice;
string name;
int soldprice1, discount, price;
string pitem;
fstream file;

//_______________________________________Data structures end_______________________________________________
//_______________________________________function prototypes_______________________________________________
void header();
string who();
void adminModule();
void adduser(string username, string password, string role);
void clearscreen();
string mainmenu();
void addProduct();
void order();
void viewproducts();
string things(int price);
void displayprofit();
void specialdiscount();
void display();
void sorting();
void swaping(int index1, int index2);
void customerheader();
char adminmenu();
void adminthings();
void addReveiw();
void viewReviews();
string parse_data(string line, int field);
void storeData();
void readData();
void availableProducts();
void buyProduct();
void billpayment();
void manageOrder();
void soldItems();

//___________________________________________main starts___________________________________________________
main()
{
    readData();
    while (true)
    {
        system("cls");
        header();

        string a = who();

        if (a == "ADMIN" || a == "admin")
        {
            system("cls");

            cout << endl;
            cout << " *** Welcome to sports shop management system ***" << endl;

            while (true)
            {
                string op = mainmenu();

                if (op == "1")
                {

                    // add products code

                    addProduct();
                }
                else if (op == "2")
                {

                    // if its press one on first attempts
                    if (counter == 0)
                    {
                        cout << " Plz enter some data to view...!" << endl;
                    }
                    else
                    {
                        // when customer enter the product then the this code show the enter the products
                        // view products

                        viewproducts();
                    }
                    cout << " Press any Key to Continue ....";
                    getch();
                }

                else if (op == "3")
                {
                    // orders

                    manageOrder();
                }
                else if (op == "4")
                {
                    // stock
                    char a;
                    int rpro, tpro;
                    int quantity;
                    cout << " Enter name of products remaining : ";
                    cin >> name;
                    cout << " Enter toatal number of products : ";
                    cin >> rpro;
                    cout << " Enter total number of product from stock : ";
                    cin >> tpro;
                    cout << " Enter quantity" << endl;
                    cin >> quantity;
                    int products = tpro - rpro;
                    cout << " Your reaming products from stock " <<"\t\t" << products << " "
                      << " from total product of" << name << endl;
                    cout << " Press any key to continue";
                    getch();
                }
                else if (op == "5")
                {
                    soldItems();
                }

                else if (op == "6")
                {

                    if (counter == 0)
                    {
                        cout << " Plz enter some products to see loss" << endl;
                    }
                    else
                    {
                        

                        displayprofit();
                    }
                    cout << " Press any Key to Continue ....";
                    getch();
                }
                else if (op == "7")
                {
                    float tprice;
                    int a;
                    char b;

                    cout << " Want to give profit on special day( y/n)" << endl;
                    cout << " Press1.to give special discount" << endl;
                    cout << " Press2.to give any discount" << endl;
                    cin >> a;
                    if (a == 1)
                    {
                        specialdiscount();
                    }
                    if (a == 2)
                    {
                        cout << " Enter name of item you want to give discount " << endl;
                        cin >> name;
                        cout << " How many discount in  percent you want to give on product" << endl;
                        cin >> discount;
                        cout << " Enter the price of item" << endl;
                        cin >> price;
                        disc = price / (discount * 100.0);
                        tprice = disc - price;
                        cout << " The price after discount is" << tprice << endl;
                        cout << " Press any key to continue" << endl;
                        cin >> b;
                        getch();
                    }
                }
                else if (op == "8")
                {
                    cout << " Showing you products by high price to low";
                    // sorting in arrays with price
                    sorting();
                    display();
                }
                else if (op == "9")
                {
                    viewReviews();
                }
                else if (op == "10")
                {
                    break;
                }
                else
                {
                    cout << " Invalid Option! " << endl;
                }
                system("cls");
            }
        }

        if (a == "CUSTOMER" || a == "customer")
        {

            while (true)
            {
                char y;
                char a;
                cout << " *** Welcome to sports shop management system ***" << endl;
                customerheader();
                y = adminmenu();
                if (y == '1')
                {
                    cout << " 1. Check available products" << endl;
                    cout << " 2. Buy Product " << endl;
                    cout << " 3. Exit" << endl;
                    cin >> y;

                    if (y == '1')
                    {
                        availableProducts();
                    }
                    else if (y == '2')
                    {
                        buyProduct();
                    }
                }

                else if (y == '2')
                {
                    int i = 0;
                    string name;
                    order();
                }
                else if (y == '3')
                {
                    billpayment();
                }
                else if (y == '4')
                {
                    system("cls");
                    addReveiw();
                }
                else if (y == '5')
                {
                    break;
                }
            }
        }

        system("cls");
        cout << " \n Do You Want to exit from Program..(y/n)...";
        char s;
        cin >> s;
        if (s == 'y' || s == 'S')
        {
            break;
        }
    }
    storeData();
}
// function to manage the order add by the customers and the after completing the data 
void manageOrder()
{
    char op;
    system("cls");
    adminModule();
    cout << " Manage Orders ... " << endl;
    cout << "__________________________________________________________" << endl;

    cout << " 1. Orders completed " << endl;
    cout << " 2. Orders Pending " << endl;
    cout << " 3. Exit" << endl;
    cout << " Your Option..";
    cin >> op;

    if (op == '1')
    {
        cout << "Customer Name\tProduct\tQuantity\tAddress" << endl;
        for (int i = 0; i < od; i++)
        {
            if (orderOK[i] == 1)
            {
                cout << cust[i] << "\t" << orderP[i] << "\t" << orderQuant[i] << "\t" << orderAdd[i] << endl;
            }
        }
    }
    else if (op == '2')
    {
        int n = 1;
        char flag;
        cout << " Customer Name\tProduct\tQuantity\tAddress" << endl;
        for (int i = 0; i < od; i++)
        {
            if (orderOK[i] == 0)
            {
                cout << n << " " << cust[i] << "\t" << orderP[i] << "\t" << orderQuant[i] << "\t" << orderAdd[i] << endl;
                cout << " Press 1 to complete order " << endl;
                cin >> flag;
                if (flag == '1')
                {
                    orderOK[i] = 1;
                }
                n++;
            }
        }
    }
    cout << " Press any key to continue....";
    getch();
}

//___________________________________________main ends______________________________________________________

//___________________________________________Function implementations_______________________________________
void header()
{
    cout << endl;
    cout << "****************************************************************************************************" << endl;
    cout << "        **********************      SPORTS SHOP MANAGEMENT SYSTEM        ****************" << endl;
    cout << "****************************************************************************************************" << endl;
}

string who()
{
    string username;
    cout << " Login page >> ..... " << endl;
    cout << "_______________________________________________________" << endl
         << endl;
    while (true)
    {
        cout << " Enter username..............(admin)&(customer) : ";
        cin >> username;

        cout << " Enter password..............(123)&(321) : ";
        cin >> password;

        if (password == "123" && (username == "ADMIN" || username == "admin"))
        {
            break;
        }
        else if (password == "321" && (username == "CUSTOMER" || username == "customer"))
        {
            break;
        }
        cout << " Invalid Input!" << endl;
    }

    return username;
}

void adduser(string username, string password, string role)
{
    if (count <= users)
    {
        usernamea[users] = username;
        passworda[users] = password;
        rolea[users] = role;
        count = count + 1;
    }
}

void clearscreen()
{
    cout << "press any key to success" << endl;

    system("cls");
}

void adminModule()
{
    cout << endl;
    cout << "**********************************************************" << endl;
    cout << "                     ADMIN MODULE                         " << endl;
    cout << "**********************************************************" << endl;
    cout << endl;
}

string mainmenu()

{
    string x;
    adminModule();
    cout << " MENU >> " << endl;
    cout << "__________________________________________________________" << endl;
    cout << " 1. Add products and categories" << endl;
    cout << " 2. Edit and view products and categories" << endl;
    cout << " 3. Manage orders" << endl;
    cout << " 4. Manage stock" << endl;
    cout << " 5. sold items" << endl;
    cout << " 6. Profit and loss" << endl;
    cout << " 7. Discount" << endl;
    cout << " 8. Sorted prices" << endl;
    cout << " 9. Reviews of customer" << endl;
    cout << " 10. Exit" << endl;
    cout << "__________________________________________________________" << endl;
    cout << "\n Your option....................? ";
    cin >> x;
    return x;
}

void addProduct()
{
    system("cls");
    adminModule();
    cout << " Add Products >> " << endl;
    cout << "__________________________________________________________" << endl;
    cout << endl;
    cout << " How many products you want to enter : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        check = check + 1;
         file.open("data.txt", ios::out);
        cout << endl;
        cout << " Enter product name : ";
        cin >> namea[counter];
        cout << " Add product price : ";
        cin >> pricea[counter];
        cout << " Add quantity of product : ";
        cin >> quanta[counter];

        counter++;

         file << namea[i] << " " << pricea[i] << " " << quanta[i] << endl;
         file.close();
    }
    cout << " Press any Key to Continue ....";
    getch();
}

void viewproducts()
{

    string name, newname;
    int price, newprice, newquant;
    char b;
    system("cls");
    adminModule();
    cout << " View Products >> " << endl;
    cout << "__________________________________________________________" << endl;
    cout << endl;

    cout << "Productname\t"<< "Price\t" << "Quantity \t" << endl;

    for (int i = 0; i < counter; i++)
    {

        file >> namea[i] >> pricea[i] >> quanta[i];

        cout << namea[i] << "\t\t" << pricea[i] << "\t\t" << quanta[i] << endl;
    }

    cout << "\n You want to edit product (y/n) : ";
    cin >> b;
    int s = 0;
    if (b == 'y')
    {
        cout << " Enter name of previous product you want to edit : ";
        cin >> name;

        for (int i = 0; i < counter; i++)
        {
            if (name == namea[i])
            {
                cout << endl;
                cout << " Enter new name : ";
                cin >> namea[i];
                cout << " Enter new price : ";
                cin >> pricea[i];
                cout << " Enter quantity : ";
                cin >> quanta[i];
                break;
            }
            s++;
            cout << "\n"
                 << namea[i] << "\t\t" << pricea[i] << "\t\t" << quanta[i] << endl;
            if (s == counter)
            {
                cout << " No such products to Show or to Edit " << endl;
            }
        }
    }
}
string things(int price)
// recomended items
{
    char n;
    int h;
    int p[10];
    string add[10];
    int i;
    int address;
    string customer;
    cout << " Your enter  products are: ";
    cout << namea[i] << "\t\t" << pricea[i] << endl;
    cout << " names  \t\t   prices" << endl;
    cout << "  1ball  \t\t   40$ " << endl;
    cout << "  1bat    \t\t  500$ " << endl;
    cout << "  football \t\t 800$" << endl;
    cout << " badminten \t\t 1000$ " << endl;
    cout << " Enter more products(y/n) " << endl;
    cin >> n;

    if (n == 'y')
    {
        cout << " How many products you want to enter ";
        cin >> h;

        for (i = 0; i < h; i++)
        {

            cout << "\n Enter the product to show customer : ";
            cin >> add[i];
            cout << " Enter price : ";
            cin >> p[i];
            cout << add[i] << "\t\t" << p[i] << endl;
        }
    }
}
void displayprofit()
{
    // int n;

    // float profit, tprofit;
    // cout << "how many products you want to see profit";
    // cin >> n;

    // cout << "enter the name of product" << endl;
    // cin >> pitem;
    // cout << "in which price you bought product from stock" << endl;
    // cin >> stockprice1;
    // cout << "enter quantity";
    // cin >> quant;
    // cout << "in which price you sold product" << endl;
    // cin >> soldprice1;

    // // if (pitem == namea[0])

    // profit = soldprice1 - stockprice1;
    // tprofit = profit * quant;

    // cout << "your profit on" << pitem << "profit is" << tprofit;

    int total_items = 0;
    int total_price = 0;

    system("cls");
    adminModule();
    cout << " Profit Lose >> " << endl;
    cout << "__________________________________________________________" << endl
         << endl;

    cout << " Product\tQuantity\tPrice\tProfit" << endl;
    for (int idx = 0; idx < buy; idx++)
    {
        cout << " " << p_name[idx] << "\t" << p_quant[idx] << "\t\t" << p_price[idx] << "\t" << p_price[idx] * 0.2 << endl;
        total_items = total_items + p_quant[idx];
        total_price = total_price + p_price[idx];
    }
    cout << endl;
    cout << " Total Items sold are " << total_items << endl;
    cout << " Total Price : " <<  total_price << endl;
    cout << " Total Profit : " << total_price * 0.2 << endl;
}
void specialdiscount()
{

    int tprice;
    string day;
    int disc;
    float discount;
    fstream newfile;
    newfile.open("discount.txt", ios::out);
    cout << "enter the day you want to give discount" << endl;
    cin >> day;

    cout << "enter price   " << endl;
    cin >> tprice;

    cout << "how many discount you want to give" << endl;
    cin >> disc;
    file << day << " " << tprice << " " << disc;
    file.close();
    newfile.open("discount.txt", ios::in);
    if (day == "friday")
    {
        discount = tprice * disc / 100.0 - tprice;
        cout << "discount is" << discount << endl;
    }
    if (day == "sunday")
    {
        discount = tprice - (tprice * disc / 100.0);
        cout << "discount is " << discount << endl;
    }
    if (day == "monday")
    {
        discount = tprice - (tprice * disc / 100.0);
        cout << "discount is " << discount << endl;
    }
    if (day == "tuesday")
    {
        discount = tprice - (tprice * disc / 100.0);
        cout << "discount is " << discount << endl;
    }
    if (day == "wednesday")
    {
        discount = tprice - (tprice * disc / 100.0);
        cout << "discount is " << discount << endl;
    }
    if (day == "thursday")
    {
        discount = tprice - (tprice * disc / 100.0);
        cout << "discount is " << discount << endl;
    }
    if (day == "friday")
    {
        discount = tprice - (tprice * disc / 100.0);
        cout << "discount is " << discount << endl;
    }
    if (day == "saturday")
    {
        discount = tprice - (tprice * disc / 100.0);
        cout << "discount is " << discount << endl;
    }

    else
    {
        cout << "discount is not applied";
        cout << "payable price is" << tprice;
    }
    // file.close();
}
void sorting()
{
    // sorting
    int b;
    int max = -1;

    for (int i = 0; i < counter; i++)
    {
        max = -1;
        for (int j = i; j < counter; j++)
        {
            if (max < pricea[j])
            {
                max = pricea[j];
                b = j;
            }
        }
        swaping(i, b);
    }
}
void swaping(int index1, int index2)
{
    int temp;
    string change;

    temp = pricea[index1];
    pricea[index1] = pricea[index2];
    pricea[index2] = temp;

    change = namea[index1];
    namea[index1] = namea[index2];
    namea[index2] = change;

    temp = quanta[index1];
    quanta[index1] = quanta[index2];
    quanta[index2] = temp;
}

void display()
{
    system("cls");
    customerheader();
    cout << " Sorted Prices ..... " << endl;
    cout << "_______________________________________________________" << endl;
    cout << endl;
    cout << "\tProductname\t"<< "\tPrice\t"<< "\tQuantity \t" << endl;
    for (int idx = 0; idx < counter; idx++)
    {
        cout <<"\t"<< namea[idx] << "\t" << pricea[idx] << "\t" << quanta[idx] << endl;
    }
    cout << " Press Any Key to Continue ....";
    getch();
}

void customerheader()
{
    system("cls");
    cout << endl;
    cout << "*******************************************************************" << endl;
    cout << "                      CUSTOMER MODULE                                 " << endl;
    cout << "*********************************************************************" << endl;
}

char adminmenu()
{
    char a;
    cout << "MENU" << endl;
    cout << "__________________________________________________________" << endl;
    cout << "\n 1. Buy product" << endl;
    cout << " 2. Place orders" << endl;
    cout << " 3. Bill payments" << endl;
    cout << " 4. Add Reviews" << endl;
    cout << " 5. Exit" << endl;
    cout << "\n Your Option : ";
    cin >> a;
    return a;
}

void adminthings()
{

    string items[10];
    int q, i;

    char a;

    cout << "your enter  products are: ";
    cout << namea[i] << "\t\t" << pricea[i] << endl;
    i++;
    cout << " names  \t\t   prices" << endl;
    cout << "  1ball  \t\t   40$ " << endl;
    cout << "  1bat    \t\t  500$ " << endl;
    cout << "  football \t\t 800$" << endl;
    cout << " badminten \t\t 1000$ " << endl;
    cout << " enter more products( y/n)";
    cin >> a;
    if (a == 'y')
    {
        cout << "how many products you want to enter" << endl;
        cin >> q;
        for (i = 0; i < q; i++)
        {
            cout << "enter name" << endl;
            cin >> items[i];
        }
    }
    cout << items[i] << endl;
    i++;
}

void viewReviews()
{

    system("cls");
    adminModule();
    cout << " Reviews " << endl;
    cout << "__________________________________________________________" << endl
         << endl;
    if (rr == 0)
    {
        cout << " We have no reviews to show....! " << endl;
    }
    else
    {
        for (int i = 0; i < rr; i++)
        {
            cout << revie[i] << endl;
        }
    }

    cout << " Press any key to continue....";
    getch();
}

void order()
{
    system("cls");
    customerheader();
    cout << " Place Order ..... " << endl;
    cout << "_______________________________________________________" << endl;
    int i;

    cout << " Enter your name : ";
    cin >> cust[od];
    cout << " Enter Your Address : ";
    cin >> orderAdd[od];
    cout << " Enter the Product Name : ";
    cin >> orderP[od];
    cout << " Enter the Quantity of product : ";
    cin >> orderQuant[od];

    orderOK[od] = 0;
    od++;

    cout << " Your order placed Sucessfully..." << endl;
    cout << " Press Any Key To continue...";
    getch();
}

void addReveiw()
{
    customerheader();

    cout << "\n Enter about the service and products quality( good/bad)" << endl;
    cin.ignore();
    getline(cin, revie[rr]);
    rr++;
    cout << " Press Any Key To continue...";
    getch();
}

// function for separarting data readed from file one by one as required
string parse_data(string line, int field)
{
    int commaCount = 1; // initial comma count
    string item;
    for (int x = 0; x < line.length(); x++)
    {
        if (line[x] == ',') // if find comma in file
        {
            commaCount++; // increment
        }
        else if (commaCount == field) // if comma Count and field required become same
        {
            item = item + line[x]; // than read data character by character
        }
    }

    return item; // and returning readed item
}

void readData()
{
    string line;
    fstream newfile;

    newfile.open("ItemsData.txt", ios::in);

    while (!newfile.eof())
    {
        // newfile >> line;
        getline(newfile, line);

        namea[counter] = parse_data(line, 1);
        pricea[counter] = stoi(parse_data(line, 2));
        quanta[counter] = stoi(parse_data(line, 3));

        counter++;
    }
    newfile.close();
}

void storeData()
{
    fstream newfile;
    newfile.open("ItemsData.txt", ios::out);

    for (int idx = 0; idx < counter; idx++)
    {
        newfile << namea[idx] << "," << pricea[idx] << "," << quanta[idx] << ",";
        if (idx < counter - 1)
        {
            newfile << endl;
        }
    }

    newfile.close();
}
void buyProduct()
{
    system("cls");
    customerheader();
    cout << " Buy Product ..... " << endl;
    cout << "_______________________________________________________" << endl
         << endl;
    cout << "Productname\t"
         << "Price\t"
         << "Quantity \t" << endl;
    for (int idx = 0; idx < counter; idx++)
    {
        cout << " " << idx + 1 << ". " << namea[idx] << "\t" << pricea[idx] << "\t" << quanta[idx] << endl;
    }
    cout << " Enter the product number you want to buy : ";
    int num;
    cin >> num;

    num = num - 1;

    cout << " Product Name is : " << namea[num] << endl;
    p_name[buy] = namea[num];
    cout << " Price of Product is : " << pricea[num] << endl;
    cout << " Enter the quantity of product : ";
    cin >> p_quant[buy];
    p_price[buy] = p_quant[buy] * pricea[num];
    cout << " You have to pay : " << p_price[buy] << endl;
    buy++;

    cout << " Press any key to continue....";
    getch();
}

void availableProducts()
{
    system("cls");
    customerheader();
    cout << " Available Product ..... " << endl;
    cout << "_______________________________________________________" << endl
         << endl;
    cout << "Productname\t"
         << "Price\t"
         << "Quantity \t" << endl;
    for (int idx = 0; idx < counter; idx++)
    {
        cout << " " << namea[idx] << "\t" << pricea[idx] << "\t" << quanta[idx] << endl;
    }

    cout << " Press any key to continue....";
    getch();
}

void billpayment()
{
    char a;
    system("cls");
    customerheader();
    cout << " Bill Payment ..... " << endl;
    cout << "_______________________________________________________" << endl;

    cout << " 1. Pay bill from card" << endl;
    cout << " 2. Pay bill from cash " << endl;
    cout << " Select One Payment method number : ";
    cin >> a;
    cout << endl;

    cout << " Enter your name : ";
    cin >> buyername[bill];
    cout << " Enter your address : ";
    cin.ignore();
    getline(cin, address[bill]);
    while (true)
    {
        cout << " Enter your number : ";

        cin >> phoneNumber[bill];
        if (phoneNumber[bill].length() == 11)
        {
            break;
        }
        cout << " Invalid Phone Number !" << endl;
    }
    cout << " You Payed Bill Succesfully....\n"
         << endl;
    bill++;
    cout << " Press any key to continue....";
    getch();
}

void soldItems()
{
    system("cls");
    adminModule();
    cout << " Sold Items >> " << endl;
    cout << "__________________________________________________________" << endl
         << endl;

    if (buy == 0)
    {
        cout << " NO Item is Sold so far...! " << endl;
    }
    else
    {
        cout << " Product\tQuantity\tPrice" << endl;
        for (int idx = 0; idx < buy; idx++)
        {
            cout << " " << p_name[idx] << "\t" << p_quant[idx] << "\t\t" << p_price[idx] << endl;
        }
    }
    cout << " Press any key to continue....";
    getch();
}
