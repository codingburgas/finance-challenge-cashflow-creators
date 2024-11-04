#pragma once
#include "precompile.h"
#include "pageHandle.h"
#include "balance.h"
#include "registerPage.h"
#include "loginPage.h"

class MainMenu {
public:
    void mainMenuTextures();
    void displayMainMenu();
    void buttonHandler(PageBools& pages);
    void displayIncomeWindow();
    void displayExpensesWindow();
    void textBoxHandler(PageBools& pages);
    void DrawCenteredText(std::string& text, Vector2 centerPoint, int fontSize, Color color, Font font);
    std::string income = "0";
    std::string expenses = "0";
    std::string balance = "0.00";
    float totalIncome = 0;
    float totalExpense = 0;
    float tBalance = 0;

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
    Rectangle loginNowButton = { 1340, 25, 60, 25 };
    Rectangle IandEwindow = { 660, 210, 650, 550 };

    std::string entIncome;
    std::string entExpense;
    std::string date = "";
    float enteredIncome;
    float enteredExpense;

    Rectangle incomeWindow = { 130, 210, 400, 550 };
    Rectangle expensesWindow = { 130, 210, 400, 550 };
    Rectangle incomeAndExpenseHB = { 195, 465, 270, 20 };
    Rectangle dateHB = { 195, 545, 270, 20 };

    Texture2D plusSign;
    Texture2D backArrowSign;
    Texture2D closeWinSign;

    Reg reg;
    Login login;
};