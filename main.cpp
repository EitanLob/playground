#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

bool checkLogin(const string &username, const string &password) {
    ifstream file("users.txt"); // Open the file containing user details
    string storedUsername, storedPassword;
    
    // Check if the file is open
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return false;
    }

    // Read each line in the file
    while (getline(file, storedUsername) && getline(file, storedPassword)) {
        // Compare the username and password
        if (storedUsername == username && storedPassword == password) {
            return true;
        }
    }

    return false; // Return false if no match is found
}

void createUser() {
    string username, password;
    cout << "Enter a new username: ";
    cin >> username;
    cout << "Enter a new password: ";
    cin >> password;

    ofstream file("users.txt", ios::app); // Open the file to append user data
    if (file.is_open()) {
        file << username << endl;
        file << password << endl;
        cout << "User created successfully!" << endl;
    } else {
        cerr << "Error opening file for writing!" << endl;
    }
}

int main() {
    int choice;
    
    cout << "1. Login" << endl;
    cout << "2. Create New User" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        // Check login details
        if (checkLogin(username, password)) {
            cout << "Login successful!" << endl;
        } else {
            cout << "Invalid username or password!" << endl;
        }
    } else if (choice == 2) {
        createUser();  // Create a new user
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
