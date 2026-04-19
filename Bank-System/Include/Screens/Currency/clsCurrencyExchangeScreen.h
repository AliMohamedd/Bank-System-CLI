#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen
{
private:
	enum _enCurrencyExchangeOptions
	{
		eListCurrencies = 1, eFindCurrency = 2,
		eUpdateRate = 3, eCurrencyCalculator = 4,
		eMainMenuFromCurrencyExchange = 5
	};

	static void _GoBackToCurrencyExchangeScreen()
	{
		cout << "\n\n\t\tPress any key to go back to Currency Exchange Menu...";
		system("pause>0");
		system("cls");
		ShowCurrencyExchangeScreen();
	}

	static short _ReadCurrencyExchangeOption()
	{
		cout << "\n\t\t\t\t      Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(0, 6,
			"\t\t\t\t      Invalid Number, Enter again : ");
		return Choice;
	}

	static void _ShowCurrenciesListScreen()
	{
		//cout << "This is will be Currencies List screen." << endl;
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "This is will be Find Currency Screen." << endl;
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "This is will be Update Rate Screen." << endl;
		clsUpdateCurrencyRateScreen::ShowFindCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "This is will be Currency Calculator Screen." << endl;
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}
	
	static void _PerformCurrencyExchangeOption(_enCurrencyExchangeOptions _CurrencyExchangeOption)
	{
		switch (_CurrencyExchangeOption)
		{
		case _enCurrencyExchangeOptions::eListCurrencies:
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrencyExchangeScreen();
			break;
		case _enCurrencyExchangeOptions::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeScreen();
			break;
		case _enCurrencyExchangeOptions::eUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeScreen();
			break;
		case _enCurrencyExchangeOptions::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeScreen();
			break;
		case _enCurrencyExchangeOptions::eMainMenuFromCurrencyExchange:
			break;
		default:
			cout << "Wrong Choice, Please try again? ";
			_GoBackToCurrencyExchangeScreen();
			break;
		}
	}
public:

	static void ShowCurrencyExchangeScreen()
	{
		if (!_CheckAccessRights(clsUser::enPermission::pShowCurrencyExchange))
		{
			return;
		}

		_DrawScreenHeader("     Currency Exchange Main Screen");

		clsUtil::Tabs(3); clsUtil::PrintTimesChar(14, ' ');
		clsUtil::PrintTimesChar(42, '='); cout << endl;
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(24, ' '); cout << "Currency Exchange Menu\n";
		clsUtil::Tabs(3); clsUtil::PrintTimesChar(14, ' ');
		clsUtil::PrintTimesChar(42, '=');
		cout << "\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[1] List Currencies.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[2] Find Currency.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[3] Update Rate.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[4] Currency Calculator.\n";
		clsUtil::Tabs(3);
		clsUtil::PrintTimesChar(17, ' '); cout << "[5] Main Menu.\n";
		clsUtil::Tabs(3); clsUtil::PrintTimesChar(14, ' ');
		clsUtil::PrintTimesChar(42, '=');
		_PerformCurrencyExchangeOption((_enCurrencyExchangeOptions)_ReadCurrencyExchangeOption());
	}
};

