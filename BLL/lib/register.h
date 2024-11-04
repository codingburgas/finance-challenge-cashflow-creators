#pragma once
#include "precompileBLL.h"

bool checkPassword(std::string password);

bool checkValidity(const std::string& firstName, const std::string& registerPassword, const std::string& lastName);

bool checkFirstName(const std::string& firstName);

bool checkLastName(const std::string& lastName);

std::string createFileLine(std::string& loginFirstName, std::string loginlastName, std::string& loginPassword);