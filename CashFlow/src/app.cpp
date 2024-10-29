#include "app.h"

app::app()
{
    //Initialize main app screen
    InitWindow(screen.width, screen.height, "app");
    SetTargetFPS(30);

    update();
}

void app::update()
{
    while (!WindowShouldClose())
    {
        display();
    }
    CloseWindow();
}

void app::display()
{
    BeginDrawing();

    //Set background color
    ClearBackground(GRAY);

    pageHandler();

    EndDrawing();
}

void app::pageHandler()
{
    if (pageBools.mainPageShouldDisplay)
    {
        mainMenu.displayMainMenu();
        mainMenu.buttonHandler(pageBools);
        return;
    }

    if (pageBools.registerPageShouldDisplay)
    {
        reg.displayRegisterPage();
        reg.buttonHandler(pageBools);
        return;
    }

    if (pageBools.loginPageShouldDisplay)
    {
        login.displayLoginPage();
        login.buttonHandler(pageBools);
        return;
    }
}