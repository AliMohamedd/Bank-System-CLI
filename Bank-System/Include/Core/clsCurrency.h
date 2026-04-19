#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsString.h"

using namespace std;

class clsCurrency
{
private:
	enum enMode{ EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string DataLine, string Seperator = "#//#")
	{
		vector<string> vDataList = clsString::Split(DataLine, Seperator);
		
		return clsCurrency(enMode::UpdateMode, vDataList[0], vDataList[1],
			vDataList[2], stof(vDataList[3]));
	}

	string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{
		string DataLine;

		DataLine = Currency.Country() + Seperator;
		DataLine += Currency.CurrencyCode() + Seperator;
		DataLine += Currency.CurrencyName() + Seperator;
		DataLine += to_string(Currency.Rate());

		return DataLine;
	}

	static vector<clsCurrency> _LoadCurrenciesDataFromFile()
	{
		vector<clsCurrency> vCurrenciesList;

		fstream File;
		File.open("Currencies.txt", ios::in);

		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrenciesList.push_back(Currency);
			}
			File.close();
		}
		else
		{
			cout << "\nFile Not Opened!" << endl;
		}

		return vCurrenciesList;
	}

	void _SaveCurrenciesDataToFile(vector<clsCurrency> vCurrenciesList)
	{
		fstream File;
		File.open("Currencies.txt", ios::out);

		if (File.is_open())
		{
			string DataLine;
			for (clsCurrency& Currency : vCurrenciesList)
			{
				DataLine = _ConvertCurrencyObjectToLine(Currency);
				File << DataLine << endl;
			}
			File.close();
		}
		else
		{
			cout << "\nFile Not Opened!" << endl;
		}
	}

	void _Update()
	{
		vector<clsCurrency> vCurrenciesList = _LoadCurrenciesDataFromFile();

		for (clsCurrency& Currency : vCurrenciesList)
		{
			if (Currency.Country() == _Country)
			{
				Currency = *this;
				break;
			}
		}

		_SaveCurrenciesDataToFile(vCurrenciesList);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode,
		string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	float Rate()
	{
		return _Rate;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream File;
		File.open("Currencies.txt", ios::in);

		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					File.close();
					return Currency;
				}
			}

			File.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream File;
		File.open("Currencies.txt", ios::in);

		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					File.close();
					return Currency;
				}
			}

			File.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExists(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());

	}

	static vector<clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrenciesDataFromFile();
	}

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Currency2.Rate());
	}
};

