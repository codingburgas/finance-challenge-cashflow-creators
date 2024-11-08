#pragma once
#include "precompile.h"
#include "pageHandle.h"
#include "register.h"
#include "files.h"

class Reg {
public:


	void displayRegisterPage();
	void buttonHandler(PageBools& pages);
	void textBoxHandler();
	bool registerHandler();
	void registerPageTextures();
	std::string firstName;
	std::string lastName;
	std::string password;

private:
	
	Texture2D Logo;
	Texture2D regButton;
	Vector2 logoPos = { 590, 10 };
	Vector2 ringCenter = { 730, 60 };
	Color background = { 172, 173, 188, 255 };
	Color MG = { 212, 175, 55, 255 };
	Color Gold2 = { 197, 179, 88, 100 };
	Font font;
	Rectangle taskbar = { 0, 0, 1440, 70 };


	Rectangle usernameText = { 570, 275, 300, 50 };
	Rectangle firstNameTextHitbox = { 582, 287, 280, 30 };
	Rectangle passwordText = { 570, 375, 300, 50 };
	Rectangle lastNameTextHitbox = { 582, 387, 280, 30 };
	Rectangle emailText = { 570, 475, 300, 50 };
	Rectangle passwordTextHitbox = { 582, 487, 280, 30 };
	Rectangle registerButton = { 620, 670, 195, 80 };
	Rectangle homeButton = { 1330, 23, 70, 30 };
	Rectangle loginButton = { 800, 800, 120, 20 };

	Rectangle regWindow = { 420, 180, 600, 670 };
	Color customBrown = { 92, 83, 70, 255 };

	float hitBoxX = 580;
};