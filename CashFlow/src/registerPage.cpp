#include "../lib/precompile.h"
#include "../lib/pageHandle.h"
#include "../lib/registerPage.h"

void Reg::registerPageTextures() {
	Logo = LoadTexture("assets/cfGlobe.png");
	font = LoadFont("assets/LuxuriousRoman-Regular.ttf");
	regButton = LoadTexture("assets/register.png");
}

void Reg::displayRegisterPage()
{
	//TaskBar
	DrawRectangle(0, 0, 730, 40, MG);
	DrawRectangle(730, 0, 900, 75, MG);
	DrawRing(ringCenter, 20, -8.5, 180, 0, 300, customBrown);
	DrawTextureEx(Logo, logoPos, 0, 0.4, WHITE);
	DrawTextEx(font, "CashFlow Banking", { 1000, 23 }, 32, 0.7, BLACK);



	//Draw register window
	DrawRectangleRec(regWindow, BLACK);
	DrawTextEx(font, "Register to CashFlow!", { 556, 200 }, 40, 0.7, MG);
	DrawTextEx(font, "Already have an account?", { 530, 800 }, 24, 0.7, background);
	DrawTextEx(font, "Log In Here!", { 800, 800 }, 24, 0.7, MG);

	//Draw first name text box
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
	if (password.size() > 0)
	{
		DrawTextEx(font, password.c_str(), { 582, 487 }, 25, 0.7, MG);
	}
	else DrawTextEx(font, "Password", { 582, 487 }, 25, 0.7, background);

	//Draw register button
	DrawTextureEx(regButton, { 535, 600 }, 0, 0.62, WHITE);
	DrawRectangleLinesEx(regWindow, 0.7, MG);
}

void Reg::buttonHandler(PageBools& pages)
{
	//register button
	if (CheckCollisionPointRec(GetMousePosition(), registerButton))
	{
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);

		if (!checkPassword(password)) {
			DrawTextEx(font, "Password incompatable", { 582, 530 }, 25, 0.7, MG);
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (registerHandler() && checkValidity(firstName, password, lastName))
			{
				pages.mainPageShouldDisplay = true;
				pages.registerPageShouldDisplay = false;
				pages.loginPageShouldDisplay = false;
				pages.incomeWindowShouldDisplay = false;
				pages.expensesWindowShouldDisplay = false;
			}
		}
		return;
	}
	else
	if (CheckCollisionPointRec(GetMousePosition(), loginButton))
	{
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			pages.mainPageShouldDisplay = false;
			pages.registerPageShouldDisplay = false;
			pages.loginPageShouldDisplay = true;
			pages.incomeWindowShouldDisplay = false;
			pages.expensesWindowShouldDisplay = false;
		}
		return;
	}
	else
	//back button
	if (CheckCollisionPointRec(GetMousePosition(), homeButton))
	{
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			pages.mainPageShouldDisplay = true;
			pages.registerPageShouldDisplay = false;
			pages.loginPageShouldDisplay = false;
			pages.incomeWindowShouldDisplay = false;
			pages.expensesWindowShouldDisplay = false;
		}
		return;
	}
}

void Reg::textBoxHandler()
{
	if (CheckCollisionPointRec(GetMousePosition(), firstNameTextHitbox))
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

	if (CheckCollisionPointRec(GetMousePosition(), lastNameTextHitbox))
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

	if (CheckCollisionPointRec(GetMousePosition(), passwordTextHitbox))
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

bool Reg::registerHandler()
{
	bool check = false;
	bool checkValid = false;
	std::fstream loginFile;
	loginFile.open("../files/login.txt", std::ios::in | std::ios::out);
	if (!loginFile)
		std::cout << "login.txt failed to load!";
	else
	{
		std::string fileLine = createFileLine(firstName, lastName, password);
		check = checkIfInFileLine(loginFile, firstName, lastName);
		checkValid = checkValidity(firstName, password, lastName);
		loginFile.close();
		loginFile.open("../files/login.txt", std::ios::in | std::ios::out | std::ios::app);
		if (!check && checkValid) {
			writeInFile(loginFile, fileLine);
			return !check;
		}
		loginFile.close();
	}
	return check;
}