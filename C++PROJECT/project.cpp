#include <iostream>
#include <map>
#include <string>
#include <algorithm>

// User data structure
struct User {
    std::string username;
    std::string password;
};

// Database to store user information (in-memory database for simplicity)
std::map<std::string, User> userDatabase;

// Function to register a new user
void Register() {
    std::string username, password;
    std::cout << "Enter a username: ";
    std::cin >> username;

    // Check if the username already exists
    if (userDatabase.find(username) != userDatabase.end()) {
        std::cout << "Username already exists. Please choose another.\n";
        return;
    }

    std::cout << "Enter a password: ";
    std::cin >> password;

    // Store the user in the database
    User newUser;
    newUser.username = username;
    newUser.password = password;
    userDatabase[username] = newUser;
    std::cout << "Registration successful.\n";
}

// Function to authenticate a user
bool Authenticate() {
    std::string username, password;
    std::cout << "Enter your username: ";
    std::cin >> username;

    // Check if the username exists in the database
    if (userDatabase.find(username) == userDatabase.end()) {
        std::cout << "User not found.\n";
        return false;
    }

    std::cout << "Enter your password: ";
    std::cin >> password;

    // Check if the provided password matches the stored password
    if (userDatabase[username].password == password) {
        std::cout << "Login successful. Welcome, " << username << "!\n";
        return true;
    } else {
        std::cout << "Incorrect password. Please try again.\n";
        return false;
    }
}

int main() {
    while (true) {
        std::cout << "Choose an option:\n";
        std::cout << "1. Register\n";
        std::cout << "2. Login\n";
        std::cout << "3. Quit\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                Register();
                break;
            case 2:
                if (Authenticate()) {
                    // Implement secured page access logic here
                }
                break;
            case 3:
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
