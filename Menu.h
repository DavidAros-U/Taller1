#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;

class Menu {
private:
    string* userName;
    string* password;
    bool* userLogged;

    bool verifyUserAccount(string* userName, string* password);

public:
    Menu();

    string getUserName() const { return *(this->userName); }
    string getPassword() const { return *(this->password); }
    bool isUserLogged() const { return *(this->userLogged); }

    void setUserName(string _userName) { *(this->userName) = _userName; }
    void setPassword(string _password) { *(this->password) = _password; }
    void setUserLogged(bool _logged) { *(this->userLogged) = _logged; }

    void mainMenu();
    void logInMenu();
    void signUpMenu();
    void userInterfaceMenu();

    // Destructor
    ~Menu();
};
#endif
