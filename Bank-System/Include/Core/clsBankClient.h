#pragma once
#include<fstream>
#include<vector>
#include"clsPerson.h";
#include"clsString.h";


class clsBankClient : public clsPerson
{
private:
	enum enMode{EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkForDelete = false;

	string _PrepareTransferRecord(double Amount, clsBankClient DestinationClient,
		string UserName, string Seperator = "#//#")
	{
		string TransferLogRecord;

		TransferLogRecord = clsDate::GetSystemDateTimeString() + Seperator;
		TransferLogRecord += _AccountNumber + Seperator;
		TransferLogRecord += DestinationClient.AccountNumber + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(_AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferLogRecord += UserName;

		return TransferLogRecord;
	}

	struct stTransferLogRecord;

	static stTransferLogRecord _ConvertLineToTransferLogRecord(string Line, string Seperator = "#//#")
	{
		vector<string> vTransferLogRecord = clsString::Split(Line, Seperator);
		stTransferLogRecord TransferLogRecord;

		TransferLogRecord.DateTime = vTransferLogRecord[0];
		TransferLogRecord.SourceAcct = vTransferLogRecord[1];
		TransferLogRecord.DestinationAcct = vTransferLogRecord[2];
		TransferLogRecord.Amount = vTransferLogRecord[3];
		TransferLogRecord.SourceBalance = vTransferLogRecord[4];
		TransferLogRecord.DestinationBalance = vTransferLogRecord[5];
		TransferLogRecord.User = vTransferLogRecord[6];

		return TransferLogRecord;
	}

	void _RegisterTransferLog(double Amount, clsBankClient DestinationClient, string UserName)
	{
		string DataLine = _PrepareTransferRecord(Amount, DestinationClient, UserName);

		fstream File;
		File.open("TransferLog.txt", ios::out | ios::app);

		if (File.is_open())
		{
			File << DataLine << endl;
			File.close();
		}
		else
		{
			cout << "File Not Oppened!" << endl;
		}
	}

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1],
			vClientData[2], vClientData[3], vClientData[4], vClientData[5],
			stod(vClientData[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string Line;
		Line = Client.FirstName + Seperator;
		Line += Client.LastName + Seperator;
		Line += Client.Email + Seperator;
		Line += Client.Phone + Seperator;
		Line += Client.AccountNumber + Seperator;
		Line += Client.PinCode + Seperator;
		Line += to_string(Client.AccountBalance);
		return Line;
	}

	static vector<clsBankClient> _LoadClientDataFromFile()
	{
		vector<clsBankClient> _vClientList;
		
		fstream File;
		File.open("ClientsDB.txt", ios::in);
		
		if (File.is_open())
		{
			string Line;
			
			while (getline(File, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				_vClientList.push_back(Client);
			}
			File.close();
		}
		else
		{
			cout << "File Not Oppened!" << endl;
		}
		return _vClientList;
	}

	static void _SaveClientDataToFile(vector<clsBankClient>& vClientList)
	{
		fstream File;
		File.open("ClientsDB.txt", ios::out);
		if (File.is_open())
		{
			for (clsBankClient& C : vClientList)
			{
				if (C.MarkForDelete == false)
				{
					File << _ConvertClientObjectToLine(C) << endl;
				}
			}
			File.close();
		}
		else
		{
			cout << "File Not Oppened!" << endl;
		}
	}

	void _AddDataLineToFile(string DataLine)
	{
		fstream File;
		File.open("ClientsDB.txt", ios::app);

		if (File.is_open())
		{
			File << DataLine << endl;
			File.close();
		}
		else
		{
			cout << "File Not Oppened!" << endl;
		}
	}

	void _Update() 
	{
		vector<clsBankClient> _vClientList = _LoadClientDataFromFile();

		for (clsBankClient& C : _vClientList)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C = *this;
				break;
			}
		}

		_SaveClientDataToFile(_vClientList);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:

	struct stTransferLogRecord
	{
		string DateTime;
		string SourceAcct;
		string DestinationAcct;
		string Amount;
		string SourceBalance;
		string DestinationBalance;
		string User;
	};

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PinCode, double AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	__declspec(property(get = GetAccountNumber)) string AccountNumber;

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	double GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;

	bool GetMarkForDelete()
	{
		return _MarkForDelete;
	}

	__declspec(property(get = GetMarkForDelete)) bool MarkForDelete;

	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";

	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsBankClient Find(string AccountNumber)
	{
		fstream File;
		File.open("ClientsDB.txt", ios::in);
		
		if (File.is_open())
		{
			string Line;

			while (getline(File, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber == AccountNumber)
				{
					File.close();
					return Client;
				}
			}

			File.close();
		}

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream File;
		File.open("ClientsDB.txt", ios::in);

		if (File.is_open())
		{
			string Line;

			while (getline(File, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber == AccountNumber && Client.PinCode == PinCode)
				{
					File.close();
					return Client;
				}
			}

			File.close();
		}

		return _GetEmptyClientObject();
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector<clsBankClient> _vClientList;
		_vClientList = _LoadClientDataFromFile();

		for (clsBankClient& C : _vClientList)
		{
			if (C.AccountNumber == _AccountNumber)
			{
				_MarkForDelete = true;
				C = *this;
				_SaveClientDataToFile(_vClientList);
				*this = _GetEmptyClientObject();
				return true;
			}
		}
		return false;
	}

	enum enSaveResult{svFailedEmptyObject = 0, svSucceeded = 1, svFailedClientExist = 2};

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			{
				return enSaveResult::svFailedEmptyObject;
			}

		case enMode::UpdateMode:
		    {
			    _Update();
				return enSaveResult::svSucceeded;
		    }
		case enMode::AddNewMode:
		    {
			    if (IsClientExists(_AccountNumber))
			    {
					return enSaveResult::svFailedClientExist;
				}
				else
				{
					_AddNew();
					_Mode = enMode::UpdateMode;
					return enSaveResult::svSucceeded;
				}
		    }
		}
	}
	
	static vector<clsBankClient> GetClientList()
	{
		return _LoadClientDataFromFile();
	}

	static double GetTotalBalances()
	{
		vector<clsBankClient> vClientsList = _LoadClientDataFromFile();

		double TotalBalances = 0;

		for (clsBankClient& C : vClientsList)
		{
			TotalBalances += C.AccountBalance;
		}

		return TotalBalances;
	}

	static bool IsClientExists(string AccountNumber)
	{
		clsBankClient Client = Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else 
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	bool Transfer(double Amount, clsBankClient& DestinationClient, string UserName)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}
		
		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, UserName);

		return true;
	}

	static vector<stTransferLogRecord> GetTransferLogList()
	{
		vector<stTransferLogRecord> vLoginRegisterList;

		fstream File;
		File.open("TransferLog.txt", ios::in);

		if (File.is_open())
		{
			string Line;

			stTransferLogRecord TransferLogRecord;

			while (getline(File, Line))
			{
				TransferLogRecord = _ConvertLineToTransferLogRecord(Line);
				vLoginRegisterList.push_back(TransferLogRecord);
			}
			File.close();
		}
		else
		{
			cout << "File Not Oppened!" << endl;
		}
		return vLoginRegisterList;
	}
};

