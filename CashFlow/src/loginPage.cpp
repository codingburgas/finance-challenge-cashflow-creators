#include "../lib/precompile.h"
#include "../lib/loginPage.h"

void login::displayLoginPage()
{
	//Draw back button
	DrawRectangle(100, 50, 70, 70, BLUE);
	DrawText("<-", 105, 53, 70, LIGHTGRAY);

	//Draw username text box
	DrawRectangle(520, 415, 280, 45, RAYWHITE);
	
	//Draw password text box
	DrawRectangle(520, 515, 280, 45, RAYWHITE);
	
	//Draw login button
	DrawRectangle(520, 660, 280, 90, BLUE);
	DrawText("Login", 605, 685, 40, LIGHTGRAY);

	DrawRectangleLinesEx(Border, 1, borderColor);
}

void login::buttonHandler(pageBools& pages)
{
	if (CheckCollisionPointRec(GetMousePosition(), loginButton))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			pages.mainPageShouldDisplay = true;
			pages.registerPageShouldDisplay = false;
			pages.loginPageShouldDisplay = false;
			
		}
	}

	if (CheckCollisionPointRec(GetMousePosition(), backButton))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			pages.mainPageShouldDisplay = true;
			pages.registerPageShouldDisplay = false;
			pages.loginPageShouldDisplay = false;
		}
	}
}

