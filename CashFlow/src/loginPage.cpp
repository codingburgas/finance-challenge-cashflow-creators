#include "../lib/precompile.h"
#include "../lib/loginPage.h"

void login::loginPageTextures() {
	Logo = LoadTexture("assets/cfGlobe.png");
	font = LoadFont("assets/LuxuriousRoman-Regular.ttf");
	loginBtn = LoadTexture("assets/loginBtn.png");
}

void login::displayLoginPage()
{
	//TaskBar
	DrawRectangle(0, 0, 730, 40, MG);
	DrawRectangle(730, 0, 900, 75, MG);
	DrawRing(ringCenter, 20, -8.5, 180, 0, 300, customBrown);
	DrawTextureEx(Logo, logoPos, 0, 0.4, WHITE);
	DrawTextEx(font, "CashFlow Banking", { 1000, 23 }, 32, 0.7, BLACK);

	//Draw register window
	DrawRectangleRec(loginWindow, BLACK);
	DrawTextEx(font, "Log into CashFlow!", { 575, 200 }, 40, 0.7, MG);
	DrawTextEx(font, "Don't have an account?", { 540, 800 }, 24, 0.7, background);
	DrawTextEx(font, "Register Here!", { 790, 800 }, 24, 0.7, MG);

	//Draw username text box
	DrawRectangleLinesEx(usernameText, 0.7, MG);
	if (firstName.size() > 0)
	{
		DrawTextEx(font, firstName.c_str(), { 582, 287 }, 25, 0.7, MG);
	}
	else DrawTextEx(font, "First Name", { 582, 287 }, 25, 0.7, background);

	//Draw surname text box
	DrawRectangleLinesEx(passwordText, 0.7, MG);
	if (lastName.size() > 0)
	{
		DrawTextEx(font, lastName.c_str(), { 582, 387 }, 25, 0.7, MG);
	}
	else DrawTextEx(font, "Surname", { 582, 387 }, 25, 0.7, background);

	//Draw email text box
	DrawRectangleLinesEx(emailText, 0.7, MG);
	if (email.size() > 0)
	{
		DrawTextEx(font, email.c_str(), { 582, 487 }, 25, 0.7, MG);
	}
	else DrawTextEx(font, "Email", { 582, 487 }, 25, 0.7, background);

	//Draw login button
	DrawTextureEx(loginBtn, { 535, 600 }, 0, 1, WHITE);
	DrawRectangleLinesEx(loginWindow, 0.7, MG);

}

void login::buttonHandler(pageBools& pages)
{
	if (CheckCollisionPointRec(GetMousePosition(), loginButton))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			
		if (!checkPassword(password)) {
			DrawTextEx(font, "Password incompatable", { 582, 530 }, 25, 0.7, MG);
		}

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
	else
	if (CheckCollisionPointRec(GetMousePosition(), registerButton))
	{
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			pages.mainPageShouldDisplay = false;
			pages.registerPageShouldDisplay = true;
			pages.loginPageShouldDisplay = false;
			pages.incomeWindowShouldDisplay = false;
			pages.expensesWindowShouldDisplay = false;
		}
		return;
	}
	else
	if (CheckCollisionPointRec(GetMousePosition(), homeButton))
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

	//password textbox
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

	if (CheckCollisionPointRec(GetMousePosition(), emailTextHitbox))
	{
		SetMouseCursor(MOUSE_CURSOR_IBEAM);
		int key = GetCharPressed();
		if ((key >= 32) && (key <= 125) && (password.size() < 16))
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
	std::string fileLine = createFileLine(firstName, lastName, password);
	std::fstream loginFile;
	loginFile.open("../files/login.txt", std::ios::in | std::ios::out);
	if (checkIfInFile(loginFile, fileLine))
		check = true;
	loginFile.close();
	return check;
}