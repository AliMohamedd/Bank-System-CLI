#pragma once
#include<iostream>
#include"clsUtil.h"
#include"Global.h"
#include"clsUser.h"
#include"clsDate.h"

using namespace std;

class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "", short Length = 40)
    {
        clsUtil::PrintTimesChar(Length, ' ');
        cout << "______________________________________";
        cout << "\n\n";
        clsUtil::PrintTimesChar(Length, ' ');
        cout << Title;

        if (SubTitle != "")
        {
            cout << "\n";
            clsUtil::PrintTimesChar(Length, ' ');
            cout << SubTitle;
        }
        cout << "\n";
        clsUtil::PrintTimesChar(Length, ' ');
        cout << "______________________________________\n\n";

        clsUtil::PrintTimesChar(Length, ' ');
        cout << "User : " << CurrentUser.UserName;

        cout << "\n";
        clsUtil::PrintTimesChar(Length, ' ');
        cout << "Date : " << _GetTodayDate();
        cout << "\n" << endl;
    }

    static bool _CheckAccessRights(clsUser::enPermission Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t_____________________________________________";
            cout << "\n\n\t\t\t\t\t      Access Denied! Contact your Admin";
            cout << "\n\t\t\t\t\t_____________________________________________";
            return false;
        }
        else
        {
            return true;
        }
    }

    static string _GetTodayDate()
    {
        clsDate TodayDate;
        return TodayDate.DateToString();;
    }
};

