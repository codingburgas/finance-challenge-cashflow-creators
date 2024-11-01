#include "../lib/precompile.h"
#include "../lib/mainPage.h"
#include "../lib/pageHandle.h"

void mainMenu::mainMenuTextures() {
    Logo = LoadTexture("assets/CFlogo-removebg-preview.png");
    font = LoadFont("assets/LuxuriousRoman-Regular.ttf");
}

void mainMenu::displayMainMenu() {
    //TaskBar
    DrawTextureEx(Logo, logoPos, 0, 0.35, WHITE);
    DrawLine(0, 40, 650, 40, MG);
    DrawRectangle(0, 0, 650, 40, MG);
    DrawRectangle(650, 0, 850, 75, MG);
    DrawRing(ringCenter, 20, -8.5, 180, 0, 300, BLACK);

    //Income and Expenses Window
    DrawRectangleLinesEx (IandEwindow, 0.7, MG);

    DrawTextEx(font, "Income:", { 820, 240 }, 35, 0.7, MG);
    DrawTextEx(font, "Expenses:", { 1120, 240 }, 35, 0.7, MG);

    DrawRing({ 880, 500 }, 120, 123, 0, 360, 360, MG);
    DrawRing({ 1180, 500 }, 120, 123, 0, 360, 360, MG);
}

void mainMenu::buttonHandler(pageBools& pages)
{
    //register button
    if (CheckCollisionPointRec(GetMousePosition(), IandEwindow))
    {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            pages.mainPageShouldDisplay = false;
            pages.registerPageShouldDisplay = true;
            pages.loginPageShouldDisplay = false;
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
            }
        }
        else
        {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        }
}
