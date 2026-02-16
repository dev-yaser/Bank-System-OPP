#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private :

  static  bool _Login()
    {
        bool LoginFaild = false;
		short LoginAttempts = 0;
        string Username, Password;
        do
        {
     
            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n\n";
				LoginAttempts++;
				cout << "You have " << 3 - LoginAttempts << " login attempts left.\n\n";
                
            }
            if (LoginAttempts >= 3) {
                cout << "Too many failed login attempts. Exiting the program.\n";
                return false; // Exit the program after 3 failed attempts
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

		CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
		return true;

    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
       return  _Login();

    }

};

