#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"

using namespace std;

class clsTransferLogScreen : protected clsScreen
{
private:

	static void _PrintTransferLogLine(clsBankClient::stTransferLogRecord Log)
	{
        cout << "\t\t| " << setw(22) << left << Log.DateTime;
        cout << "| " << setw(8) << left << Log.SourceAcct;
        cout << "| " << setw(8) << left << Log.DestinationAcct;
        cout << "| " << setw(18) << left << Log.Amount;
        cout << "| " << setw(18) << left << Log.SourceBalance;
        cout << "| " << setw(18) << left << Log.SourceBalance;
        cout << "| " << setw(5) << left << Log.User;
	}

public:

	static void ShowTransferLogScreen()
	{
        vector<clsBankClient::stTransferLogRecord> vTransferLogList = clsBankClient::GetTransferLogList();

        string Title = "\t     Transfer Log List Screen";
        string SubTitle = "\t          (" + to_string(vTransferLogList.size())
            + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle, 55);

        cout << "\n\t\t_______________________________________________________";
        cout << "_____________________________________________________________\n" << endl;

        cout << "\t\t| " << left << setw(22) << "Data/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(18) << "Amount";
        cout << "| " << left << setw(18) << "s.Balance";
        cout << "| " << left << setw(18) << "d.Balance";
        cout << "| " << left << setw(5) << "User";

        cout << "\n\t\t_______________________________________________________";
        cout << "_____________________________________________________________\n" << endl;

        if (vTransferLogList.size() == 0)
            cout << "\t\t\t\t\t\t      No Transfer Logs Available In the System!\n";
        else

            for (clsBankClient::stTransferLogRecord& Log : vTransferLogList)
            {
                _PrintTransferLogLine(Log);
                cout << endl;
            }

        cout << "\t\t_______________________________________________________";
        cout << "_____________________________________________________________\n" << endl;
	}
};

