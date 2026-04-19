#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUtil.h"
#include"clsInputValidate.h"
#include"clsUserListScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"

using namespace std;

class clsManageUsersScreen : protected clsScreen
{
private:
	static enum _enManageUsersMenuOptions
	{
		eListUsers = 1, eAddNewUser = 2,
		eDeleteUser = 3, eUpdateUser = 4,
		eFindUser = 5, eMainMenuFromManageUsers = 6
	};

	static short _ReadManageUsersMenuOption()
	{
		cout << "\n\t\t\t\t      Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(0, 7,
			"\t\t\t\t      Invalid Number, Enter again : ");
		return Choice;
	}

	static void _GoBackToManageUsersMenu()
	{
		cout << "\n\n\t\tPress any key to go back to Manage Users Menu...";
		system("pause>0");
		system("cls");
		ShowManageUsersMenuScreen();
	}

	static void _ShowUsersListScreen()
	{
		//cout << "This is will be Users List Screen.";
		clsUserListScreen::ShowUsersListScreen();
	}

	static void _ShowAddNewUserScreen()
	{
		//cout << "This is will be Add New Users Screen.";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		//cout << "This is will be Delete User Screen.";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		//cout << "This is will be Update User Screen.";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		//cout << "This is will be Find User Screen.";
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersOption(_enManageUsersMenuOptions _ManageUsersMenuOption)
	{
		switch (_ManageUsersMenuOption)
		{
		case _enManageUsersMenuOptions::eListUsers:
			system("cls");
			_ShowUsersListScreen();
			_GoBackToManageUsersMenu();
			break;
		case _enManageUsersMenuOptions::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenu();
			break;
		case _enManageUsersMenuOptions::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenu();
			break;
		case _enManageUsersMenuOptions::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenu();
			break;
		case _enManageUsersMenuOptions::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenu();
			break;
		case _enManageUsersMenuOptions::eMainMenuFromManageUsers:
			break;
		default:
			cout << "Wrong Choice, Please try again? ";
			_GoBackToManageUsersMenu();
			break;
		}
	}

public:
	static void ShowManageUsersMenuScreen()
	{
		if (!_CheckAccessRights(clsUser::enPermission::pManageUsers))
		{
			return;
		}

		_DrawScreenHeader("\t  Manage Users Screen");

		clsUtil::Tabs(3); clsUtil::PrintTimesChar(14, ' ');
		clsUtil::PrintTimesChar(42, '='); cout << endl;
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(23, ' '); cout << "Manage Users Menu Screen\n";
		clsUtil::Tabs(3); clsUtil::PrintTimesChar(14, ' ');
		clsUtil::PrintTimesChar(42, '=');
		cout << "\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[1] Show Users List.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[2] Add New User.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[3] Delete User.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[4] Update User.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[5] Find User.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[6] Main Menu.\n";
		clsUtil::Tabs(3); clsUtil::PrintTimesChar(14, ' ');
		clsUtil::PrintTimesChar(42, '=');
		_PerformManageUsersOption((_enManageUsersMenuOptions)_ReadManageUsersMenuOption());
	}
};

