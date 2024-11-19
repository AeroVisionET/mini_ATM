#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string.h>

using namespace std;

class mini_ATM
{
private:
    long int account_no;
    int PIN;
    double balance;
    string name;
    string mobile_no;

public:
    void setData(long int account_noo, int PINN,double balancee, string namee, string mobile_noo)
    {
       account_no = account_noo;
       PIN = PINN;
       balance = balancee;
       name = namee;
       mobile_no = mobile_noo;
    }

    long int getAcc()
    {
        return account_no;
    }

    int getPIN()
    {
        return PIN;
    }

    double getBalance()
    {
        return balance;
    }

    string getname()
    {
        return name;
    }

    string getmobileNo()
    {
        return mobile_no;
    }

    void setMobileNo(string mobile_pre, string mobile_new)
    {
        if(mobile_pre == mobile_no)
        {
            mobile_no = mobile_new;
            cout<<endl<<"Mobile number updated";
            _getch();
        }
        else
        {
            cout<<endl<<"Incorrect! This is old mobile number";
            _getch();            
        }
    }
    void cashWithDraw(int amountt)
    {
        if(amountt > 0 && amountt < balance)
        {
            balance -= amountt;
            cout<<endl<<"Please collect your cash";
            cout<<endl<<"Available balance is :" <<balance;  
            _getch();           
        }
        else
        {
             cout<<endl<<"insufficent balance";     
             _getch();                   
        }
    }


};


int main()
{
    int choice;
    int enterPIN;
    long int enterAccount_No;

    system("cls");

    mini_ATM mini_ATM_user1;
    mini_ATM_user1.setData(12345678, 1234, 980999, "Semachew", "0926808306");

    do 
    {
        system("cls");  
        cout << endl << "Welcome to the mini ATM";
        cout << endl << "Please enter your account number: ";   
        cin >> enterAccount_No;     

        cout << endl << "Please enter your PIN number: ";   
        cin >> enterPIN; 

        if (enterAccount_No == mini_ATM_user1.getAcc() && enterPIN == mini_ATM_user1.getPIN())  
        {
            do
            {
                int amount = 0;
                string mobileNoold, mobileNoNew;

                system("cls");    
                cout << endl << "Welcome to the mini ATM";
                cout << endl << "Select options";  
                cout << endl << "1. Check balance";  
                cout << endl << "2. Cash withdrawal";  
                cout << endl << "3. Show user details"; 
                cout << endl << "4. Update mobile number";  
                cout << endl << "5. Exit";  
                cout << endl << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                    case 1:
                        cout << endl << "Your account balance is: " << mini_ATM_user1.getBalance();
                        _getch();
                        break;

                    case 2:
                        cout << endl << "Enter the amount: ";
                        cin >> amount;
                        mini_ATM_user1.cashWithDraw(amount);
                        break;

                    case 3:
                        cout << endl << "User details are:";
                        cout << endl << "Account number: " << mini_ATM_user1.getAcc();
                        cout << endl << "Name: " << mini_ATM_user1.getname();  
                        cout << endl << "Balance: " << mini_ATM_user1.getBalance();                  
                        cout << endl << "Mobile Number: " << mini_ATM_user1.getmobileNo();   
                        _getch();                      
                        break;

                    case 4:
                        cout << endl << "Enter old mobile number: ";
                        cin >> mobileNoold;

                        cout << endl << "Enter new mobile number: ";
                        cin >> mobileNoNew;

                        mini_ATM_user1.setMobileNo(mobileNoold, mobileNoNew);
                        break;

                    case 5:
                        exit(0);

                    default:
                        cout << endl << "Enter valid data.";
                        _getch();
                        break;
                }

            } while (true);
        }
        else
        {
            cout << endl << "Invalid account number or PIN.";
            _getch();
        }

    } while (true);

    return 0;
}