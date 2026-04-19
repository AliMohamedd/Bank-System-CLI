#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUtil.h"
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private:
	static enum _enTransactionsMenuOptions
	{
		eDeposit = 1, eWithdraw = 2,
		eTotalBalance = 3, eTransfer = 4,
		eShowTransferLog = 5,
		eMainMenuFromTransactions = 6
	};

	static void _GoBackToTransactionsMenu()
	{
		cout << "\n\n\t\tPress any key to go back to Transactions Menu...";
		system("pause>0");
		system("cls");
		ShowTransactionsMenuScreen();
	}

	static short _ReadTransactionsMenuOption()
	{
		cout << "\n\t\t\t\t      Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(0, 7,
			"\t\t\t\t      Invalid Number, Enter again : ");
		return Choice;
	}

	static void _ShowDepositScreen()
	{
		//cout << "This is will be a Deposit Screen";
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		//cout << "This is will be a Withdraw Screen";
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowAllClientsBalacneScreen()
	{
		//cout << "This is will be Clients Balance Screen";
		clsTotalBalancesScreen::ShowTotalBalancesListScreen();
	}

	static void _ShowTransferScreen()
	{
		//cout << "This is will be Transfer Screen.";
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		//cout << "This is will be Transfer Log Screen.";
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _PerformTransactionsOption(_enTransactionsMenuOptions _TransactionsMenueOption)
	{
		switch (_TransactionsMenueOption)
		{
		case _enTransactionsMenuOptions::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenu();
			break;
		case _enTransactionsMenuOptions::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenu();
			break;
		case _enTransactionsMenuOptions::eTotalBalance:
			system("cls");
			_ShowAllClientsBalacneScreen();
			_GoBackToTransactionsMenu();
			break;
		case _enTransactionsMenuOptions::eTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenu();
		case _enTransactionsMenuOptions::eShowTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenu();
			break;
		case _enTransactionsMenuOptions::eMainMenuFromTransactions:
			break;
		default:
			cout << "Wrong Choice, Please try again? ";
			_GoBackToTransactionsMenu();
			break;
		}
	}

public:
	static void ShowTransactionsMenuScreen()
	{
		if (!_CheckAccessRights(clsUser::enPermission::pTransactions))
		{
			return;
		}

		_DrawScreenHeader("\t  Transactions Screen");

		clsUtil::Tabs(3); clsUtil::PrintTimesChar(14, ' ');
		clsUtil::PrintTimesChar(42, '='); cout << endl;
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(23, ' '); cout << "Transactions Menu Screen\n";
		clsUtil::Tabs(3); clsUtil::PrintTimesChar(14, ' ');
		clsUtil::PrintTimesChar(42, '=');
		cout << "\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[1] Deposit.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[2] Withdraw.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[3] Total Balance.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[4] Transfer.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[5] Transfer Log.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[6] Main Menue.\n";
		clsUtil::Tabs(3); clsUtil::PrintTimesChar(14, ' ');
		clsUtil::PrintTimesChar(42, '=');

		_PerformTransactionsOption((_enTransactionsMenuOptions)_ReadTransactionsMenuOption());
	}
};

