#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"

using namespace std;

class clsUserListScreen : protected clsScreen
{
private:

    static void _PrintUserRecordLine(clsUser User)
    {
        cout << "\t\t| " << setw(10) << left << User.UserName;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(19) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(23) << left << User.Email;
        cout << "| " << setw(11) << left << to_string(User.Permissions);
    }

public:

    static void ShowUsersListScreen()
    {
        vector<clsUser> vUsersList = clsUser::GetUsersList();

        string Title = "\t         User List Screen";
        string SubTitle = "\t           (" + to_string(vUsersList.size())
            + ") User(s).";

        _DrawScreenHeader(Title, SubTitle, 55);

        cout << "\n\t\t_______________________________________________________";
        cout << "_____________________________________________________________\n" << endl;

        cout << "\t\t| " << left << setw(10) << "UserName";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(19) << "FullName";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(23) << "Email";
        cout << "| " << left << setw(11) << "Permissions";

        cout << "\n\t\t_______________________________________________________";
        cout << "_____________________________________________________________\n" << endl;

        if (vUsersList.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser& User : vUsersList)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << "\t\t_______________________________________________________";
        cout << "_____________________________________________________________\n" << endl;
    }
};

