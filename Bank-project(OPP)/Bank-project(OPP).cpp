#include <iostream>

#include "clsLoginScreen.h"
int main()
{
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen()) {
			break; // Exit the loop and end the program if login fails after 3 attempts
		}
		

	}
	return 0;
}

