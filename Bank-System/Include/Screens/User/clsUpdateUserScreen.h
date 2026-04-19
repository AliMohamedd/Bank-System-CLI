#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

using namespace std;

class clsUpdateUserScreen : protected clsScreen
{
private:

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nPlease Enter FirstName : ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nPlease Enter LastName : ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nPlease Enter Email : ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nPlease Enter Phone : ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nPlease Enter Password : ";
        User.Password = clsInputValidate::ReadString();

        User.Permissions = _ReadUserPermissions();
    }

    static short _ReadUserPermissions()
    {
        short Permissions = 0;
        char AllPerms = 'n';

        cout << "\nDo you want to give full access? (y/n) : ";
        cin >> AllPerms;

        if (AllPerms == 'y' || AllPerms == 'Y')
            Permissions = clsUser::enPermission::eAll;
        else
        {
            char CurrentPerm = 'n';

            cout << "\nDo you want to give access to :";

            cout << "\n\nShow Client List? y/n? ";
            cin >> CurrentPerm;
            Permissions = (CurrentPerm == 'y' || CurrentPerm == 'Y') ?
                clsUser::enPermission::pListClients : 0;

            cout << "\nAdd New Client? y/n? ";
            cin >> CurrentPerm;
            Permissions += (CurrentPerm == 'y' || CurrentPerm == 'Y') ?
                clsUser::enPermission::pAddNewClient : 0;

            cout << "\nDelete Client? y/n? ";
            cin >> CurrentPerm;
            Permissions += (CurrentPerm == 'y' || CurrentPerm == 'Y') ?
                clsUser::enPermission::pDeleteClient : 0;

            cout << "\nUpdate Client? y/n? ";
            cin >> CurrentPerm;
            Permissions += (CurrentPerm == 'y' || CurrentPerm == 'Y') ?
                clsUser::enPermission::pUpdateClients : 0;

            cout << "\nFind Client? y/n? ";
            cin >> CurrentPerm;
            Permissions += (CurrentPerm == 'y' || CurrentPerm == 'Y') ?
                clsUser::enPermission::pFindClient : 0;

            cout << "\nTransactions? y/n? ";
            cin >> CurrentPerm;
            Permissions += (CurrentPerm == 'y' || CurrentPerm == 'Y') ?
                clsUser::enPermission::pTransactions : 0;

            cout << "\nManage Users? y/n? ";
            cin >> CurrentPerm;
            Permissions += (CurrentPerm == 'y' || CurrentPerm == 'Y') ?
                clsUser::enPermission::pManageUsers : 0;

            cout << "\n\nShow Login Register? y/n? ";
            cin >> CurrentPerm;
            Permissions = (CurrentPerm == 'y' || CurrentPerm == 'Y') ?
                clsUser::enPermission::pShowLoginRegister : 0;
        }

        return Permissions;
    }

    static void PrintUser(clsUser User)
    {
        cout << "\nUser Info:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUserName    : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";
    }

public:

    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("\t  Update User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName : ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExists(UserName))
        {
            cout << "\nThis User is Not Found, Enter New UserName : ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        PrintUser(User);

        cout << "\n\nUpdate Client Info:";
        cout << "\n____________________\n";

        _ReadUserInfo(User);

        clsUser::enSaveResult SaveResult;
        SaveResult = User.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResult::svFailedEmptyObject:
        {
            cout << "Failed To Save Update!" << endl;
            break;
        }

        case clsUser::enSaveResult::svSucceeded:
        {
            cout << "Update Saved Successfully :)" << endl;
        }

        }
    }
};

