#include <iostream>
#include <ctime>

using namespace std;

// Bank class implementing ATM functionalities
class Bank {
private:
    int balance;
    const int PIN = 12345;

public:
    Bank() : balance(20000) {} // Constructor initializing balance

    void displayWelcomeScreen() {
        cout << "Welcome to the ATM Banking Application\n";
        displayCurrentDateTime();
        cout << "1. Enter ATM PIN\n2. Help\nChoose an option: ";
    }

    void displayCurrentDateTime() {
        time_t now = time(0);
        char* dt = ctime(&now);
        cout << "Current Date and Time: " << dt << endl;
    }

    void enterPIN() {
        int userPIN;
        cout << "Enter ATM PIN: ";
        cin >> userPIN;

        if (userPIN == PIN) {
            displayMenu();
        } else {
            cout << "Incorrect PIN. Exiting...\n";
        }
    }

    void displayHelpScreen() {
        cout << "\nHelp Screen:\n";
        cout << "Enter 12345 as the PIN to access the ATM system.\n";
        cout << "Follow the instructions for deposit, withdrawal, and balance check.\n";
    }

    void displayMenu() {
        int choice;
        cout << "\nMenu:\n1. Deposit\n2. Withdraw\n3. Check Balance\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: deposit(); break;
            case 2: withdraw(); break;
            case 3: checkBalance(); break;
            default: cout << "Invalid choice. Exiting...\n"; break;
        }
    }

    void deposit() {
        int amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Deposit successful. New Balance: Rs. " << balance << endl;
    }

    void withdraw() {
        int amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount > balance) {
            cout << "Unsuccessful withdrawal. Insufficient balance.\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful. New Balance: Rs. " << balance << endl;
        }
    }

    void checkBalance() {
        cout << "Current Balance: Rs. " << balance << endl;
    }
};

int main() {
    Bank atm;
    atm.displayWelcomeScreen();

    int option;
    cin >> option;

    if (option == 1) {
        atm.enterPIN();
    } else if (option == 2) {
        atm.displayHelpScreen();
    } else {
        cout << "Invalid option. Exiting...\n";
    }

    return 0;
}

