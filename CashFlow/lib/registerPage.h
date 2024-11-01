#pragma once
#include "precompile.h"
#include "pageHandle.h"

class reg {
public:
	void displayRegisterPage();
	void buttonHandler(pageBools& pages);

	void textBoxHandler();
	std::string firstName = "Sam";
	std::string lastName = "Davidson";
	std::string email = "samD@gmail.com";
	std::string phoneNum = "0812356781";
	float borderThickness = 2;
	Font customFont = GetFontDefault();
	Color borderColor = BLACK;
	Rectangle usernameText = { 820, 415, 280, 45 };
	Rectangle usernameTextHitbox = { 820, 395, 280, 45 };
	Rectangle backButton = { 1700, 50, 70, 70 };
	Rectangle passwordText = { 820, 515, 280, 45 };
	Rectangle passwordTextHitbox = { 820, 495, 280, 45 };
	Rectangle registerButton = { 820, 660, 280, 90 };
	Rectangle Border = { 670, 215, 580, 600 };
};