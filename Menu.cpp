#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu() {
    this->userName = new string("");
    this->password = new string("");
    this->userLogged = new bool(false);
    this->head = nullptr;
    createAdminUser();
}

Menu::~Menu() {
    delete this->userName;
    delete this->password;
    delete this->userLogged;

    User* temp = head;
    while (temp) {
        User* next = temp->getNext();
        delete temp;
        temp = next;
    }

    cout << "Menu destroyed" << endl;
}

void Menu::createAdminUser() {
    addUser("admin", "123");
}

void Menu::addUser(string userName, string password) {
    User* newUser = new User(userName, password);
    if (!head) {
        head = newUser;
    } else {
        User* temp = head;
        while (temp->getNext()) temp = temp->getNext();
        temp->setNext(newUser);
    }
}

bool Menu::verifyUserAccount(string* userName, string* password, bool creatingNewUser) {
    User* temp = head;
    while (temp) {
        if (temp->getUsername() == *userName) {
            if (creatingNewUser) {
                return false;
            } else {
                return temp->getPassword() == *password;
            }
        }
        temp = temp->getNext();
    }
    return creatingNewUser ? true : false;
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

    bool userExist = verifyUserAccount(this->userName, this->password, false);

    if (userExist) {
        cout << "Welcome, " << *(this->userName) << "!!" << endl;
        *(this->userLogged) = true;
    } else {
        cout << "The user does not exist or password is incorrect..." << endl;
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

    bool canCreate = verifyUserAccount(&newUser, &newPassword, true);

    if (!canCreate) {
        cout << "The user already exists!!" << endl;
    } else {
        if (newPassword == confirmPassword) {
            addUser(newUser, newPassword);
            *(this->userName) = newUser;
            *(this->password) = newPassword;
            *(this->userLogged) = true;
            cout << "Benvenuti " << *(this->userName) << "!!!" << endl;
        } else {
            cout << "Passwords are not the same!!" << endl;
        }
    }
}
