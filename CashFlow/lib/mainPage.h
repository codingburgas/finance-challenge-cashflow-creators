#pragma once
#include "precompile.h"
#include "pageHandle.h"

class mainMenu {
public:
    void mainMenuTextures();
    void displayMainMenu();
    void buttonHandler(pageBools& pages);
    void displayIncomeWindow();
    void displayExpensesWindow();
    void textBoxHandler();

private:
    Texture2D Logo;
    Vector2 logoPos = { 590, 10 };
    Vector2 ringCenter = { 730, 60 };
    Color background = { 113, 121, 126, 255 };
    Color MG = { 212, 175, 55, 255 };
    Color Gold2 = { 197, 179, 88, 100 };
    Color customBrown = { 92, 83, 70, 255 };
    Font font;

    Rectangle taskbar = { 0, 0, 1440, 70 };
    Rectangle loginNowButton = { 1330, 23, 80, 30 };
    Rectangle IandEwindow = { 700, 210, 650, 550 };
    std::string income = "895.32";
    std::string expenses = "683.67";

    Rectangle incomeWindow = { 200, 210, 400, 550 };
    Rectangle expensesWindow = { 200, 210, 400, 550 };

    std::string enterIncome;
    std::string enterExpense;
    Rectangle incomeAndExpenseHB = { 265, 465, 270, 20 };

    Texture2D plusSign;
    Texture2D backArrowSign;
    Texture2D closeWinSign;

};