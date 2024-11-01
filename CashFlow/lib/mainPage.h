#pragma once
#include "precompile.h"
#include "pageHandle.h"

class mainMenu {
public:
    void mainMenuTextures();
    void displayMainMenu();
    void buttonHandler(pageBools& pages);
    Texture2D Logo;
    Vector2 logoPos = { 480, 18 };
    Vector2 ringCenter = { 650, 60 };
private:
    Color background = { 113, 121, 126, 255 };
    Color MG = { 212, 175, 55, 255 };

    Font font;

    Rectangle taskbar = { 0, 0, 1440, 70 };

    Rectangle IandEwindow = { 700, 210, 650, 550 };
    Rectangle loginNowButton = { 820, 490, 280, 70 };

};