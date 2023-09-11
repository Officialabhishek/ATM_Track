#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

class atm {
    private:

    string name;
    long long int accNumber;
    long int PIN;
    double balance;
    string mobileNo;

    public:

    void setAccDetails(string user_name, long long int user_accNumber, long int user_pin, double user_balance, string user_mobileNo) {
        name = user_name;
        accNumber = user_accNumber;
        PIN = user_pin;
        balance = user_balance;
        mobileNo = user_mobileNo;
    }

    long long int getAccNumber() {
        return accNumber;
    }

    string getName() {
        return name;
    }

    long int getPin() {
        return PIN;
    }

    double getBal() {
        return balance;
    }

    string getMobile() {
        return mobileNo;
    }

    void setMobile(string oldMobile, string newMobile) {
        if(oldMobile == mobileNo) {
            mobileNo = newMobile;
            cout << endl << "NEW MOBILE NUMBER SUCCESSFULLY UPDATED!!" << endl;

            _getch();
        } else {
            cout << endl << "WRONG CREDENTIALS" << endl;
            _getch();
        }
    }

    void withdrawal(int amount) {
        if(amount > 0 && amount < balance) {
            balance -= amount;
            cout << endl << "PLEASE COLLECT YOUR MONEY!!" <<endl;
            cout << endl << "Available Balance : " << balance << endl;
            _getch();
        } else {
            cout << endl << "INSUFFICIENT BALANCE!!" << endl;
            _getch();
        }
    }

};

int main() {
    int choice = 0;
    long int enterPin;
    long long int enterAccNumber;

    system("cls");

    atm user1;

    user1.setAccDetails("Mahesh", 987654321, 0000, 50000.50, "999888777");

    do {
        system("cls");

        cout << "____________________WELCOME TO ATM________________________"<< endl << endl;
        cout << "Enter your Account Number : ";
        cin >> enterAccNumber;   
        cout << endl << "Enter your ATM PIN : ";
        cin >> enterPin;

        if(enterAccNumber == user1.getAccNumber() && enterPin == user1.getPin()) {

            do {
                int amount = 0;
                string old_mobileNumber, new_mobileNumber;

                system("cls");
                cout << "________________________WELCOME TO ATM____________________________"<< endl << endl;
                cout << "SELECT OPTIONS ;" <<endl;
                cout << "1. Check Account Details" <<endl;
                cout << "2. Check Bank Balance" <<endl;
                cout << "3. Money Withdrawal" <<endl;
                cout << "4. Update Mobile Number" << endl;
                cout << "5. Exit" <<endl << endl;

                cout << "Your Choice : ";
                cin >> choice;

                switch(choice) {
                    case 1: 
                        cout << "YOUR ACCOUNT DETAILS : " <<endl <<endl;
                        cout << "Name : " << user1.getName() <<endl;
                        cout << "Account Number : " << user1.getAccNumber() <<endl;
                        cout << "Balance : " << user1.getBal() <<endl;
                        cout << "Mobile Number : " << user1.getMobile() << endl;

                        _getch();
                        break;
                    case 2:
                        cout << "Available Bank Balance is " << user1.getBal() <<endl;

                        _getch();
                        break;
                    case 3:
                        cout << "Enter withdrawal amount : ";
                        cin >> amount;
                        user1.withdrawal(amount);
                        break;

                    case 4:
                        cout << "Enter old Mobile Number : ";
                        cin >> old_mobileNumber;
                        cout <<endl << "Enter New Mobile Number : ";
                        cin >> new_mobileNumber;

                        user1.setMobile(old_mobileNumber, new_mobileNumber);
                        break;

                    case 5:
                        exit(0);
                    
                    default:
                        cout <<endl<< "PLEASE ENTER VALID OPTION!!"<<endl; 

                        _getch();                   
                }

            }while(1);

        } else {
            cout << "INVALID USER CREDENTIALS!!"<<endl;
            cout << "PLEASE ENTER CORRECT ACCOUNT NUMBER AND ATM PIN!!";

            _getch();
        }
    } while(1);

    return 0;
}