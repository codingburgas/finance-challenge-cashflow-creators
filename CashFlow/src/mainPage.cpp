#include "../lib/precompile.h"
#include "../lib/mainPage.h"
#include "../lib/pageHandle.h"

void mainMenu::mainMenuTextures() {
    Logo = LoadTexture("assets/cfGlobe.png");
    font = LoadFont("assets/LuxuriousRoman-Regular.ttf");
    plusSign = LoadTexture("assets/plusSign.png");
    backArrowSign = LoadTexture("assets/backArrowSign.png");
    closeWinSign = LoadTexture("assets/closeWinSign.png");
}

void mainMenu::displayMainMenu() {
    DrawTextEx(font, "     Welcome to\nCashFlow Banking!", { 160, 380 }, 48, 0.7, MG);

    //TaskBar
    DrawRectangle(0, 0, 730, 40, MG);
    DrawRectangle(730, 0, 900, 75, MG);
    DrawRing(ringCenter, 20, -8.5, 180, 0, 300, customBrown);
    DrawTextureEx(Logo, logoPos, 0, 0.4, WHITE);
    DrawTextEx(font, "Log In", { 1340, 25 }, 25, 0.7, BLACK);
    DrawTextEx(font, "CashFlow Banking", { 1000, 23 }, 32, 0.7, BLACK);

    //Income and Expenses Window
    DrawRectangleRec(IandEwindow, BLACK);
    DrawRectangleLinesEx (IandEwindow, 0.7, MG);

    DrawTextEx(font, "Monthly\n Income: ", { 780, 240 }, 35, 0.7, MG);
    DrawTextEx(font, " Monthly \nExpenses:", { 1080, 240 }, 35, 0.7, MG);

    DrawRing({ 840, 500 }, 120, 123, 0, 360, 360, MG);
    DrawRing({ 1140, 500 }, 120, 123, 0, 360, 360, MG);
    DrawTextEx(font, income.c_str(), { 805, 480 }, 32, 0.7, MG);
    DrawTextEx(font, expenses.c_str(), { 1105, 480 }, 32, 0.7, MG);

    //Add income and expense button
    DrawTextureEx(plusSign, { 1190, 640 }, 0, 0.25, WHITE);
}

void mainMenu::displayIncomeWindow() {
    DrawRectangleRec(incomeWindow, BLACK);
    DrawRectangleLinesEx(incomeWindow, 0.7, MG);
    DrawTextEx(font, "Add Income", { 245, 230 }, 35, 0.7, MG);
    DrawTextEx(font, "Add Expense", { 290, 720 }, 20, 0.7, MG);
    DrawTextEx(font, "Track your monthly income\n          with CashFlow!", { 158, 320 }, 32, 0.7, MG);

    DrawTextureEx(closeWinSign, { 435, 220 }, 0, 0.2, WHITE);

    //Income text box
    DrawRectangleLinesEx({ 180, 450, 300, 50 }, 0.7, MG);
    if (enterIncome.size() > 0)
    {
        DrawTextEx(font, enterIncome.c_str(), { 192, 462 }, 25, 0.7, MG);
    }
    else DrawTextEx(font, "Enter Income", { 192, 462 }, 25, 0.7, background);

    //Date text box
    DrawRectangleLinesEx({ 180, 530, 300, 50 }, 0.7, MG);
    if (date.size() > 0)
    {
        DrawTextEx(font, date.c_str(), { 192, 542 }, 25, 0.7, MG);
    }
    else DrawTextEx(font, "Enter Date (DD/MM/YYYY)", { 192, 542 }, 25, 0.7, background);
}


void mainMenu::displayExpensesWindow() {
    DrawRectangleRec(expensesWindow, BLACK);
    DrawRectangleLinesEx(expensesWindow, 0.7, MG);
    DrawTextEx(font, "Add Expenses", { 240, 230 }, 35, 0.7, MG);
    DrawTextEx(font, "Track your monthly expenses\n           with CashFlow!", { 148, 320 }, 32, 0.7, MG);

    DrawTextureEx(backArrowSign, { 430, 670 }, 0, 0.2, WHITE);
    DrawTextureEx(closeWinSign, { 435, 220 }, 0, 0.2, WHITE);

    //Expense text box
    DrawRectangleLinesEx({ 180, 450, 300, 50 }, 0.7, MG);
    if (enterIncome.size() > 0)
    {
        DrawTextEx(font, enterIncome.c_str(), { 192, 462 }, 25, 0.7, MG);
    }
    else DrawTextEx(font, "Enter Expense", { 192, 462 }, 25, 0.7, background);

    //Date text box
    DrawRectangleLinesEx({ 180, 530, 300, 50 }, 0.7, MG);
    if (date.size() > 0)
    {
        DrawTextEx(font, date.c_str(), { 192, 542 }, 25, 0.7, MG);
    }
    else DrawTextEx(font, "Enter Date (DD/MM/YYYY)", { 192, 542 }, 25, 0.7, background);
}

void mainMenu::textBoxHandler() {
    if (CheckCollisionPointRec(GetMousePosition(), incomeAndExpenseHB))
    {
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
        int key = GetCharPressed();
        if ((key >= 45) && (key <= 57) && (enterIncome.size() < 14))
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

    if (CheckCollisionPointRec(GetMousePosition(), dateHB))
    {
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
        int key = GetCharPressed();
        if ((key >= 47) && (key <= 57) && (date.size() < 10))
        {
            date.push_back((char)key);
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            if (date.size() > 0)
                date.pop_back();
        }
        return;
    }
    else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}

void mainMenu::buttonHandler(pageBools& pages)
{
    //income and expenses window button
    if (CheckCollisionPointRec(GetMousePosition(), { 1220, 670, 65, 65 }))
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

        //expenses window button
    if (CheckCollisionPointRec(GetMousePosition(), { 290, 720, 100, 20 }))
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
                
    //income window button
        if (CheckCollisionPointRec(GetMousePosition(), { 450, 700, 55, 40 }))
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

    //close window button
        if (CheckCollisionPointRec(GetMousePosition(), { 475, 225, 30, 30 }))
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

    //login button
        if (CheckCollisionPointRec(GetMousePosition(), loginNowButton))
        {
             SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
             if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                 pages.mainPageShouldDisplay = false;
                 pages.registerPageShouldDisplay = true;
                 pages.loginPageShouldDisplay = false;
                 pages.incomeWindowShouldDisplay = false;
                 pages.expensesWindowShouldDisplay = false;
             }
        }
    else

         {
             SetMouseCursor(MOUSE_CURSOR_DEFAULT);
         }
}