#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"

using namespace std;

class clsClientsListScreen : protected clsScreen
{
private:
    static void _PrintClientRecordLine(clsBankClient Client)
    {
        cout << "\t\t| " << setw(16) << left << Client.AccountNumber;
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(23) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << to_string(Client.AccountBalance);
    }

public:

    static void ShowClientsListScreen()
    {
        if (!_CheckAccessRights(clsUser::enPermission::pListClients))
        {
            return;
        }

        vector<clsBankClient> vClientsList = clsBankClient::GetClientList();

        string Title = "\t\t Client List Screen";
        string SubTitle = "\t\t   (" + to_string(vClientsList.size()) 
            + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle, 55);
        
        cout << "\n\t\t_______________________________________________________";
        cout << "_____________________________________________________________\n" << endl;

        cout << "\t\t| " << left << setw(16) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(23) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n\t\t_______________________________________________________";
        cout << "_____________________________________________________________\n" << endl;

        if (vClientsList.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClientsList)
            {

                _PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << "\t\t_______________________________________________________";
        cout << "_____________________________________________________________\n" << endl;
    }

};

