#include <iostream>
#include "addressBook.h"
#include "record.h"
#include "list.h"
#include "list.cpp"
using namespace std;



void menu()
{
    std::string fileName = "address_save.txt";
    list recordList(fileName);
    int select = 1 ;
    while(1){
        do {
        if(select < 1 || select > 7){
            cout << "Invalid choice, please select again. (number 1 - 6)" << endl;
        } else {
            cout << "Please select the following function(number 1 - 6):" << endl;
        }
        select = 0;
        cout << "1. Display all contacts." << endl;
        cout << "2. Add new contact" << endl;
        cout << "3. Modify existing contacts." << endl;
        cout << "4. Delete contact" << endl;
        cout << "5. Search record with contact name" << endl;
        cout << "6. Delete all records" << endl;
        cout << "7. Exit address book program." << endl;

        cin >> select;
        std::cin.ignore(256, '\n');

        } while (select < 1 || select > 7);

        switch (select){
            case 1:
            {
                recordList.printAllRecords(recordList);
                select = 1;
                break;
            }
            case 2:
            {
                std::string name = getName();
                std::string email = getEmail();
                std::string address = getAddress();
                int phoneNo = getPhoneNo();
                recordList.addRecord(name, email, address, phoneNo);
                select = 1;
                break;
            }
            case 3:
            {
                record* temp;
                std:: string name = getName();
                temp = recordList.modifyRecord(name);
                temp->name = getName();
                temp->email = getEmail();
                temp->address = getAddress();
                temp->phoneNo = getPhoneNo();
                cout <<"-----------------------------"<<endl;
                cout << "Record modified successfully." << endl;
                cout <<"-----------------------------"<<endl;
                cout<<temp->name<<endl;
                cout<<temp->email<<endl;
                cout<<temp->address<<endl;
                cout<<temp->phoneNo<<endl;
                cout <<"---------------"<<endl;
                select = 1;
                break;
            }
            case 4:
            {
                record* temp;
                cout << "-------------" << endl;
                cout << "Delete Record" << endl;
                cout << "-------------" << endl;
                std:: string name = getName();
                recordList.deleteRecord(name);
                select = 1;
                break;
            }
            case 5:
            {
                std::string name = getName();
                recordList.printRecord(name);
                select = 1;
                break;
            }
            case 6:
            {
                recordList.deleteALlRecords();
                select = 1;
                break;
            }
            case 7:
            {
                return;
            }
    }
    }
}

std::string getName()
{
    std::string temp;
    cout << "Please enter name of that person." << endl;
    getline(cin, temp, '\n');
    // cin.clear();
    return temp;
}

std::string getEmail()
{
    std::string temp;
    cout << "Please enter the email of that person." << endl;
    getline(cin, temp, '\n');
    // cin.clear();
    // std::cin.ignore(256, '\n');
    return temp;
}

std::string getAddress()
{
    std::string temp;
    cout << "Please enter the address of that person." << endl;
    getline(cin, temp, '\n');
    // cin.clear();
    // cin.ignore(256, '\n');
    return temp;
}

int getPhoneNo()
{
    int temp;
    cout << "Please enter the phone number of that person." << endl;
    cin >> temp;
    // cin.clear();
    // cin.ignore(256, '\n');
    return temp;
}



