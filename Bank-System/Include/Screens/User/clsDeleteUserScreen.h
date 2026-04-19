#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
private:

    static void _PrintUser(clsUser& User)
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

    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\t  Delete User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName : ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExists(UserName))
        {
            cout << "\nThis User is Not Found, Enter New UserName : ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        cout << "\nAre you sure you want to delete this User ? (y/n) : ";

        char answer = 'n';
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            if (User.Delete())
            {
                cout << "\nUser Deleted Successfully." << endl;
                _PrintUser(User);
            }
            else
            {
                cout << "\nFailed To Delete User!";
            }
        }
    }
};

