#pragma once
#include<iostream>
#include"clsScreen.h"

using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "\nCurrency Card:")
	{
		cout << "\n" << Title;
		cout << "\n___________________";
		cout << "\nCountry     : " << Currency.Country();
		cout << "\nCode        : " << Currency.CurrencyCode();
		cout << "\nName        : " << Currency.CurrencyName();
		cout << "\nRate(1$) =  : " << Currency.Rate();
		cout << "\n___________________\n";
	}

    static clsCurrency _ReadCurrency(short Number)
    {
        string AccountNumber = "";
        cout << "\nPlease Enter Currency" << Number << " Code: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExists(AccountNumber))
        {
            cout << "\nInvalid Currency Code, Enter Again: ";
            AccountNumber = clsInputValidate::ReadString();
        }

		cout << endl;

		clsCurrency Currency = clsCurrency::FindByCode(AccountNumber);
        return Currency;
    }
    
    static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
    {
        _PrintCurrencyCard(Currency1, "Convert From:");

        float AmountInUSD = Currency1.ConvertToUSD(Amount);

        cout << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInUSD << " USD\n";

        if (Currency2.CurrencyCode() == "USD")
        {
            return;
        }

        cout << "\nConverting from USD to:\n";

        _PrintCurrencyCard(Currency2, "To:");

        float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

        cout << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();

    }
public: 
	static void ShowCurrencyCalculatorScreen()
	{
        char Continue = 'n';

        while (Continue == 'Y' || Continue == 'y')
        {
            system("cls");

            _DrawScreenHeader("      Currency Calculator Screen");

            clsCurrency Currency1 = _ReadCurrency(1);

            clsCurrency Currency2 = _ReadCurrency(2);

            cout << "\nEnter Amount To Exchange: ";
            float Amount = clsInputValidate::ReadDblNumberBetween(0, FLT_MAX,
                "\nInvalid Amount, Enter Again: ");

            _PrintCalculationsResults(Amount, Currency1, Currency2);

            cout << "\n\nDo you want to perform another calculation? (y/n) : ";
            cin >> Continue;
        }
	}
};

