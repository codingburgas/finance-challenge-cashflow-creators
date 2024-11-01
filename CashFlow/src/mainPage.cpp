#include "../lib/precompile.h"
#include "../lib/mainPage.h"
#include "../lib/pageHandle.h"

void mainMenu::mainMenuTextures() {
    Logo = LoadTexture("assets/CFlogo-removebg-preview.png");
    font = LoadFont("assets/LuxuriousRoman-Regular.ttf");
    plusSign = LoadTexture("assets/plusSign.png");
    backArrowSign = LoadTexture("assets/backArrowSign.png");
    closeWinSign = LoadTexture("assets/closeWinSign.png");
}

void mainMenu::displayMainMenu() {
    //TaskBar
    DrawTextureEx(Logo, logoPos, 0, 0.35, WHITE);
    DrawRectangle(0, 0, 680, 40, MG);
    DrawRectangle(680, 0, 850, 75, MG);
    DrawRing(ringCenter, 20, -8.5, 180, 0, 300, BLACK);
    DrawTextEx(font, "Log In", { 1330, 23 }, 32, 0.7, BLACK);

    //Income and Expenses Window
    DrawRectangleLinesEx (IandEwindow, 0.7, MG);

    DrawTextEx(font, "Monthly\n Income: ", { 820, 240 }, 35, 0.7, MG);
    DrawTextEx(font, " Monthly \nExpenses:", { 1120, 240 }, 35, 0.7, MG);

    DrawRing({ 880, 500 }, 120, 123, 0, 360, 360, MG);
    DrawRing({ 1180, 500 }, 120, 123, 0, 360, 360, MG);
    DrawTextEx(font, income.c_str(), { 845, 480 }, 32, 0.7, MG);
    DrawTextEx(font, expenses.c_str(), { 1145, 480 }, 32, 0.7, MG);

    //Add income and expense button
    DrawTextureEx(plusSign, { 1230, 640 }, 0, 0.25, WHITE);
}

void mainMenu::displayIncomeWindow() {
    DrawRectangleLinesEx(incomeWindow, 0.7, MG);
    DrawTextEx(font, "Add Income", { 325, 230 }, 35, 0.7, MG);
    DrawTextEx(font, "Add Expense", { 360, 720 }, 20, 0.7, MG);
    DrawTextEx(font, "Track your monthly income\n          with CashFlow!", { 228, 320 }, 32, 0.7, MG);

    DrawTextureEx(closeWinSign, { 505, 220 }, 0, 0.2, WHITE);

    DrawRectangleLinesEx({ 250, 450, 300, 50 }, 0.7, MG);
    if (enterIncome.size() > 0)
    {
        DrawTextEx(font, enterIncome.c_str(), { 262, 462 }, 25, 0.7, MG);
    }
    else DrawTextEx(font, "Enter Income", { 262, 462 }, 25, 0.7, Gold2);
}


void mainMenu::displayExpensesWindow() {
    DrawRectangleLinesEx(expensesWindow, 0.7, MG);
    DrawTextEx(font, "Add Expenses", { 310, 230 }, 35, 0.7, MG);
    DrawTextEx(font, "Track your monthly expenses\n           with CashFlow!", { 218, 320 }, 32, 0.7, MG);

    DrawTextureEx(backArrowSign, { 500, 670 }, 0, 0.2, WHITE);
    DrawTextureEx(closeWinSign, { 505, 220 }, 0, 0.2, WHITE);

    DrawRectangleLinesEx({ 250, 450, 300, 50 }, 0.7, MG);
    if (enterIncome.size() > 0)
    {
        DrawTextEx(font, enterIncome.c_str(), { 262, 462 }, 25, 0.7, MG);
    }
    else DrawTextEx(font, "Enter Expense", { 262, 462 }, 25, 0.7, Gold2);
}

void mainMenu::textBoxHandler() {
    if (CheckCollisionPointRec(GetMousePosition(), incomeAndExpenseHB))
    {
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
        int key = GetCharPressed();
        if ((key >= 32) && (key <= 125) && (enterIncome.size() < 14))
        {
            enterIncome.push_back((char)key);
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            if (enterIncome.size() > 0)
                enterIncome.pop_back();
        }
        return;
    }
    else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}

void mainMenu::buttonHandler(pageBools& pages)
{
    //income and expenses window button
    if (CheckCollisionPointRec(GetMousePosition(), { 1260, 670, 65, 65 }))
    {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            pages.mainPageShouldDisplay = false;
            pages.registerPageShouldDisplay = false;
            pages.loginPageShouldDisplay = false;
            pages.incomeWindowShouldDisplay = true;
            pages.expensesWindowShouldDisplay = false;
        }
    }
    else

    //expenses window button
    if (CheckCollisionPointRec(GetMousePosition(), { 360, 720, 100, 20 }))
    {
        if (pages.expensesWindowShouldDisplay == false) {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                pages.mainPageShouldDisplay = false;
                pages.registerPageShouldDisplay = false;
                pages.loginPageShouldDisplay = false;
                pages.incomeWindowShouldDisplay = false;
                pages.expensesWindowShouldDisplay = true;
            }
        }
    }
    else
                
    //income window button
    if (CheckCollisionPointRec(GetMousePosition(), { 520, 700, 55, 40 }))
    {
        if (pages.incomeWindowShouldDisplay == false) {
             SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
             if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                 pages.mainPageShouldDisplay = false;
                 pages.registerPageShouldDisplay = false;
                 pages.loginPageShouldDisplay = false;
                 pages.incomeWindowShouldDisplay = true;
                 pages.expensesWindowShouldDisplay = false;
             }
        }
            }
    else

    //close window button
    if (CheckCollisionPointRec(GetMousePosition(), { 545, 225, 30, 30 }))
    {
        if (pages.mainPageShouldDisplay == false) {
             SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
             if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                 pages.mainPageShouldDisplay = true;
                 pages.registerPageShouldDisplay = false;
                 pages.loginPageShouldDisplay = false;
                 pages.incomeWindowShouldDisplay = false;
                 pages.expensesWindowShouldDisplay = false;
             }
        }
            }
    else

    //login button
    if (CheckCollisionPointRec(GetMousePosition(), loginNowButton))
    {
         SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
         if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
             pages.mainPageShouldDisplay = false;
             pages.registerPageShouldDisplay = false;
             pages.loginPageShouldDisplay = true;
             pages.incomeWindowShouldDisplay = false;
             pages.expensesWindowShouldDisplay = false;
         }
    }
    else

         {
             SetMouseCursor(MOUSE_CURSOR_DEFAULT);
         }
}