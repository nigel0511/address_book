#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "record.h"
#include <string>

class list 
{
    private:
        record *head;
        record *tail;
        std::string file_name;
        void readFile(std::string fileName);
        void writeFile();
    public:
        list();
        list(std::string fileName);
        ~list();
        void printAllRecords(list recordList);
        void printRecord(std::string name);
        void addRecord(std::string name, std::string email, std::string address, int phoneNo);
        void deleteRecord(std::string name);
        void deleteALlRecords();
        record* modifyRecord(std::string name);
};

#endif