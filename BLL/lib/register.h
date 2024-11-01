#pragma once
#include "precompileBLL.h"

bool checkPassword(std::string password);

bool checkValidity(std::string registerUsername, std::string registerPassword);

bool checkUsername(std::string username);

std::string createFileLine(std::string& loginUsername, std::string& loginPassword);