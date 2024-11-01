#include "../lib/precompileBLL.h"
#include "../lib/login.h"

std::string createFileLine(std::string& loginUsername, std::string& loginPassword)
{
    std::string inputLine;
    inputLine = loginUsername + " " + loginPassword;
    return inputLine;
}