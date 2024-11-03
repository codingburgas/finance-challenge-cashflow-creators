#include "../lib/precompileBLL.h"
#include "../lib/register.h"

bool checkPassword(std::string password)
{
    bool checkSize = false;
    bool checkSpaces = false;
    bool checkUpper = false;
    bool checkSpecial = false;
    bool checkNumber = false;

    if (password.size() >= 6 && password.size() <= 16) checkSize = true;

    if (password.find(' ') != std::string::npos) checkSpaces = true;

    for (int i = 0; i < password.size(); i++)
    {
        if (password[i] >= 65 && password[i] <= 90) checkUpper = true;
        if (password[i] >= 48 && password[i] <= 57) checkNumber = true;
        if (!(password[i] >= 65 && password[i] <= 90) && !(password[i] >= 48 && password[i] <= 57) && !(password[i] >= 97 && password[i] <= 122)) checkSpecial = true;
    }

    if (checkSize && checkUpper && checkNumber && checkSpecial && !checkSpaces)
        return true;
    else
        return false;
}

bool checkValidity(std::string firstName, std::string registerPassword, std::string lastName)
{
    bool checkValidityB = false;
    if (checkPassword(registerPassword) && checkFirstName(firstName) && checkLastName(lastName))
    {
        checkValidityB = true;
    }
    return checkValidityB;
}

bool checkFirstName(std::string firstName)
{
    bool checkSize = false;
    bool checkSpaces = false;
    bool check = false;
    if (firstName.size() > 0) checkSize = true;
    if (firstName.find(' ') != std::string::npos) checkSpaces = true;
    if (checkSize && checkSpaces) check = true;
    return check;
}

bool checkLastName(std::string lastName)
{
    bool checkSize = false;
    bool checkSpaces = false;
    bool check = false;
    if (lastName.size() > 0) checkSize = true;
    if (lastName.find(' ') != std::string::npos) checkSpaces = true;
    if (checkSize && checkSpaces) check = true;
    return check;
}

std::string createFileLine(std::string& loginFirstName, std::string loginlastName, std::string& loginPassword)
{
    std::string inputLine;
    inputLine = loginFirstName + " " + loginlastName + " " + loginPassword;
    return inputLine;
}