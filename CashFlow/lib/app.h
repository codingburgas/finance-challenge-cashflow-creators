#pragma once
#include "precompile.h"
#include "pageHandle.h"
#include "mainPage.h"
#include "loginPage.h"
#include "registerPage.h"

class displayRes {
public:
    int width = 1440; //GetScreenWidth();
    int height = 900; //GetScreenHeight();
};

class app {
public:
    app();
    void display();
    void update();
    void pageHandler();

    char username[15] = "\0";
    int userCharCount = 0;
    char password[15] = "\0";
    int passCharCount = 0;
    displayRes screen;
    pageBools pageBools;
    mainMenu mainMenu;
    login login;
    reg reg;
};