#pragma once
#include "precompile.h"
#include "pageHandle.h"
#include "files.h"
#include "login.h"
#include "register.h"

class Login {
public:
	void displayLoginPage();
	void textBoxHandler();
	void buttonHandler(PageBools& pages);
	bool loginHandler();
	void loginPageTextures();
	std::string logFirstName = "";
	std::string logLastName = "";
	std::string logPassword = "";
	bool loginSuccess = false;

private:
	Texture2D Logo;
	Texture2D loginBtn;
	Vector2 logoPos = { 590, 10 };
	Vector2 ringCenter = { 730, 60 };
	Color background = { 172, 173, 188, 255 };
	Color MG = { 212, 175, 55, 255 };
	Color Gold2 = { 197, 179, 88, 100 };
	Font font;
	Rectangle taskbar = { 0, 0, 1440, 70 };


	Rectangle usernameText = { 570, 275, 300, 50 };
	Rectangle usernameTextHitbox = { 582, 287, 280, 30 };
	Rectangle passwordText = { 570, 375, 300, 50 };
	Rectangle passwordTextHitbox = { 582, 387, 280, 30 };
	Rectangle emailText = { 570, 475, 300, 50 };
	Rectangle emailTextHitbox = { 582, 487, 280, 30 };
	Rectangle loginButton = { 620, 670, 195, 80 };
	Rectangle homeButton = { 1330, 23, 70, 30 };
	Rectangle registerButton = { 790, 800, 140, 20 };

	Rectangle loginWindow = { 420, 180, 600, 670 };
	Color customBrown = { 92, 83, 70, 255 };
};