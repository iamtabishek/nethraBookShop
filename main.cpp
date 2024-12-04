#include <iostream>
#include<unistd.h>
#include<fstream>
#include<string>
using namespace std;

const int maxBooks=50;
const int maxOrders=50;

// Structure to represent a book
struct book
{
    int id;
    string Book_Name;
    double Book_Price;

}x[maxBooks];

// Structure to represent an order
struct order
{
    string Order_Name;
    int Order_Quatity;
    int Order_Price;

}y[maxOrders];


// Function prototypes

void Header ();
void Login_Portal();
void Bookshop_Details();
void Admin_Login_Portal ();
void Admin_Portal();
void Customer_Login_Portal() ;
void Customer_Portal ();
void Books();
void Admin_Books();
void Add_Book();
void Make_Order();
void View_Order();



void Admin_Login_Portal ()
{
    system("cls");
    Header();
    string Admin_UName = "adminmiru";
    string Admin_Password = "abc123";
    string Admin_UName_IN;
    string Admin_Password_IN;

    cout<<"**++=== Log in as an Admin ===++**\n\n";

    cout<<"User Name: ";
    cin>>Admin_UName_IN;

    cout<<"Password: ";
    cin>>Admin_Password_IN;

    if (Admin_UName_IN==Admin_UName && Admin_Password_IN==Admin_Password)
    {
        cout<<"\n";
        cout<<"Login Successfully as an Admin. \n";
        sleep(2);
        system("cls");
        Admin_Portal();

    }
    else {
        cout << "\n!!! Invalid username or password. Please try again !!!\n";
        sleep(1);
        system("cls");

        for (int i=1; i<=5; i++)
        {
            Header();
            cout<<"**++=== Log in as an Admin ===++**\n\n";
            cout<<"User Name: ";
            cin>>Admin_UName_IN;

            cout<<"Password: ";
            cin>>Admin_Password_IN;

            if (Admin_UName_IN==Admin_UName && Admin_Password_IN==Admin_Password)
            {
                cout<<"Login Successfully as an Admin. \n";
                sleep(2);
                system("cls");
                Admin_Portal();

                break;
            }
            else {
                cout << "\n!!! Invalid username or password. Please try again !!!\n";
                sleep(2);
                system("cls");
            }
        }
    }
}

void Customer_Login_Portal()
{
    system("cls");
    string Customer_UName= "miru";
    string Customer_Password= "mithu123";
    string Customer_UName_IN;
    string Customer_Password_IN;

    Header();

    cout<<"**++=== Log in as a Customer ===++**\n\n";

    cout<<"User Name : ";
    cin>>Customer_UName_IN;

    cout<<"Password : ";
    cin>>Customer_Password_IN;

    if(Customer_UName_IN==Customer_UName && Customer_Password_IN==Customer_Password)
    {
        cout<<"\n";
        cout<<"Login Successfully as a Customer. \n";
        sleep(2);
        system("cls");
        Customer_Portal();
    }
    else
    {
        cout<<"\n!!! Invalid username or password. Please try again !!!\n";
        sleep(1);
        system("cls");
        Header();
        for(int x=1; x<=5; x++)
        {
            cout<<"\n";
            cout<<"**++=== Log in as a Customer ===++**\n\n";

            cout<<"User Name : ";
            cin>>Customer_UName_IN;

            cout<<"Password :";
            cin>>Customer_Password_IN;

            if(Customer_UName_IN==Customer_UName && Customer_Password_IN==Customer_Password)
            {
                cout<<"*== Login Successfully as a Customer ==*";
                sleep(1);
                Customer_Portal();
                break;
            }
            else
            {
                cout<<"\n!!! Invalid username or password. Please try again !!!\n";
                sleep(2);
                system("cls");
            }
        }
    }
}

void Login_Portal()
{
    int l;
    cout<<"Type 0 for Log in as an Admin\n"
          "Type 1 for Log in as a Customer\n\n"
          "Enter your choice: ";;
    cin>>l;

    switch(l)
    {
        case 0:
            Admin_Login_Portal();
            break;

        case 1:
            Customer_Login_Portal();
            break;
    }
}

