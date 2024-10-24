#include "../lib/precompile.h"
#include "../lib/mainPage.h"
#include "../lib/pageHandle.h"

void mainMenu::displayMainMenu() {
    DrawRectangle(220, 250, 1000, 400, RAYWHITE);

    DrawRectangle ( 320, 490, 280, 70, BLACK);
    DrawRectangle ( 820, 490, 280, 70, BLACK);
}

void mainMenu::buttonHandler(pageBools& pages)
{
    //register button
    if (CheckCollisionPointRec(GetMousePosition(), registerNowButton))
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
