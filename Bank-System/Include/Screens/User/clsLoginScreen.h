#pragma once
#include<iostream>
#include<ctime>
#include"clsScreen.h"
#include"clsUser.h"
#include"Global.h"
#include"clsMainScreen.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFailed = false;
		short FaildLoginCount = 0;

		string UserName, Password;

		do
		{
			if (LoginFailed)
			{
				FaildLoginCount++;

				cout << "\nInvalid UserName/Password!";
				cout << "\nYou have " << (3-FaildLoginCount)
					 << " Trial(s) to login.\n\n";
			}

			if (FaildLoginCount == 3)
			{
				cout << "\nYour are Locked after 3 faild trials \n\n";
				return false;
			}

			cout << "Enter Username : ";
			cin >> UserName;

			cout << "Enter Password : ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogIn();
		system("cls");
		clsMainScreen::ShowMainMenuScreen();
		
		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		_DrawScreenHeader("\t     Login Screen");
		return _Login();
	}
};

