#include "../lib/precompileBLL.h"
#include "../lib/login.h"

std::string createLoginFileLine(std::string loginFirstName, std::string loginlastName, std::string loginPassword)
{
    std::string inputLine;
    inputLine = loginFirstName + " " + loginlastName + " " + loginPassword;
    return inputLine;
}