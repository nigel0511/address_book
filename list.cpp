#include <iostream>
#include <fstream>
#include "record.h"
#include "list.h"
// #include "addressBook.h"
// #include "addressBook.cpp"
#include <string>
using namespace std;

list::list(){
    head = NULL;
    tail = NULL;
    readFile("address_save.txt");
}

list::list(std::string fileName)
{
    head = NULL;
    tail = NULL;
    file_name = fileName;
    readFile(file_name);
}

list::~list(){
    writeFile();
}

void list::deleteRecord(std::string name){
    record* temp = new record;
    record* previous = new record;
    temp = head;
    char answer;
    while(temp!=NULL){
        if(temp->name == name){
            cout << "Record found, are you sure you want to delete it?(y/n)" << endl;
            cout <<"---------------"<<endl;
            cout<<temp->name<<endl;
            cout<<temp->email<<endl;
            cout<<temp->address<<endl;
            cout<<temp->phoneNo<<endl;
            cout <<"---------------"<<endl;
            cin >> answer;
            while(answer != 'y' || answer != 'n'){
                if(answer == 'y'){
                    if(temp == head){
                        head = temp->next;
                        delete temp;
                        break;
                    } else if (previous == tail){
                        tail = previous;
                        delete temp;
                        break;
                    } else {
                        previous->next = temp->next;
                        delete temp;
                        break;
                    }
                } else if (answer == 'n'){
                    break;
                }
            }
        }
        previous = temp;
        temp = temp->next;
    }
}

void list::deleteALlRecords()
{
    char answer;
    cout << "*Are you sure you want to delete all records?(y/n)*" << endl;
    cin >> answer;
    while(answer != 'y' || answer != 'n'){
        if(answer == 'y'){
            record* temp = new record;
            temp = head;
            while(temp != NULL){
                record* deleteThis = new record;
                deleteThis = temp;
                temp = temp->next;
                delete deleteThis;
            }
            head = NULL;
            tail = NULL;
            cout << "**ALL RECORDS DELETED***" << endl;
            return;
        } else if (answer == 'n'){
            return;
        }
        cout << "Please select (y/n) only." << endl;
        cin >> answer;
    }
    

}

void list::printRecord(std::string name){
    record* temp = new record;
    int recordCounter = 0;
    temp = head;
    while(temp!=NULL){
        if(temp->name == name){
            cout <<"---------------"<<endl;
            cout<<temp->name<<endl;
            cout<<temp->email<<endl;
            cout<<temp->address<<endl;
            cout<<temp->phoneNo<<endl;
            cout <<"---------------"<<endl;
            recordCounter++;
        } 
        temp = temp->next;
    } 

    if(recordCounter == 0){
            cout <<"---------------"<<endl;
            cout <<"No record found."<<endl;
            cout <<"---------------"<<endl;

    }
}

void list::writeFile()
{
    record *temp = new record;
    fstream fs;
    temp = head;
    fs.open("address_save.txt", ios::out | ios::binary);
    if(fs.is_open()){
        while (temp!= NULL){
            fs << temp->name << endl;
            fs << temp->email << endl;
            fs << temp->address << endl;
            fs << temp->phoneNo << endl;
            temp = temp->next;
        }
        fs.close();
    } else {
        cout << "Cannot open file." << endl;
    }
}

void list::readFile(std::string fileName){
    fstream fs;
    string dummy = "";
    int recordCount = 0;
    fs.open(fileName, ios::in);

    while(fs.peek() != EOF) {
        record * temp = new record;
        std::getline(fs, temp->name);
        std::getline(fs, temp->email);
        std::getline(fs, temp->address);
        fs >> temp->phoneNo;
        std::getline(fs, dummy);


        if(head == NULL){
            head = temp;
            tail = temp;
        } else if (head != NULL) {
            tail->next = temp;
            tail = temp;
        }
    }
}

void list::addRecord(string name, string email, string address, int phoneNo)
{
    record* temp = new record;
    temp = head;
    while(temp!=NULL){
        if(temp->name == name){
            cout <<"----------------------" << endl;
            cout << "Record already exist." << endl;
            cout <<"----------------------"<<endl;
            cout << temp->name <<endl;
            cout << temp->email <<endl;
            cout << temp->address <<endl;
            cout << temp->phoneNo <<endl;
            cout <<"---------------"<<endl;
            return;
        }
        temp = temp->next;
    }

    record* newRecord = new record;
    newRecord->name = name;
    newRecord->email = email;
    newRecord->address = address;
    newRecord->phoneNo = phoneNo;
    if(head == NULL){ //if list is empty
        head = newRecord;
        tail = newRecord;
    } else { 
        tail->next = newRecord;
        tail = newRecord;
    }

    cout <<"---------------------------" << endl;
    cout << "Record added successfully." << endl;
    cout <<"---------------------------"<<endl;
    cout << newRecord->name <<endl;
    cout << newRecord->email <<endl;
    cout << newRecord->address <<endl;
    cout << newRecord->phoneNo <<endl;
    cout <<"---------------"<<endl;
};


void list::printAllRecords(list recordList)
{
    record* temp = new record;
    temp = head;
    if(temp != NULL) {
        while(temp != NULL) {
        cout<<"----------------"<<endl;
        cout<<temp->name<<endl;
        cout<<temp->email<<endl;
        cout<<temp->address<<endl;
        cout<<temp->phoneNo<<endl;
        cout<<"****************"<<endl;

        temp = temp->next;
    }
    cout<<endl;
    } else {
        cout<<"---------------------------------"<<endl;
        cout<<"There are no existing record yet.\n";
        cout<<"---------------------------------"<<endl;

    }
};

record* list::modifyRecord(std::string name)
{
    record* temp = new record;
    temp = head;
    record* result;
    while(temp!=NULL){
        if(temp->name == name){
            cout <<"-----------------------------"<<endl;
            cout << "Record found, please modify." << endl;
            cout <<"-----------------------------"<<endl;
            cout<<temp->name<<endl;
            cout<<temp->email<<endl;
            cout<<temp->address<<endl;
            cout<<temp->phoneNo<<endl;
            cout <<"---------------"<<endl;
            result = temp;
        } 
        temp = temp->next;
    };




    return result;
}