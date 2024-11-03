#include "../lib/precompileBLL.h"
#include "../lib/balance.h"

// Helper function to check if a string is a valid number
bool isValidNumber(std::string& str) {
    bool decimalPoint = false;

    if (str.empty()) return false;

    for (char c : str) {
        if (c >= '0' && c <= '9') {
            continue;  
        }
        if (c == '.' && !decimalPoint) {
            decimalPoint = true;
            continue;
        }
        return false;
    }
    return true;
}

float totalIncome = 0.0f, totalExpense = 0.0f, tBalance = 0.0f;
std::string income, expenses, balance;

void calculateBalance(std::string& enterIncome, std::string& enterExpense, float& enteredIncome, float& enteredExpense, float& totalIncome, float& totalExpense, float& tBalance) {
    try {
        if (isValidNumber(enterIncome) && isValidNumber(enterExpense)) {
            enteredIncome = std::stof(enterIncome); 
            enteredExpense = std::stof(enterExpense);
        }
        else {
            throw std::invalid_argument("Non-numeric input.");
        }

        totalIncome += enteredIncome;
        totalExpense += enteredExpense;
        tBalance = totalIncome - totalExpense;

        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2);

        oss.str("");  // Clear the stream
        oss << totalIncome;
        income = oss.str();

        oss.str("");
        oss << totalExpense;
        expenses = oss.str();

        oss.str("");
        oss << tBalance;
        balance = oss.str();

    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid input: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Input number is out of range." << std::endl;
    }
}