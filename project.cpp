#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

class BankAccount {
private:
    string name;
    int accNumber;
    double balance;

public:
    BankAccount() {
        name = "";
        accNumber = 0;
        balance = 0.0;
    }

    void createAccount() {
        cout << "\nEnter Account Holder Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Account Number: ";
        cin >> accNumber;

        cout << "Enter Initial Deposit Amount: ";
        cin >> balance;

        cout << "\nAccount created successfully.\n";
    }

    void deposit() {
        double amount;
        cout << "\nEnter amount to deposit: ";
        cin >> amount;

        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully.\n";
        } else {
            cout << "Invalid amount entered.\n";
        }
    }

    void withdraw() {
        double amount;
        cout << "\nEnter amount to withdraw: ";
        cin >> amount;

        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful.\n";
        } else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }

    void displayBalance() const {
        cout << "\n------ ACCOUNT DETAILS ------\n";
        cout << "Account Holder: " << name << endl;
        cout << "Account Number : " << accNumber << endl;
        cout << fixed << setprecision(2);
        cout << "Current Balance: ₹" << balance << endl;
        cout << "------------------------------\n";
    }

    void saveToFile() const {
        ofstream file("bank_accounts.txt", ios::app);
        if (!file) {
            cout << "Error: Unable to open file.\n";
            return;
        }
        file << "Name: " << name
             << ", Acc No: " << accNumber
             << ", Balance: " << balance << endl;
        file.close();
    }
};


long long factorial(int n) {
    if (n < 0) return -1;
    long long fact = 1;
    for (int i = 1; i <= n; ++i)
        fact *= i;
    return fact;
}


void calculator() {
    int option;
    do {
        cout << "\n------ CALCULATOR ------";
        cout << "\n1. Addition";
        cout << "\n2. Subtraction";
        cout << "\n3. Multiplication";
        cout << "\n4. Division";
        cout << "\n5. Power (x^y)";
        cout << "\n6. Square Root (√x)";
        cout << "\n7. Percentage (x%)";
        cout << "\n8. Factorial (x!)";
        cout << "\n9. Exit Calculator";
        cout << "\n------------------------";
        cout << "\nEnter your choice: ";
        cin >> option;

        double num1, num2;
        cout << fixed << setprecision(2);

        switch (option) {
            case 1:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 + num2 << endl;
                break;

            case 2:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 - num2 << endl;
                break;

            case 3:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 * num2 << endl;
                break;

            case 4:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                if (num2 != 0)
                    cout << "Result: " << num1 / num2 << endl;
                else
                    cout << "Error: Division by zero.\n";
                break;

            case 5:
                cout << "Enter base and exponent: ";
                cin >> num1 >> num2;
                cout << "Result: " << pow(num1, num2) << endl;
                break;

            case 6:
                cout << "Enter number: ";
                cin >> num1;
                if (num1 >= 0)
                    cout << "Result: " << sqrt(num1) << endl;
                else
                    cout << "Error: Negative number not allowed.\n";
                break;

            case 7:
                cout << "Enter number: ";
                cin >> num1;
                cout << "Result: " << (num1 / 100) << endl;
                break;

            case 8: {
                int n;
                cout << "Enter integer: ";
                cin >> n;
                if (n < 0)
                    cout << "Error: Negative number not allowed.\n";
                else
                    cout << "Result: " << factorial(n) << endl;
                break;
            }

            case 9:
                cout << "Exiting calculator...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (option != 9);
}

int main() {
    BankAccount account;
    int choice;

    do {
        cout << "\n===== BANK ACCOUNT MANAGEMENT SYSTEM =====";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Check Balance";
        cout << "\n5. Save and Exit";
        cout << "\n6. Calculator";
        cout << "\n------------------------------------------";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.createAccount();
                break;
            case 2:
                account.deposit();
                break;
            case 3:
                account.withdraw();
                break;
            case 4:
                account.displayBalance();
                break;
            case 5:
                account.saveToFile();
                cout << "\nAccount data saved. Exiting...\n";
                break;
            case 6:
                calculator();
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
