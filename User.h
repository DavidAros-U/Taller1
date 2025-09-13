#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {
private:
    string* username;
    string* password;
    User* next;

public:
    User(string _username, string _password);

    string getUsername() const { return *(this->username); }
    string getPassword() const { return *(this->password); }
    User* getNext() const { return this->next; }

    void setUsername(string _username) { *(this->username) = _username; }
    void setPassword(string _password) { *(this->password) = _password; }
    void setNext(User* _next) { this->next = _next; }

    ~User();
};

#endif
