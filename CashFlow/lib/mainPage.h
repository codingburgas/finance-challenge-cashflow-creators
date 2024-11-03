#pragma once
#include "precompile.h"
#include "pageHandle.h"
#include "balance.h"

class mainMenu {
public:
    void mainMenuTextures();
    void displayMainMenu();
    void buttonHandler(pageBools& pages);
    void displayIncomeWindow();
    void displayExpensesWindow();
    void textBoxHandler(pageBools& pages);

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

    std::string income;
    std::string expenses;
    std::string entIncome;
    std::string entExpense;
    std::string date;
    std::string balance;
    float enteredIncome;
    float enteredExpense;
    float totalIncome = 0;
    float totalExpense = 0;
    float tBalance;

    Rectangle incomeWindow = { 130, 210, 400, 550 };
    Rectangle expensesWindow = { 130, 210, 400, 550 };
    Rectangle incomeAndExpenseHB = { 195, 465, 270, 20 };
    Rectangle dateHB = { 195, 545, 270, 20 };

    Texture2D plusSign;
    Texture2D backArrowSign;
    Texture2D closeWinSign;

};