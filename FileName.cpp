// C++ program to implement the ATM Management System

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <string>
using namespace std;

int x = 1234;
int pin;

class Bank {

    // Private variables used inside class
    private:
        unsigned long amount = 0;
        unsigned long total = 700;
   
    public:

        // Function to verify if the pin is correctly introduced
        bool verifypin()
        {
            cout << "Enter Account PIN\n";
            cin >> pin;
            /*fstream mypin;
            mypin.open("pin.txt", ios::out);
            if (mypin.is_open())
            {
                mypin << 1234;
                mypin.close();
            }
            mypin.open("pin.txt", ios::in);
            if (mypin.is_open())
            {
                string line;
                while (getline(mypin, line))
                {
                    if (line != "1234") {
                        cout << "The PIN is incorrect! " << endl;
                        return false;
                    }
                    return true;
                }
                mypin.close();
            }*/

        
            if (pin != x) {
                cout << "The PIN is incorrect! " << endl;
                return false;
            }
            return true;    
        }

    // Function to modify the PIN
    void modifypin()
    {
        int y=0;
        cout << "Old PIN:";
        cin >> x;
        if (x != pin)
        {
            cout << "Wrong PIN";
            exit(1);
        }
        else
        {
            cout << "Enter new PIN ";
            cin >> y;
            cout << "Now your new PIN is " << y << "!" << endl;
        }
        pin = y;
        x = y;
        
    }

    // Function to deposit the amount in ATM
    void deposit()
    {
        cout << "\nEnter amount to be Deposited\n";
        cin >> amount;
        cout << "You deposited with succes " << amount << " $"<<endl;
        total = total + amount;
    }

    // Function to show the balance amount
    void showbal()
    {
        cout << "\nTotal balance is: " << total<<endl;
    }

    // Function to withdraw the amount in ATM
    void withdraw()
    {
        int withdrawAmount,withdrawOption, avail_balance;

        cout << "How much do you want to withdraw?"<<endl;
        cout << "10 (1)" << "                                 50 (4)"<<endl;
        cout << "100 (2)" << "                                200 (5)"<<endl;
        cout << "500 (3)" << "                          Another sum(6)"<<endl;
        cout << "Enter amount to withdraw\n";
        
        cin >> withdrawOption;

        switch (withdrawOption) {
        case 1:
            avail_balance = total - 10;
            if (avail_balance < 0)
                cout << "You don't have that much money to withdraw ";
            else
            {
                cout << "You withdraw with success " << "10" << " $ ," << "Available Balance is " << avail_balance << endl;
                total = avail_balance;
            }
            break;
        case 2:
            avail_balance = total - 100;
            if (avail_balance < 0)
                cout << "You don't have that much money to withdraw ";
            else
            {
                cout << "You withdraw with success " << "100" << " $ ," << "Available Balance is " << avail_balance << endl;
                total = avail_balance;
            }
            break;
        case 3:
            avail_balance = total - 500;
            if (avail_balance < 0)
                cout << "You don't have that much money to withdraw ";
            else {
                cout << "You withdraw with success " << "500" << " $ ," << "Available Balance is " << avail_balance << endl;
                total = avail_balance;
            }
            break;
        case 4:
            avail_balance = total - 50;
            if (avail_balance < 0)
                cout << "You don't have that much money to withdraw ";
            else {
                cout << "You withdraw with success " << "50" << " $ ," << "Available Balance is " << avail_balance << endl;
                total = avail_balance;
            }   
            break;
        case 5:
            avail_balance = total - 200;
            if (avail_balance < 0)
                cout << "You don't have that much money to withdraw ";
            else {
                cout << "You withdraw with success " << "200" << " $ ," << "Available Balance is " << avail_balance << endl;
                total = avail_balance;
            }
                
            break;
        case 6:
            cout << "How much do you want to withdraw? ";
            cin >> withdrawAmount;
            avail_balance = total - withdrawAmount;
            if (avail_balance < 0)
                cout << "You don't have that much money to withdraw ";
            else {
                cout << "You withdraw with success " << withdrawAmount << " $ ," << "Available Balance is " << avail_balance << endl;
                total = avail_balance;
            }
                
            break;
        default:
            cout << "Invalid option ";
            break;
        }
        
    }
   
};

// Driver Code
int main()
{
    // Object of class
    Bank bankObject;

    int choice;

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~"
        << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
        << "~~~WELCOME~~~~~~~~~~~~~~~~~~"
        << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
        << "~~~~~~~~~\n\n";

       
    if (bankObject.verifypin()) 
    {
        while (1) {

            cout << "Enter Your Choice\n";
            cout << "\t1. Change PIN\n";
            cout << "\t2. Deposit Money\n";
            cout << "\t3. Show Total balance\n";
            cout << "\t4. Withdraw Money\n";
            cout << "\t5. Cancel\n";
            cin >> choice;

            // Choices to select from
            switch (choice) {
            case 1:
                bankObject.modifypin();

                char option;
                cout << "Do you want another operation? " << endl;
                cin >> option;

                if (option == 'y') 
                {
                    bankObject.verifypin();
                }
                else 
                {
                    exit(1);
                }

                break;
            case 2:
                bankObject.deposit();
                char option1;
                cout << "Do you want another operation? " << endl;
                cin >> option1;

                if (option1 == 'y')
                {
                    bankObject.verifypin();
                }
                else
                {
                    exit(1);
                }

                break;
            case 3:
                bankObject.showbal();
                char option2;
                cout << "Do you want another operation? " << endl;
                cin >> option2;

                if (option2 == 'y')
                {
                    bankObject.verifypin();
                }
                else
                {
                    exit(1);
                }

                break;
            case 4:
                bankObject.withdraw();
                char option3;
                cout << "Do you want another operation? " << endl;
                cin >> option3;

                if (option3 == 'y')
                {
                    bankObject.verifypin();
                }
                else
                {
                    exit(1);
                }

                break;
            case 5:
                exit(1);
                
            default:
                cout << "\nInvalid choice\n";
                break;
            }
        }
    }
}