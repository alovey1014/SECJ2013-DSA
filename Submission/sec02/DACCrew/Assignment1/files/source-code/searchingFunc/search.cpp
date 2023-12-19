#include <iostream>
#include <iomanip>
using namespace std;

void dispHeader()
{
    for(int i = 0; i < 106; i++)
        cout << "-";
    cout << endl;
    cout << setw(50) << left << "| Name " << "|" 
             << setw(20) << " Account Number " << "|" 
             << setw(14) << " Ic Number " << "|" 
             << setw(18) << " Account Balance " << "|" << endl;
    for(int i = 0; i < 106 ; i++)
        cout << "-";
    cout << endl;
}

//Searching
void searchByName(Bank bl[], int size, const string& searchName)
{
    bool found = false;

    cout << "Search Results for Name: " << searchName << endl;

    for (int i = 0; i < size; i++)
    {
        if (bl[i].getName() == searchName)
        {
            dispHeader();
            bl[i].displaySort();
            found = true;
        }
    }

    if (!found)
        cout << "No matching records found for the given name." << endl;
}

void searchByAccNum(Bank bl[], int size, const string& searchAccNum)
{
    bool found = false;

    cout << "Search Results for Account Number: " << searchAccNum << endl;

    for (int i = 0; i < size; i++)
    {
        if (bl[i].getAccNum() == searchAccNum)
        {
            dispHeader();
            bl[i].displaySort();
            found = true;
        }
    }

    if (!found)
        cout << "No matching records found for the given account number." << endl;
}

void searchByIc(Bank bl[], int size, const string& searchIc)
{
    bool found = false;

    cout << "Search Results for IC Number: " << searchIc << endl;

    for (int i = 0; i < size; i++)
    {
        if (bl[i].getIc() == searchIc)
        {
            dispHeader();
            bl[i].displaySort();
            found = true;
        }
    }

    if (!found)
        cout << "No matching records found for the given IC number." << endl;
}
