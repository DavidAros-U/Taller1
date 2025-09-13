#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu() {
    this->userName = new string("");
    this->password = new string("");
    this->userLogged = new bool(false);
     this->students = new StudentList();
    this->head = nullptr;
    createAdminUser();
}

Menu::~Menu() {
    delete this->userName;
    delete this->password;
    delete this->userLogged;
    delete this->students;
    
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
        cout << "1) Log In" << endl;
        cout << "2) Sign Up" << endl;
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
    cout << "Enter Username: ";
    cin >> *(this->userName);
    cout << "Enter Password: ";
    cin >> *(this->password);

    bool userExist = verifyUserAccount(this->userName, this->password, false);

    if (userExist) {
        cout << "Welcome, " << *(this->userName) << "!!" << endl;
        *(this->userLogged) = true;
        userInterfaceMenu();
    } else {
        cout << "The user does not exist or password is incorrect..." << endl;
    }
}

void Menu::signUpMenu() {
    string newUser;
    string newPassword;
    string confirmPassword;

    cout << "Enter Username: ";
    cin >> newUser;
    cout << "Enter Password: ";
    cin >> newPassword;
    cout << "Repeat Password: ";
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

void Menu::userInterfaceMenu() {
    if (!*(this->userLogged)) {
        cout << "Access denied. You must log in first!" << endl;
        return;
    }

    bool running = true;
    string option;

    while (running) {
        cout << ""<<endl;
        cout << "1) Student Management\n";
        cout << "2) Course Management\n";
        cout << "3) Enrollment Management\n";
        cout << "4) Grades Management\n";
        cout << "5) Reports\n";
        cout << "0) Log out\n";
        cout << "Select an option: ";
        cout << ""<<endl;
        cin >> option;

        if (option == "1") {
            studentManagementMenu();
        } else if (option == "2") {
            //courseManagementMenu();
        } else if (option == "3") {
            //enrollmentManagementMenu();
        } else if (option == "4") {
            //gradesManagementMenu();
        } else if (option == "5") {
            //reportsMenu();
        } else if (option == "0") {
            running = false;
            *(this->userLogged) = false;
            cout << "Logged out successfully.\n";
        } else {
            cout << "Invalid option, please try again.\n";
        }
    }
}

void Menu::studentManagementMenu() {
    bool running = true;
    string option;

    while (running) {
        cout << "\n--- STUDENT MANAGEMENT ---\n";
        cout << "1) Create Student\n";
        cout << "2) Search Student by ID\n";
        cout << "3) Search Student by Name\n";
        cout << "4) Delete Student by ID\n";
        cout << "0) Back to Main Menu\n";
        cout << "Select an option: ";
        cin >> option;

        if (option == "1") {
            int id;
            string firstName, lastName, career, admissionDate;

            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter First Name: ";
            cin >> firstName;
            cout << "Enter Last Name: ";
            cin >> lastName;
            cout << "Enter Career: ";
            cin >> career;
            cout << "Enter Admission Date (YYYY-MM-DD): ";
            cin >> admissionDate;
            cout << "QEPAAAAAZA ";
            students->addStudent(id, firstName, lastName, career, admissionDate);
            cout << "Student created successfully!\n";

        } else if (option == "2") {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;

            Student* s = students->findStudentById(id);
            if (s) {
                cout << "ID: " << s->getId()
                     << ", Name: " << s->getFirstName() << " " << s->getLastName()
                     << ", Career: " << s->getCareer()
                     << ", Admission: " << s->getAdmissionDate() << endl;
            } else {
                cout << "Student not found.\n";
            }

        } else if (option == "3") {
            string name;
            cout << "Enter First Name to search: ";
            cin >> name;

            vector<Student*> results = students->findStudentsByName(name);
            if (!results.empty()) {
                for (Student* s : results) {
                    cout << "ID: " << s->getId()
                         << ", Name: " << s->getFirstName() << " " << s->getLastName()
                         << ", Career: " << s->getCareer()
                         << ", Admission: " << s->getAdmissionDate() << endl;
                }
            } else {
                cout << "No students found with that name.\n";
            }

        } else if (option == "4") {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;

            bool removed = students->removeStudentById(id);
            if (removed) {
                cout << "Student removed successfully!\n";
            } else {
                cout << "Student not found.\n";
            }

        } else if (option == "0") {
            running = false;
        } else {
            cout << "Please select a valid option..."<<endl;
            cout<<""<<endl;
        }
    }
}

