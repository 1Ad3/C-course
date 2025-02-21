#include <iostream>
using namespace std;

int main() {
    int pin = 1234, enteredPin, option;
    double balance = 1000.0, amount;

    cout << "Enter your PIN: ";
    cin >> enteredPin;

    if (enteredPin != pin) {
        cout << "Incorrect PIN. Access Denied.\n";
        return 0;
    }

    do {
        cout << "\nATM Menu:\n";
        cout << "1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Current Balance: $" << balance << endl;
                break;
            case 2:
                cout << "Enter deposit amount: $";
                cin >> amount;
                balance += amount;
                cout << "Deposited successfully.\n";
                break;
            case 3:
                cout << "Enter withdrawal amount: $";
                cin >> amount;
                if (amount > balance) {
                    cout << "Insufficient funds.\n";
                } else {
                    balance -= amount;
                    cout << "Withdrawn successfully.\n";
                }
                break;
            case 4:
                cout << "Thank you for using the ATM. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (option != 4);

    return 0;
}
