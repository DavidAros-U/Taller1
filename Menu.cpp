#include "Menu.h"

Menu::Menu() {
    this->userName = new string("");
    this->password = new string("");
    this->userLogged = new bool(false);
}

Menu::~Menu() {
    delete this->userName;
    delete this->password;
    delete this->userLogged;
    cout << "Menu destroyed" << endl;
}

bool Menu::verifyUserAccount(string* userName, string* password) {
    return true;
}

void Menu::mainMenu() {
    bool program = true;
    string optionSelected;

    while (program) {
        cout << "BANNER ESCUELA DE BORRACHERIA" << endl;
        cout << "1) Log in" << endl;
        cout << "2) Sign up" << endl;
        cout << "0) Exit" << endl;
        cin >> optionSelected;

        if (optionSelected == "1") {
            this->logInMenu();
        } else if (optionSelected == "2") {
            this->signUpMenu();
        } else if (optionSelected == "0") {
            program = false;
        } else {
            cout << "Please select a valid option..." << endl;
        }
    }
}

void Menu::logInMenu() {
    cout << "Enter username: ";
    cin >> *(this->userName);
    cout << "Enter password: ";
    cin >> *(this->password);

    bool userExist = verifyUserAccount(this->userName, this->password);

    if (userExist) {
        cout << "Welcome, " << *(this->userName) << "!!" << endl;
        *(this->userLogged) = true;
    } else {
        cout << "The user does not exist..." << endl;
    }
}

void Menu::signUpMenu() {
    string newUser;
    string newPassword;
    string confirmPassword;

    cout << "Enter username: ";
    cin >> newUser;
    cout << "Enter password: ";
    cin >> newPassword;
    cout << "Repeat password: ";
    cin >> confirmPassword;

    bool userExist = false;

    if (!userExist) {
        if (newPassword == confirmPassword) {
            *(this->userName) = newUser;
            *(this->password) = newPassword;
            *(this->userLogged) = true;
            cout << "Benvenuti " << *(this->userName) << "!!!" << endl;
        } else {
            cout << "Passwords are not the same!!" << endl;
        }
    } else {
        cout << "The user already exists!!" << endl;
    }
}