void Customer_Portal ()
{
    int d;
    Header();

    cout<<"**++=== Customer ===++**\n\n"
          "Type 0 for Books \n"
          "Type 1 for About Book Shop \n"
          "Type 2 for Logout \n"
          "Type 3 for Quit \n\n "
          "Enter your choice: ";
    cin>>d;

    switch (d)
    {
        case 0:
            Books();
            break;

        case 1:
            Bookshop_Details();
            break;

        case 2:
            system("cls");
            cout<<"Logging out...";
            sleep(2);
            system("cls");

            Header();
            Login_Portal();
            break;

        case 3:
            system("cls");
            Header();
            cout<<"=** Thank you for choosing Nethra. We look forward to serving you again soon! **=";
            sleep(2);
    }
    system("cls");
}

void Admin_Portal()
{
    int a;
    Header();
    cout<<"**++=== Admin ===++**\n\n"
          "Type 0 for Add Books \n"
          "Type 1 for View Book \n"
          "Type 2 for Orders \n"
          "Type 3 for Logout\n"
          "Type 4 for Exit\n\n"

          "Enter your choice  ";
    cin>>a;
    switch (a)
    {
        case 0 :
            Add_Book();
            break;

        case 1 :
            Admin_Books();
            break;

        case 2 :
            View_Order();
            break;

        case 3 :
            system("cls");
            cout<<"Logging out...";
            sleep(2);
            system("cls");

            Header();
            Login_Portal();
            break;

        case 4 :
            system("cls");
            Header();
            cout<<"=** Thank you for choosing Nethra. We look forward to serving you again soon! **=";
            sleep(2);
    }
}

void Header ()
{
    //Welcome Message
    cout<<"\n";
    cout <<"*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*\n";
    cout << "\n------------------------------------------------------------------------------\n\n";
    cout << "  ****=========       Nethra Book Shop Management         =========****\n";
    cout<< "                              Kandy, Sri Lanka                             ";
    cout << "\n------------------------------------------------------------------------------\n\n";
    cout << "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*\n\n\n\n";
}

void Make_Order()
{
    int discount;
    int c;

    int total = 0;
    ofstream Order_List;

    Header();
    Order_List.open("make_order.txt",ios::trunc);

    cout<<"**++=== Book Details ===++** "<<endl;
    cout<<"NOTE===:- Type 'Q' in the name field to exit"<<endl<<endl;

    for(int v=0; v<5; v++)
    {
        cout<<"Book's Name : ";
        cin>>(y[v].Order_Name);
        cout<<"\n";

        if(y[v].Order_Name == "Q")
        {
            break;
        }

        cout<<"Quantity: ";
        cin>>(y[v].Order_Quatity);

        cout<<"\n";

        cout << "Price: SLR ";
        cin >> (y[v].Order_Price);
        total += y[v].Order_Quatity * y[v].Order_Price;

        Order_List<<"Book's Name      : "<<y[v].Order_Name<<endl;
        Order_List<<"Quantity         : "<<y[v].Order_Quatity<<endl;
        Order_List<<"Price            : LKR "<<y[v].Order_Price <<"\n"<< endl;

        cout<<"\n";
    }

    cout<<"Total Amount: SLR " <<total<< endl;
    cout<<"\n";
    if(1000 < total <= 1500)
    {
        discount = total - 150;
        cout<<"Final Amount: SLR "<<discount<<endl;

    }
    else if(1500 < total <= 2500)
    {
        discount = total - 350;
        cout<<"Final Amount: SLR "<<discount<<endl;

    }
    else if(2500 < total <= 5000)
    {
        discount = total - 500;
        cout<<"Final Amount: SLR "<<discount<<endl;

    }
    else if (total>5000)
    {
        discount = total - 800;
        cout<<"Final Amount: SLR "<<discount<<endl;

    }
    Order_List<<"Total Amount   :SLR "<<total<<endl;
    Order_List<<"Final Amount   :SLR "<<discount<<endl;
    Order_List.close();
    cout<<"\n *=== Order Received ===*"<<endl;
    sleep(2);

    cout<<"\n\n\nType 0 for Menu \n"
          "Type 1 for Logout \n"
          "Type 2 for  Exit\n\n> "
          "Enter your choice: ";
    cin>>c;

    switch (c)
    {
        case 0 :
            system("cls");
            Customer_Portal();

        case 1 :
            system("cls");
            cout<<"Logging out...";
            sleep(2);
            system("cls");

            Header();
            Login_Portal();
            break;

        case 2 :
            system("cls");
            Header();
            cout<<"=** Thank you for choosing Nethra. We look forward to serving you again soon! **=";
            sleep(2);
            break;
    }
}

