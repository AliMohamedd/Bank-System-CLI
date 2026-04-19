#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

using namespace std;

class clsUpdateCurrencyRateScreen: protected clsScreen
{
private:
	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n___________________";
		cout << "\nCountry     : " << Currency.Country();
		cout << "\nCode        : " << Currency.CurrencyCode();
		cout << "\nName        : " << Currency.CurrencyName();
		cout << "\nRate(1$) =  : " << Currency.Rate();
		cout << "\n___________________\n";
	}
public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Screen");

		string CountryCode = "";
		cout << "\nPlease Enter Currency Code: ";

		CountryCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExists(CountryCode))
		{
			cout << "\nInvalid Country Code, Please Enter Again : ";
			CountryCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CountryCode);
		_PrintCurrencyCard(Currency);

		cout << "\nAre you sure you want to update the rate of this currency? (y/n) : ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n\nUpdate Currency Rate:";
			cout << "\n____________________";

			cout << "\n\nEnter New Rate: ";
			float CurrencyRate = clsInputValidate::ReadDblNumberBetween(0, FLT_MAX);
			Currency.UpdateRate(CurrencyRate);

			cout << "\nCurrency Rate Updated Successfully." << endl;
			_PrintCurrencyCard(Currency);
		}
		
	}
};

