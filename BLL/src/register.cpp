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

bool checkValidity(std::string registerUsername, std::string registerPassword)
{
    bool checkValidityB = false;
    if (checkPassword(registerPassword) && checkUsername(registerUsername))
    {
        checkValidityB = true;
    }
    return checkValidityB;
}

bool checkUsername(std::string username)
{
    return !(username.find(' ') != std::string::npos);
}

std::string createFileLine(std::string& loginUsername, std::string& loginPassword)
{
    std::string inputLine;
    inputLine = loginUsername + " " + loginPassword;
    return inputLine;
}