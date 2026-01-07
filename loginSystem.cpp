#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

void userRegistration(){
    string username,password;
    cout<<"\n--- Registration ---"<<endl;
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";   
    cin>>password;

    if(username == "" || password == "") {
        cout<<"Username and password cannot be empty."<<endl;
        return;
    }

    for(char c : username) {
        if(!isalnum(c)) {
            cout<<"Username can only contain alphanumeric characters."<<endl;
            return;
        }
    }

    if (password.length() < 6) {
        cout<<"Password must be at least 6 characters long."<<endl;
        return;
    }

    ifstream readfile("usersRecords.txt");
    string fileUsername, filePassword;

    while (readfile>>fileUsername>>filePassword)
    {
        if(fileUsername == username) 
        {
            cout<<"Username already exists. \nPlease choose a different username."<<endl;
            readfile.close();
            return;
        }
    }
    readfile.close();
    ofstream writefile("usersRecords.txt", ios::app);
    writefile<<username<<" "<<password<<endl;
    writefile.close();
    cout<<"Registration successful!"<<endl;
}

void loginUser(){
    string username, password;
    cout<<"\n--- Login ---"<<endl;
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;

    if(username == "" || password == "") {
        cout<<"Username and password cannot be empty."<<endl;
        return;
    }

    ifstream readfile("usersRecords.txt");
    string fileUsername, filePassword;
    bool loginSuccess = false;

    while (readfile>>fileUsername>>filePassword)
    {
        if(fileUsername == username && filePassword == password) 
        {
            loginSuccess = true;
            break;
        }
    }
    readfile.close();

    if(loginSuccess) 
    {
        cout<<"Login successful! Welcome, "<<username<<"."<<endl;
    }
    else 
    {
        cout<<"Login failed! Invalid username or password."<<endl;
    }
}

int main() {
    int choice;
    do{
        cout<<"Login & Registration System"<<endl;
        cout<<"1. Register"<<endl;
        cout<<"2. Login"<<endl; 
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                userRegistration();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout<<"Exiting the system. Goodbye!"<<endl;
                break;
            default:
                cout<<"Invalid choice! Please select a valid option."<<endl;
        }
    } while(choice != 3);

    return 0;
}