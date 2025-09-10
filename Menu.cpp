#include "Menu.h"

Menu::Menu(){
    userLogged=false;
}

bool Menu::verifyUserAccount(string userName, string password){
    return true;
}

void Menu::mainMenu(){
    bool program=true;
    string optionselected;
    while(program){

            cout<<"BANNER ESCUELA DE BORRACHERIA"<<endl;
            cout<<""<<endl;
            cout<<"1) Log in"<<endl;
            cout<<"2) Sign account"<<endl;
            cout<<"0) Exit"<<endl;
            cout<<""<<endl;
            cin >> optionselected;

            if(optionselected=="1"){
                logInMenu();
            }
            else if(optionselected=="2"){
                //signAccountMenu();
            }
            else if(optionselected=="0"){
                program=false;
            }
            else {
                cout<<"Please select a valid option..."<<endl;
            }
            cout<<""<<endl;
    }
}

void Menu::logInMenu(){
    bool user;
    string userName;
    string password;
    cout<<""<<endl;
    cout<<"Enter username: "<<endl;
    cin >> userName;
    cout<<"Enter password: "<<endl;
    cin >> password;
    cout<<""<<endl;
    //user=verifyUserAccount(userName,password);
    user=true;
    if(user==true){
        //userInterface();
        cout<<"welcome!!"<<endl;
    }
    else{
        cout<<"the user does not exist..."<<endl;
        cout<<""<<endl;
    }
    
}