#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private:
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

    static void ShowAddNewClientScreen()
    {
        if (!_CheckAccessRights(clsUser::enPermission::pAddNewClient))
        {
            return;
        }

        _DrawScreenHeader("\t    Add New Client");

        string AccountNumber = "";

        cout << "\nPlease Enter AccountNumber : ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExists(AccountNumber))
        {
            cout << "\nThis Account is Already Exist, Enter New AccountNumber : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResult SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResult::svFailedEmptyObject:
        {
            cout << "\nFailed To Save Because It is Empty Object!";
            break;
        }
        case clsBankClient::enSaveResult::svFailedClientExist:
        {
            cout << "\nFailed To Save Because The Client is Already Exist!";
            break;
        }
        case clsBankClient::enSaveResult::svSucceeded:
        {
            cout << "\nClient Saved Successfully." << endl;
            NewClient.Print();
            break;
        }
        }
    }

};

