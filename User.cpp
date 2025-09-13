#include "User.h"

User::User(string _username, string _password) {
    this->username = new string(_username);
    this->password = new string(_password);
    this->next = nullptr;
}

User::~User() {
    delete this->username;
    delete this->password;
    cout << "User " << *(this->username) << " destroyed" << endl;
}
