#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

class clsUpdateClientScreen : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber;
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }

    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nPlease Enter FirstName : ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nPlease Enter LastName : ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nPlease Enter Email : ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nPlease Enter Phone : ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nPlease Enter PinCode : ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nPlease Enter AccountBalance : ";
        Client.AccountBalance = clsInputValidate::ReadDblNumberBetween(0, DBL_MAX, "\nIs Not Valid Amount, Enter Again : ");
    }

public:
    
    static void ShowUpdateClientScreen()
    {
        if (!_CheckAccessRights(clsUser::enPermission::pUpdateClients))
        {
            return;
        }

        _DrawScreenHeader("\t Update Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExists(AccountNumber))
        {
            cout << "\nAccount Not Found, Enter Again : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "\n\nUpdate Client Info:";
        cout << "\n____________________\n";

        _ReadClientInfo(Client);

        clsBankClient::enSaveResult SaveResult;
        SaveResult = Client.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResult::svFailedEmptyObject:
        {
            cout << "\nFailed To Save Update!" << endl;
            break;
        }

        case clsBankClient::enSaveResult::svSucceeded:
        {
            cout << "\nUpdate Saved Successfully." << endl;
        }

        }
    }
};


