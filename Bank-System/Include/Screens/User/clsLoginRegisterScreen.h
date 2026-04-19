#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"

using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{
private:

    static void _PrintLoginRegisterLine(clsUser::stLoginRegister& User)
    {
        cout << "\t\t| " << setw(44) << left << User.DateTime;
        cout << "| " << setw(20) << left << User.UserName;
        cout << "| " << setw(20) << left << User.Password;
        cout << "| " << setw(5) << left << User.Permission;
    }
public:

    static void ShowLoginRegisterScreen()
    {
        if (!_CheckAccessRights(clsUser::enPermission::pShowLoginRegister))
        {
            return;
        }

        vector<clsUser::stLoginRegister> vLoginRegisterList = clsUser::GetLoginRegisterList();

        string Title = "\t     Login Register List Screen";
        string SubTitle = "\t          (" + to_string(vLoginRegisterList.size())
            + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle, 55);

        cout << "\n\t\t_______________________________________________________";
        cout << "_____________________________________________________________\n" << endl;

        cout << "\t\t| " << left << setw(44) << "Data/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(5) << "Permissions";

        cout << "\n\t\t_______________________________________________________";
        cout << "_____________________________________________________________\n" << endl;

        if (vLoginRegisterList.size() == 0)
            cout << "\t\t\t\t\t\t     No Registers Available In the System!\n";
        else

            for (clsUser::stLoginRegister& User : vLoginRegisterList)
            {
                _PrintLoginRegisterLine(User);
                cout << endl;
            }

        cout << "\t\t_______________________________________________________";
        cout << "_____________________________________________________________\n" << endl;
    }
};

