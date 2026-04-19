#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUtil.h"
#include"clsInputValidate.h"
#include"clsClientsListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUSersScreen.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyExchangeScreen.h"
#include"Global.h"
#include"clsUser.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:
	enum _enCurrencyExchangeOptions
	{
		eListClients = 1, eAddNewClient = 2,
		eDeleteClient = 3, eUpdateClient = 4,
		eFindClient = 5, eTransactions = 6,
		eManageUsers = 7, eLoginRegister = 8,
		eCurrencyExchange = 9, eLogout = 10
	};

	static void _GoBackToMainMenuScreen()
	{
		cout << "\n\n\t\tPress any key to go back to Main Menu...";
		system("pause>0");
		system("cls");
		ShowMainMenuScreen();
	}

	static short _ReadMainMenueOption()
	{
		cout << "\n\t\t\t\t      Choose what do you want to do? [1 to 10]? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(0, 11,
			"\t\t\t\t      Invalid Number, Enter again : ");
		return Choice;
	}

	static void _ShowClientsListScreen()
	{
		//cout << "This is will be Client list screen." << endl;
		clsClientsListScreen::ShowClientsListScreen();
	}

	static void _ShowAddNewClientsScreen()
	{
		//cout << "This is will be Add New Client Screen." << endl;
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		//cout << "This is will be Delete Client Screen." << endl;
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		//cout << "This is will be Update Client Screen." << endl;
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		//cout << "This is will be Find Client Screen." << endl;
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenuScreen()
	{
		//cout << "This is will be Transactions Menu Screen." << endl;
		clsTransactionsScreen::ShowTransactionsMenuScreen();
	}

	static void _ShowManageUsersMenuScreen()
	{
		//cout << "This is will be Manage Users Menu Screen." << endl;
		clsManageUsersScreen::ShowManageUsersMenuScreen();
	}

	static void _LoginRegisterScreen()
	{
		//cout << "Login Register will be here.";
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeScreen()
	{
		//cout << "This is will be Currency Exchange Screen";
		clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
	}

	static void _Login()
	{
		cout << "This is will be Login Screen." << endl;
		_GoBackToMainMenuScreen();
	}
	
	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
		// Then will go back from calling stack.
	}

	static void _PerformMainMenuOption(_enCurrencyExchangeOptions _MainMenueOption)
	{
		switch (_MainMenueOption)
		{
		case _enCurrencyExchangeOptions::eListClients:
			system("cls");
			_ShowClientsListScreen();
			_GoBackToMainMenuScreen();
			break;
		case _enCurrencyExchangeOptions::eAddNewClient:
			system("cls");
		    _ShowAddNewClientsScreen();
			_GoBackToMainMenuScreen();
			break;
		case _enCurrencyExchangeOptions::eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenuScreen();
			break;
		case _enCurrencyExchangeOptions::eUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenuScreen();
			break;
		case _enCurrencyExchangeOptions::eFindClient:
			system("cls");
            _ShowFindClientScreen();
			_GoBackToMainMenuScreen();
			break;
		case _enCurrencyExchangeOptions::eTransactions:
			system("cls");
			_ShowTransactionsMenuScreen();
			_GoBackToMainMenuScreen();
			break;
		case _enCurrencyExchangeOptions::eManageUsers:
			system("cls");
			_ShowManageUsersMenuScreen();
			_GoBackToMainMenuScreen();
			break;
		case _enCurrencyExchangeOptions::eLoginRegister:
			system("cls");
			_LoginRegisterScreen();
			_GoBackToMainMenuScreen();
			break;
		case _enCurrencyExchangeOptions::eCurrencyExchange:
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenuScreen();
			break;
		case _enCurrencyExchangeOptions::eLogout:
			system("cls");
			_Logout();
			break;
		default:
			cout << "Wrong Choice, Please try again? ";
			_GoBackToMainMenuScreen();
			break;
		}
	}

public:

	static void ShowMainMenuScreen()
	{
		_DrawScreenHeader("\t      Main Screen");
		clsUtil::Tabs(3);clsUtil::PrintTimesChar(14, ' ');
		clsUtil::PrintTimesChar(42, '='); cout << endl;
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(27 , ' '); cout << "Main Menu Screen\n";
		clsUtil::Tabs(3); clsUtil::PrintTimesChar(14, ' ');
		clsUtil::PrintTimesChar(42, '=');
		cout << "\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[1] Show Clien List.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[2] Add New Client.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[3] Delete Client.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[4] Update Client Info.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[5] Find Client.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[6] Transactions.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[7] Manage Users.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[8] Login Register.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[9] Currency Exchange.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[10] Logout.\n";
		clsUtil::Tabs(3); clsUtil::PrintTimesChar(14, ' ');
		clsUtil::PrintTimesChar(42, '=');
		_PerformMainMenuOption((_enCurrencyExchangeOptions)_ReadMainMenueOption());
	}
};

