#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"

using namespace std;

class clsCurrenciesListScreen : protected clsScreen
{
private:
    static void _PrintCurrencyRecord(clsCurrency Currency)
    {
        cout << "\t\t| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(9) << left << Currency.CurrencyCode();
        cout << "| " << setw(58) << left << Currency.CurrencyName();
        cout << "| " << setw(5) << left << Currency.Rate();
    }
public:
	static void ShowCurrenciesListScreen()
	{
        vector<clsCurrency> vCurrenciesList = clsCurrency::GetCurrenciesList();

        string Title = "\t       Currencies List Screen";
        string SubTitle = "\t\t   (" + to_string(vCurrenciesList.size())
            + ") Currency.";

        _DrawScreenHeader(Title, SubTitle, 55);

        cout << "\n\t\t_______________________________________________________";
        cout << "_____________________________________________________________\n" << endl;

        cout << "\t\t| " << left << setw(30) << "Country";
        cout << "| " << left << setw(9) << "Code";
        cout << "| " << left << setw(58) << "Name";
        cout << "| " << left << setw(5) << "Rate/(1$)";
        cout << "\n\t\t_______________________________________________________";
        cout << "_____________________________________________________________\n" << endl;

        if (vCurrenciesList.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency & C : vCurrenciesList)
            {
                _PrintCurrencyRecord(C);
                cout << endl;
            }

        cout << "\t\t_______________________________________________________";
        cout << "_____________________________________________________________\n" << endl;
	}
};

