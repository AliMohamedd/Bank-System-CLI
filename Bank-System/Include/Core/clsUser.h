#pragma once
#include<fstream>
#include<vector>
#include"clsPerson.h";
#include"clsString.h";
#include"clsUtil.h"

using namespace std;

class clsUser : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _UserName;
	string _Password;
	short _Permissions;

	bool _MarkForDelete = false;

	struct stLoginRegister;

	string _PrepareLoginRecord(string Seperator = "#//#")
	{
		string DataLine;

		DataLine = clsDate::GetSystemDateTimeString() + Seperator;
		DataLine += _UserName + Seperator;
		DataLine += clsUtil::EncryptText(_Password, 12) + Seperator;
		DataLine += to_string(_Permissions);

		return DataLine;
	}

	static stLoginRegister _ConvertLineToLoginRegister(string Line, string Seperator = "#//#")
	{
		vector<string> vRegisterRecord = clsString::Split(Line, Seperator);
		stLoginRegister LoginRegister;
		LoginRegister.DateTime = vRegisterRecord[0];
		LoginRegister.UserName = vRegisterRecord[1];
		LoginRegister.Password = clsUtil::DecryptText(vRegisterRecord[2], 12);
		LoginRegister.Permission = vRegisterRecord[3];

		return LoginRegister;
	}

	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData = clsString::Split(Line, Seperator);

		return clsUser(enMode::UpdateMode, vClientData[0], vClientData[1],
			vClientData[2], vClientData[3], vClientData[4], 
			clsUtil::DecryptText(vClientData[5], 12),
			stoi(vClientData[6]));
	}

	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
	{
		string Line;
		Line = User.FirstName + Seperator;
		Line += User.LastName + Seperator;
		Line += User.Email + Seperator;
		Line += User.Phone + Seperator;
		Line += User.UserName + Seperator;
		Line += clsUtil::EncryptText(User.Password, 12) + Seperator;
		Line += to_string(User.Permissions);
		return Line;
	}

	static vector<clsUser> _LoadUserDataFromFile()
	{
		vector<clsUser> _vUsersList;

		fstream File;
		File.open("UsersDB.txt", ios::in);

		if (File.is_open())
		{
			string Line;

			while (getline(File, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				_vUsersList.push_back(User);
			}
			File.close();
		}
		else
		{
			cout << "File Not Oppened!" << endl;
		}
		return _vUsersList;
	}

	static void _SaveUserDataToFile(vector<clsUser>& vUserList)
	{
		fstream File;
		File.open("UsersDB.txt", ios::out);
		if (File.is_open())
		{
			for (clsUser& C : vUserList)
			{
				if (C.MarkForDelete == false)
				{
					File << _ConvertUserObjectToLine(C) << endl;
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
		File.open("UsersDB.txt", ios::app);

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
		vector<clsUser> _vUserList = _LoadUserDataFromFile();

		for (clsUser& C : _vUserList)
		{
			if (C.UserName == UserName)
			{
				C = *this;
				break;
			}
		}

		_SaveUserDataToFile(_vUserList);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:
	struct stLoginRegister
	{
		string DateTime;
		string UserName;
		string Password;
		string Permission;
	};

	enum enPermission
	{
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64,
		pShowLoginRegister = 128, pShowCurrencyExchange = 256
	};

	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string UserName, string Password, int Permissions) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	string GetUserName()
	{
		return _UserName;
	}

	__declspec(property(get = GetUserName)) string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	int GetPermissions()
	{
		return _Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

	bool GetMarkForDelete()
	{
		return _MarkForDelete;
	}

	__declspec(property(get = GetMarkForDelete)) bool MarkForDelete;

	void Print()
	{
		cout << "\nUser Info:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nUserName    : " << _UserName;
		cout << "\nPassword    : " << _Password;
		cout << "\nPermissions : " << _Permissions;
		cout << "\n___________________\n";
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsUser Find(string UserName)
	{
		fstream File;
		File.open("UsersDB.txt", ios::in);

		if (File.is_open())
		{
			string Line;

			while (getline(File, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName)
				{
					File.close();
					return User;
				}
			}

			File.close();
		}

		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string Password)
	{
		fstream File;
		File.open("UsersDB.txt", ios::in);

		if (File.is_open())
		{
			string Line;

			while (getline(File, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName && User.Password == Password)
				{
					File.close();
					return User;
				}
			}

			File.close();
		}

		return _GetEmptyUserObject();
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	bool Delete()
	{
		vector<clsUser> _vUsersList;
		_vUsersList = _LoadUserDataFromFile();

		for (clsUser& C : _vUsersList)
		{
			if (C.UserName == UserName)
			{
				_MarkForDelete = true;
				C = *this;
				_SaveUserDataToFile(_vUsersList);
				*this = _GetEmptyUserObject();
				return true;
			}
		}
		return false;
	}

	enum enSaveResult { svFailedEmptyObject = 0, svSucceeded = 1, svFailedUserExist = 2 };

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
			if (IsUserExists(_UserName))
			{
				return enSaveResult::svFailedUserExist;
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

	static vector<clsUser> GetUsersList()
	{
		return _LoadUserDataFromFile();
	}

	static bool IsUserExists(string UserName)
	{
		clsUser Client = Find(UserName);
		return (!Client.IsEmpty());
	}

	bool CheckAccessPermission(enPermission Permission)
	{
		if (this->Permissions == enPermission::eAll)
			return true;

		if ((Permission & this->Permissions) == Permission)
			return true;
		else
			return false;
	}

	void RegisterLogIn()
	{
		string DataLine = _PrepareLoginRecord();

		fstream File;
		File.open("LoginRegister.txt", ios::out | ios::app);

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

	static vector<stLoginRegister> GetLoginRegisterList()
	{
		vector<stLoginRegister> vLoginRegisterList;

		fstream File;
		File.open("LoginRegister.txt", ios::in);

		if (File.is_open())
		{
			string Line;

			stLoginRegister LoginRegisterRecord;

			while (getline(File, Line))
			{
				LoginRegisterRecord = _ConvertLineToLoginRegister(Line);
				vLoginRegisterList.push_back(LoginRegisterRecord);
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

