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

bool checkValidity(const std::string& firstName, const std::string& registerPassword, const std::string& lastName) {
    return checkPassword(registerPassword) && checkFirstName(firstName) && checkLastName(lastName);
}

bool checkFirstName(const std::string& firstName) {
    // Check if firstName is non-empty and does not contain spaces
    bool checkSize = !firstName.empty();
    bool checkSpaces = (firstName.find(' ') == std::string::npos);

    // Return true if size is valid and there are no spaces
    return checkSize && checkSpaces;
}

bool checkLastName(const std::string& lastName) {
    // Check if lastName is non-empty and does not contain spaces
    bool checkSize = !lastName.empty();
    bool checkSpaces = (lastName.find(' ') == std::string::npos);

    // Return true if size is valid and there are no spaces
    return checkSize && checkSpaces;
}

std::string createFileLine(std::string& loginFirstName, std::string loginlastName, std::string& loginPassword)
{
    std::string inputLine;
    inputLine = loginFirstName + " " + loginlastName + " " + loginPassword;
    return inputLine;
}