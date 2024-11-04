#include "../lib/precompile.h"
#include "../lib/loginPage.h"

void Login::loginPageTextures() {
	Logo = LoadTexture("assets/cfGlobe.png");
	font = LoadFont("assets/LuxuriousRoman-Regular.ttf");
	loginBtn = LoadTexture("assets/loginBtn.png");
}

void Login::displayLoginPage()
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
	if (Reg.firstName.size() > 0)
	{
		DrawTextEx(font, Reg.firstName.c_str(), { 582, 287 }, 25, 0.7, MG);
	}
	else DrawTextEx(font, "First Name", { 582, 287 }, 25, 0.7, background);

	//Draw surname text box
	DrawRectangleLinesEx(passwordText, 0.7, MG);
	if (Reg.lastName.size() > 0)
	{
		DrawTextEx(font, Reg.lastName.c_str(), { 582, 387 }, 25, 0.7, MG);
	}
	else DrawTextEx(font, "Surname", { 582, 387 }, 25, 0.7, background);

	//Draw password text box
	DrawRectangleLinesEx(emailText, 0.7, MG);
	if (Reg.password.size() > 0)
	{
		DrawTextEx(font, Reg.password.c_str(), { 582, 487 }, 25, 0.7, MG);
	}
	else DrawTextEx(font, "Password", { 582, 487 }, 25, 0.7, background);

	//Draw login button
	DrawTextureEx(loginBtn, { 535, 600 }, 0, 1, WHITE);
	DrawRectangleLinesEx(loginWindow, 0.7, MG);
}



void Login::textBoxHandler()
{
	//username textbox
	if (CheckCollisionPointRec(GetMousePosition(), usernameTextHitbox))
	{
		SetMouseCursor(MOUSE_CURSOR_IBEAM);
		int key = GetCharPressed();
		if ((key >= 32) && (key <= 125) && (Reg.firstName.size() < 14))
		{
			Reg.firstName.push_back((char)key);
		}
		if (IsKeyPressed(KEY_BACKSPACE))
		{
			if (Reg.firstName.size() > 0)
				Reg.firstName.pop_back();
		}
		return;

	}

	//password textbox
	if (CheckCollisionPointRec(GetMousePosition(), passwordTextHitbox))
	{
		SetMouseCursor(MOUSE_CURSOR_IBEAM);
		int key = GetCharPressed();
		if ((key >= 32) && (key <= 125) && (Reg.lastName.size() < 14))
		{
			Reg.lastName.push_back((char)key);
		}
		if (IsKeyPressed(KEY_BACKSPACE))
		{
			if (Reg.lastName.size() > 0)
				Reg.lastName.pop_back();
		}
		return;
	}

	if (CheckCollisionPointRec(GetMousePosition(), emailTextHitbox))
	{
		SetMouseCursor(MOUSE_CURSOR_IBEAM);
		int key = GetCharPressed();
		if ((key >= 32) && (key <= 125) && (Reg.password.size() < 16))
		{
			Reg.password.push_back((char)key);
		}
		if (IsKeyPressed(KEY_BACKSPACE))
		{
			if (Reg.password.size() > 0)
				Reg.password.pop_back();
		}
		return;
	}
	SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}

void Login::buttonHandler(PageBools& pages)
{
	if (CheckCollisionPointRec(GetMousePosition(), loginButton)) 
	{
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		if (!checkPassword(Reg.password)) {
			DrawTextEx(font, "Password incompatible", { 582, 530 }, 25, 0.7, MG);
		}
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			if (loginHandler()) {
				loginSuccess = true;
				pages.mainPageShouldDisplay = true;
				pages.registerPageShouldDisplay = false;
				pages.loginPageShouldDisplay = false;
				pages.incomeWindowShouldDisplay = false;
				pages.expensesWindowShouldDisplay = false;
				
			}
		}
	}

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

bool Login::loginHandler() {
	std::string fileLine = createLoginFileLine(Reg.firstName, Reg.lastName, Reg.password);
	std::fstream loginFile("../files/login.txt");

	// Ensure the file is open before proceeding
	if (!loginFile.is_open()) {
		std::cerr << "Error: Could not open login file." << std::endl;
		return false;
	}

	std::cout << "Trying to match lines in login.txt" << fileLine << std::endl;

	// Return the result of checkIfInFile directly
	return checkIfInFile(loginFile, fileLine);
}