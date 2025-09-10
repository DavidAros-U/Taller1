#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;

class Menu{
    
private:
    string userName;
    string password;
    bool userLogged;
    bool verifyUserAccount(string userNmae, string password);

    public:
    Menu();
    void mainMenu();
    void logInMenu();
    void signInMenu();
    void userInterfaceMenu();
};

#endif