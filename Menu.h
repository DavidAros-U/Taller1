#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "User.h"
#include "StudentList.h"
using namespace std;

class Menu {
private:
    User* head;
    string* userName;
    string* password;
    bool* userLogged;
    StudentList* students;
    
public:
    Menu();
    ~Menu();

    string getUserName() const { return *(this->userName); }
    string getPassword() const { return *(this->password); }
    bool isUserLogged() const { return *(this->userLogged); }

    void setUserName(string _userName) { *(this->userName) = _userName; }
    void setPassword(string _password) { *(this->password) = _password; }
    void setUserLogged(bool _logged) { *(this->userLogged) = _logged; }

    bool verifyUserAccount(string* userName, string* password, bool creatingNewUser);
    void createAdminUser();
    void addUser(string userName, string password);

    void mainMenu();
    void logInMenu();
    void signUpMenu();
    void userInterfaceMenu();

    void studentManagementMenu();
};

#endif
