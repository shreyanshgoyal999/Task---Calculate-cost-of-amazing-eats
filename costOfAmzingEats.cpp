#include <iostream>
#include <string>
using namespace std;

// Task - Calculate the cost of Amazing eats

float cost;                    // Cost before tax
float total_cost;              // total cost after tax
int order;                     // item no. that customer orderd
int no_of_meals;               // no. of meals customer orderd
int street_num;               
string fname;
string lname;
string street_name;
string city;
string province;
string phone_number;
int postal_code;
char confirm;
char isStudent;
float stud_saving;
float hst_tax;

// Array to store items in our menu
string items[] = {"Mac Float", "Sandwitch"};

// Array to store prices of items
float prices[] = {80.20, 20.45};
int sizePrices = sizeof(prices) / sizeof(prices[0]);


float round(float var)
{
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

// Function to take input customer detail 
void userInput()
{
    cout << "Enter first name : ";
    cin >> fname;
    cout << "Enter last name : ";
    cin >> lname;
    cout << "Enter Full Delivery Adress -" << endl;
    cout << "Street number : ";
    cin >> street_num;
    cout << "Street name : ";
    getline(cin >> ws, street_name);
    cout << "City : ";
    cin >> city;
    cout << "Province : ";
    cin >> province;
    cout << "Postal code : ";
    cin >> postal_code;
    cout << "Phone no. : ";
    cin >> phone_number;
}

// Function to display menu
void menu()
{
    
    cout << "Here is our Menu - " << endl;
    cout<<endl;
    cout << "Sno."<<"\t"<< "Item"<<"\t\t"<< "Price" << endl;
    cout << "-----"<<"\t"<< "--------"<<"\t"<< "------" << endl;
    for (int i = 0; i < sizePrices; i++)
    {
        cout << i + 1 <<"\t"<<items[i]<<"\t"<<"$"<< prices[i] << endl;
        
    }
}


// Function to get customer order input
void acceptOrder()
{
    cout << "Enter item no. : ";
    cin >> order;
    cout << "Enter no. of meals : ";
    cin >> no_of_meals;
}

// Function to print receipt
void printReciept()
{
    cout << "Customer Name : " << fname << " " << lname << endl;
    cout << "Customer Address : " << street_num << " " << street_name << endl;
    cout << city << " " << province << " " << postal_code << endl;
    cout << endl;

    cout << "Order"
         << "\t\t\t"
         << "Item Amount"
         << "\t\t"
         << "Item Price"
         << "\t\t"
         << "Total" << endl;
    cout << "-------------"
         << "\t\t"
         << "-----------"
         << "\t\t"
         << "----------"
         << "\t\t"
         << "-------" << endl;
    cout << items[order - 1] << "\t\t\t" << no_of_meals << "\t\t"
         << "$" << prices[order - 1] << "\t\t\t"
         << "$" << prices[order - 1] * no_of_meals << endl;
    if (isStudent == 'y' || isStudent == 'Y')
    {
        cout << "10% student saving"
             << "\t\t\t\t\t\t\t"
             << "-$" << stud_saving << endl;
    }

    cout << "\t\t\t\t\t\t"
         << "sub total"
         << "\t\t"
         << "$" << cost << endl;
    cout << "\t\t\t\t\t\t"
         << "Tax (13%)"
         << "\t\t"
         << "$" << hst_tax << endl;
    cout << "\t\t\t\t\t\t"
         << "-------" << endl;
    cout << "\t\t\t\t\t\t"
         << "Total "
         << "\t\t\t"
         << "$" << total_cost;
}

int main()
{

    userInput();
    menu:

    cout<<endl;
    menu();
    cout<<endl;

    acceptOrder();

    cout << "You Chose: " << items[order - 1] << endl;
    cout << "Quantity: " << no_of_meals << endl;

    while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N')
    {
        cout << "Press 'y' or 'Y' to confirm order" << endl;
        cout << "Press 'n' or 'N' to change order if not correct" << endl;
        cin >> confirm;
    }

    if (confirm == 'y' || confirm == 'Y')
    {
        cost = round(prices[order - 1] * no_of_meals);
        

        while (isStudent != 'y' && isStudent != 'Y' && isStudent != 'n' && isStudent != 'N')
        {
            cout << "Are you a Student ?" << endl;
            cin >> isStudent;
        }

        // Calculates student discount , if customer is student
        if (isStudent == 'Y' || isStudent == 'y')
        {
            stud_saving = round(0.10 * cost);
            cost = round(cost * 0.90);
        }

        // Calculating hst tax 13%
        hst_tax = round(0.13 * cost);

        // Calculating total bill after tax
        total_cost = round(cost * 1.13);
    }
    else
    {
        goto menu;
    }

    cout << endl;

    printReciept();

    return 0;
}