void View_Order()
{
    int g;
    system("cls");
    Header();
    cout<<"Type 0 for Orders\n\n"<<endl;
    cout<<"Enter your choice: ";
    cin>>g;

    cout<<"\n";
    switch (g)
    {
        case 0 :
            string text;
            ifstream readfile("make_order.txt");
            cout<<"**++=== Order ===++**\n\n";
            while(getline(readfile,text))
            {
                cout<<text<<endl;
            }
            readfile.close();
    }
    int f;
    cout<<"\n\n\nType 0 for Menu \n"
          "Type 1 for Logout \n"
          "Type 2 for Quit \n "
          "Enter your choice:  ";

    cin>>f;
    switch (f)
    {
        case 0 :
            system("cls");
            Admin_Portal();

        case 1 :
            system("cls");
            cout<<"Logging out...";
            sleep(2);
            system("cls");

            Header();
            Login_Portal();
            break;

        case 2 :
            system("cls");
            Header();
            cout<<"=** Thank you for choosing Nethra. We look forward to serving you again soon! **=";
            sleep(2);
            break;
    }
}

void Add_Book()
{
    int k;
    int j;
    string z;

    system("cls");
    Header();

    cout<<"Book Count: ";
    cin>>k;

    cout<<"\n";

    system("cls");
    ofstream book;
    book.open("books.txt",ios::trunc);
    cout<<"Provide information about the book you're interested in purchasing :\n\n"<<endl;
    for (j=1; j<=k; j++)
    {
        cout<<"Book's Name : ";
        cin>>(x[j].Book_Name);
        cout<<"Price       : SLR ";
        cin>>(x[j].Book_Price);

        cout<<"\n";
        book<<"Book's Name   : "<<x[j].Book_Name<<endl;
        book<<"Price         : SLR "<<x[j].Book_Price<<"\n"<<endl;
        cout<<"\n";
    }
    book.close();

    cout<<"\n\n\nType 0 for Menu \n"
          "Type 1 for Logout \n"
          "Type 2 for Exit\n\n"
          "Enter your choice: ";

    int g;
    cin>>g;
    switch (g)
    {
        case 0 :
            system("cls");
            Admin_Portal();

        case 1 :
            system("cls");
            cout<<"Logging out...";
            sleep(2);
            system("cls");

            Header();
            Login_Portal();
            break;

        case 2 :
            system("cls");
            Header();
            cout<<"=** Thank you for choosing Nethra. We look forward to serving you again soon! **=";
            sleep(2);
            break;
    }
}

