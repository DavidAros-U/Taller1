#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "User.h"
using namespace std;

class Menu {
private:
    User* head;
    string* userName;
    string* password;
    bool* userLogged;
    
public:
    Menu();

    string getUserName() const { return *(this->userName); }
    string getPassword() const { return *(this->password); }

    bool isUserLogged() const { return *(this->userLogged); }
    bool verifyUserAccount(string* userName, string* password, bool creatingNewUser);

    void setUserName(string _userName) { *(this->userName) = _userName; }
    void setPassword(string _password) { *(this->password) = _password; }
    void setUserLogged(bool _logged) { *(this->userLogged) = _logged; }

    void createAdminUser();
    void addUser(string userName, string password);

    void mainMenu();
    void logInMenu();
    void signUpMenu();
    void userInterfaceMenu();

    ~Menu();
};
#endif
