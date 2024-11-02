#include "../lib/precompile.h"
#include "../lib/loginPage.h"

void login::displayLoginPage()
{
	DrawTextEx(customFont, "Login Before Starting", Vector2{ 700, 280 }, 50, 3, BLACK);

	//Draw back button
	DrawRectangle(1700, 50, 70, 70, BLUE);
	DrawText("<-", 1705, 53, 70, LIGHTGRAY);

	//Draw username text box
	DrawRectangle(820, 415, 280, 45, RAYWHITE);
	DrawRectangleLinesEx(usernameText, borderThickness, borderColor);
	if (username[0] != '\0')
		DrawText(username.c_str(), 835, 430, 20, BLACK);

	else DrawText("Username", 835, 430, 20, LIGHTGRAY);

	//Draw password text box
	DrawRectangle(820, 515, 280, 45, RAYWHITE);
	DrawRectangleLinesEx(passwordText, borderThickness, borderColor);
	if (password[0] != '\0')
	{
		for (int i = 0; i < password.size(); i++)
			DrawText("*", 835 + i * 11, 530, 20, BLACK);
	}
	else DrawText("Password", 835, 530, 20, LIGHTGRAY);

	//Draw login button
	DrawRectangle(820, 660, 280, 90, BLUE);
	DrawText("Login", 905, 685, 40, LIGHTGRAY);

	DrawRectangleLinesEx(Border, 1, borderColor);
}

void login::buttonHandler(pageBools& pages)
{
	if (CheckCollisionPointRec(GetMousePosition(), loginButton))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (loginHandler())
			{
				pages.mainPageShouldDisplay = true;
				pages.registerPageShouldDisplay = false;
				pages.loginPageShouldDisplay = false;
				pages.incomeWindowShouldDisplay = false;
				pages.expensesWindowShouldDisplay = false;
			}
		}
	}

	if (CheckCollisionPointRec(GetMousePosition(), backButton))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			pages.mainPageShouldDisplay = true;
			pages.registerPageShouldDisplay = false;
			pages.loginPageShouldDisplay = false;
			pages.incomeWindowShouldDisplay = false;
			pages.expensesWindowShouldDisplay = false;
		}
	}
}

void login::textBoxHandler()
{
	//username textbox
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

	//password textbox
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

bool login::loginHandler()
{
	bool check = false;
	std::string fileLine = createFileLine(username, password);
	std::fstream loginFile;
	loginFile.open("../files/login.txt", std::ios::in | std::ios::out);
	if (checkIfInFile(loginFile, fileLine))
		check = true;
	loginFile.close();
	return check;
}