void Bookshop_Details ()
{
    system("cls");
    Header();
    cout<<"Welcome to Nethra Book Shop, a haven for bibliophiles nestled in the heart of Kandy, Sri Lanka, "
          "at 282/A DS Senanayake Road. Our bookshop is more than just a store; it's a literary sanctuary "
          "where the pages of countless stories come to life. \n"
          "\n"
          "At Nethra Book Shop, we take pride in offering a diverse and curated collection of valuable books "
          "catering to schools, educational institutes, and our cherished daily customers. Whether you're on "
          "a quest for academic knowledge or seeking the pleasure of a good read, our shelves hold treasures "
          "waiting to be explored.\n"
          "\n"
          "Established with a passion for literature, Nethra Book Shop has become a beacon for those who "
          "appreciate the magic that unfolds between the covers of a book. Our commitment goes beyond providing "
          "a vast range of books; we are dedicated to enhancing the overall reading experience for our customers.\n"
          "\n"
          "Convenience and customer satisfaction are at the forefront of our priorities. To meet the evolving "
          "needs of our patrons, we are thrilled to announce our transition towards automation. By embracing "
          "technology, we aim to streamline our business processes, ensuring accurate and prompt service. This "
          "transformation aligns with our vision to not only reduce costs but also to elevate the quality of "
          "service we provide.\n"
          "\n"
          "As we embark on this exciting journey, we extend our gratitude to our loyal customers who have been "
          "an integral part of our story. Join us at Nethra Book Shop, where the love for books meets the efficiency "
          "of modernity, creating an unparalleled experience for all who step through our doors.\n"
          "\n"
          "For any inquiries, feel free to contact us at 076 393 9592 or reach out via email at nethrabookshopkandy@gmail.com. "
          "Thank you for choosing Nethra Book Shop — your literary destination in Kandy.";

    cout<<"\n\n\nType 0 for Exit\n"
          "Type 1 for Menu\n\n "
          "Enter your choice: ";

    int e;
    cin>>e;

    switch (e)
    {
        case 0 :
            system("cls");
            Header();
            cout<<"=** Thank you for choosing Nethra. We look forward to serving you again soon! **=";
            sleep(2);

            break;

        case 1:
            system("cls");
            Customer_Portal();
            break;
    }
}

void Books()
{
    system("cls");
    Header();
    cout<<"|||***=== Discount Details ===****|||\n\n"<<endl;
    cout<<"|||Total Amount||| \t\t |||Discount|||"<<endl;
    cout<<"SLR 1000 to SLR 1500 \t\t -SLR 150"<<endl;
    cout<<"SLR 1500 to SLR 2500 \t\t -SLR 350"<<endl;
    cout<<"SLR 2500 to SLR 5000 \t\t -SLR 500"<<endl;
    cout<<"SLR 5000 to ABOVE    \t\t -SLR 800"<<endl;
    cout<<"\n";

    int c;

    string text;
    ifstream readfile("books.txt");
    while(getline(readfile,text))
    {
        cout<<text<<endl;
    }
    readfile.close();

    cout<<"Type 0 for Make Order \n"
          "Type 1 Menu \n"
          "Type 2 for Quit\n\n "
          "Enter your choice: ";
    cin>>c;
    switch (c)
    {
        case 0 :
            Make_Order();

        case 1 :
            system("cls");
            Header();
            cout<<"=** Thank you for choosing Nethra. We look forward to serving you again soon! **=";
            sleep(2);
            system("cls");
            Customer_Portal();

            break;

        case 2 :
            system("cls");
            Customer_Portal();
            break;
    }
}

void Admin_Books()
{
    system("cls");
    string text;
    ifstream readfile("books.txt");
    cout<<"**++=== Books ===++**\n\n";

    while(getline(readfile,text))
    {
        cout<<text<<endl;
    }
    int d;
    readfile.close();
    cout<<"\n\n\nType 0 for Menu \n"
          "Type 1 for Logout \n"
          "Type 2 for Exit\n\n"
          "Enter your choice:  ";
    cin>>d;

    switch (d)
    {
        case 0 :
            system("cls");
            Admin_Portal();

        case 1 :
            system("cls");
            cout<<"Logging out...";
            sleep(2);
            system("cls");
            Header();
            Login_Portal();
            break;

        case 2 :
            system("cls");
            Header();
            cout<<"=** Thank you for choosing Nethra. We look forward to serving you again soon! **=";
            sleep(2);
            break;
    }
}


int main () {
    Header();
    Login_Portal();

    return 0;
}