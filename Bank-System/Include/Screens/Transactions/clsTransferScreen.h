#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"Global.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber;
        cout << "\nBalance     : " << to_string(Client.AccountBalance);
        cout << "\n___________________\n";
    }

    static string _ReadAccountNumber(string AccountType)
    {
        string AccountNumber = "";
        cout << "\nPlease Enter Account Number to Transfer " 
             << AccountType << " : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExists(AccountNumber))
        {
            cout << "\nAccount Not Found, Enter Again : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        return AccountNumber;
    }

    static double _ReadAmount(clsBankClient SourceClient)
    {
        cout << "\nEnter Transfe Amount? ";
        double Amount = clsInputValidate::ReadDblNumberBetween(0, DBL_MAX,
            "\nIs Not Valid Amount, Enter Again : ");

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadDblNumberBetween(0, DBL_MAX,
                "\nIs Not Valid Amount, Enter Again : ");
        }

        return Amount;
    }

public:

	static void ShowTransferScreen()
	{
        _DrawScreenHeader("\t    Transfer Screen");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("From"));
        _PrintClient(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("To"));
        _PrintClient(DestinationClient);
        
        double Amount = _ReadAmount(SourceClient);

        cout << "\nAre you sure you want to Perform this operation ? (y/n) : ";

        char answer = 'n';
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
            {
                cout << "\nTransfer done Successfully." << endl;
            }
            else
            {
                cout << "\nFailed To Transfer!" << endl;
            }
        }

        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);
	}
};

