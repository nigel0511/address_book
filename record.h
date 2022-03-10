#ifndef RECORD_H
#define RECORD_H
#include <string>

struct record {
    std::string name;
    std::string email;
    std::string address;
    int phoneNo;
    struct record * next;
};

#endif