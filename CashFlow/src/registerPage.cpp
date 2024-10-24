#include "../lib/precompile.h"
#include "../lib/pageHandle.h"
#include "../lib/registerPage.h"

void reg::displayRegisterPage()
{
	DrawTextEx(customFont, "Program The Future!", Vector2{ 710, 280 }, 50, 3, BLACK);

	//Draw username text box
	DrawRectangle(520, 415, 280, 45, RAYWHITE);
	
	//Draw back button
	DrawRectangle(100, 50, 70, 70, BLUE);
	DrawText("<-", 105, 53, 70, LIGHTGRAY);

	//Draw password text box
	DrawRectangle(520, 515, 280, 45, RAYWHITE);
	
	//Draw register button
	DrawRectangle(520, 660, 280, 90, BLUE);
	DrawText("Register", 575, 685, 40, LIGHTGRAY);

	DrawRectangleLinesEx(Border, 1, borderColor);
}

void reg::buttonHandler(pageBools& pages)
{
	//register button
	if (CheckCollisionPointRec(GetMousePosition(), registerButton))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			
			pages.mainPageShouldDisplay = true;
			pages.registerPageShouldDisplay = false;
			pages.loginPageShouldDisplay = false;
			
		}
		return;
	}
	//back button
	if (CheckCollisionPointRec(GetMousePosition(), backButton))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			pages.mainPageShouldDisplay = true;
			pages.registerPageShouldDisplay = false;
			pages.loginPageShouldDisplay = false;
		}
		return;
	}
}
