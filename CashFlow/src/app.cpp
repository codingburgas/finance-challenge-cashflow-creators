#include "app.h"

App::App()
{
    //Initialize main app screen
    InitWindow(screen.width, screen.height, "app");
    SetTargetFPS(30);

    update();

}

void App::update()
{
    textures();

    while (!WindowShouldClose())
    {
        display();
    }

    CloseWindow();

}

void App::display()
{
    BeginDrawing();

    //Set background color
    ClearBackground(customBrown);

    pageHandler();

    EndDrawing();
}

void App::pageHandler()
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
        reg.textBoxHandler();
        return;
    }

    if (pageBools.loginPageShouldDisplay)
    {
        login.displayLoginPage();
        login.textBoxHandler();
        login.buttonHandler(pageBools);
        return;
    }

    if (pageBools.incomeWindowShouldDisplay)
    {
        mainMenu.displayMainMenu();
        mainMenu.displayIncomeWindow();
        mainMenu.buttonHandler(pageBools);
        mainMenu.textBoxHandler(pageBools);
        return;
    }

    if (pageBools.expensesWindowShouldDisplay)
    {
        mainMenu.displayMainMenu();
        mainMenu.displayExpensesWindow();
        mainMenu.buttonHandler(pageBools);
        mainMenu.textBoxHandler(pageBools);
        return;
    }

}

void App::textures() {
    mainMenu.mainMenuTextures();
    reg.registerPageTextures();
    login.loginPageTextures();
}