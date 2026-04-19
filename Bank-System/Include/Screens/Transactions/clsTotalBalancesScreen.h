#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"

using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
private:
    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << "\t\t   | " << setw(16) << left << Client.AccountNumber;
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << to_string(Client.AccountBalance);
    }

public:
    static void ShowTotalBalancesListScreen()
    {
        vector<clsBankClient> vClientsList = clsBankClient::GetClientList();

        string Title = "\t      Balances List Screen";
        string SubTitle = "\t\t(" + to_string(vClientsList.size())
            + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle, 53);

        cout << "\n\t\t   _______________________________________________________";
        cout << "___________________________________________________\n" << endl;

        cout << "\t\t   | " << left << setw(16) << "Account Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n\t\t   _______________________________________________________";
        cout << "___________________________________________________\n" << endl;

        if (vClientsList.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClientsList)
            {

                _PrintClientRecordBalanceLine(Client);
                cout << endl;
            }

        cout << "\t\t   _______________________________________________________";
        cout << "___________________________________________________\n" << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();

        cout << "\t\t\t\t   Total Balances = " << to_string(TotalBalances) << endl;
        cout << "\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")" << endl;
    }
};

