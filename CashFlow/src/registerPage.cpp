#include "../lib/precompile.h"
#include "../lib/pageHandle.h"
#include "../lib/registerPage.h"

void reg::displayRegisterPage()
{
	DrawTextEx(customFont, "Program The Future!", Vector2{ 710, 280 }, 50, 3, BLACK);

	//Draw username text box
	DrawRectangle(820, 415, 280, 45, RAYWHITE);
	DrawRectangleLinesEx(usernameText, borderThickness, borderColor);
	if (username.size() > 0)
	{
		DrawText(username.c_str(), 835, 430, 20, BLACK);
	}
	else DrawText("Username", 835, 430, 20, LIGHTGRAY);

	//Draw back button
	DrawRectangle(1700, 50, 70, 70, BLUE);
	DrawText("<-", 1705, 53, 70, LIGHTGRAY);

	//Draw password text box
	DrawRectangle(820, 515, 280, 45, RAYWHITE);
	DrawRectangleLinesEx(passwordText, borderThickness, borderColor);
	if (password.size() > 0)
	{
		for (int i = 0; i < password.size(); i++)
			DrawText("*", 835 + i * 11, 530, 20, BLACK);
	}
	else DrawText("Password", 835, 530, 20, LIGHTGRAY);

	//Draw register button
	DrawRectangle(820, 660, 280, 90, BLUE);
	DrawText("Register", 875, 685, 40, LIGHTGRAY);

	DrawRectangleLinesEx(Border, 1, borderColor);
}

void reg::buttonHandler(pageBools& pages)
{
	//register button
	if (CheckCollisionPointRec(GetMousePosition(), registerButton))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (registerHandler())
			{
				pages.mainMenuShouldDisplay = false;
				pages.registerPageShouldDisplay = false;
				pages.loginPageShouldDisplay = false;
				pages.preTestPageShouldDisplay = true;
				pages.testPageShouldDisplay = false;
				pages.submitPageShouldDsiplay = false;
			}
		}
		return;
	}
	//back button
	if (CheckCollisionPointRec(GetMousePosition(), backButton))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			pages.mainMenuShouldDisplay = true;
			pages.registerPageShouldDisplay = false;
			pages.loginPageShouldDisplay = false;
			pages.preTestPageShouldDisplay = false;
			pages.testPageShouldDisplay = false;
			pages.submitPageShouldDsiplay = false;
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
		if ((key >= 32) && (key <= 125) && (username.size() < 14))
		{
			username.push_back((char)key);
		}
		if (IsKeyPressed(KEY_BACKSPACE))
		{
			if (username.size() > 0)
				username.pop_back();
		}
		return;
	}

	if (CheckCollisionPointRec(GetMousePosition(), passwordTextHitbox))
	{
		SetMouseCursor(MOUSE_CURSOR_IBEAM);
		int key = GetCharPressed();
		if ((key >= 32) && (key <= 125) && (password.size() < 14))
		{
			password.push_back((char)key);
		}
		if (IsKeyPressed(KEY_BACKSPACE))
		{
			if (password.size() > 0)
				password.pop_back();
		}
		return;
	}
	SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}

bool reg::registerHandler()
{
	bool check = false;
	std::fstream loginFile;
	loginFile.open("../files/login.txt", std::ios::in | std::ios::out);
	if (!loginFile)
		std::cout << "login.txt failed to load!";
	else
	{
		std::string fileLine = createFileLine(username, password);
		check = checkIfInFileLine(loginFile, username);
		loginFile.close();
		loginFile.open("../files/login.txt", std::ios::in | std::ios::out | std::ios::app);
		if (!check)
			writeInFile(loginFile, fileLine);
		loginFile.close();
		return !check;
	}
	return check;
}