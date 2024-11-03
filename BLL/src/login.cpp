#include "../lib/precompileBLL.h"
#include "../lib/login.h"

std::string createFileLine(std::string& loginFirstName, std::string loginlastName, std::string& loginPassword)
{
    std::string inputLine;
    inputLine = loginFirstName + " " + loginPassword + " " + loginPassword;
    return inputLine;
}