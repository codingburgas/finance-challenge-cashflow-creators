#pragma once
#include "precompile.h"
#include "pageHandle.h"

class mainMenu {
public:
    void displayMainMenu();
    void buttonHandler(pageBools& pages);
private:
    Rectangle registerNowButton = { 320, 490, 280, 70 };
    Rectangle loginNowButton = { 820, 490, 280, 70 };
};