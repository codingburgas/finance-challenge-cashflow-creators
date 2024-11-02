#pragma once
#include "precompileBLL.h"

bool checkPassword(std::string password);

bool checkValidity(std::string firstName, std::string registerPassword, std::string lastName);

bool checkFirstName(std::string firstName);

bool checkLastName(std::string lastName);

std::string createFileLine(std::string& loginFirstName, std::string loginlastName, std::string& loginPassword);