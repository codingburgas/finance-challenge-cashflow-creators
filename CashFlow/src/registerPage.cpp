#include "../lib/precompile.h"
#include "../lib/pageHandle.h"
#include "../lib/registerPage.h"
#include "../lib/precompile.h"
#include "../lib/pageHandle.h"
#include "../lib/registerPage.h"

void reg::displayRegisterPage()
{
    DrawTextEx(customFont, "Program The Future!", Vector2{ 710, 280 }, 50, 3, BLACK);

    //Draw username text box
    DrawRectangle(520, 415, 280, 45, RAYWHITE);
    DrawRectangleLinesEx(usernameText, borderThickness, borderColor);
    if (firstName.size() > 0)
    {
        DrawText(firstName.c_str(), 535, 430, 20, GRAY);
    }
    else DrawText("First Name", 535, 430, 20, LIGHTGRAY);

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

void reg::textBoxHandler()
{
    if (CheckCollisionPointRec(GetMousePosition(), usernameTextHitbox))
    {
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
        int key = GetCharPressed();
        if ((key >= 32) && (key <= 125) && (firstName.size() < 14))
        {
            firstName.push_back((char)key);
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            if (firstName.size() > 0)
                firstName.pop_back();
        }
        return;
    }

    if (CheckCollisionPointRec(GetMousePosition(), passwordTextHitbox))
    {
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
        int key = GetCharPressed();
        if ((key >= 32) && (key <= 125) && (lastName.size() < 14))
        {
            lastName.push_back((char)key);
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            if (lastName.size() > 0)
                lastName.pop_back();
        }
        return;
    }
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}
bool reg::registerHandler() {
    registerUser(firstName, lastName, email, phoneNum);            //Registers the users info into the database
}