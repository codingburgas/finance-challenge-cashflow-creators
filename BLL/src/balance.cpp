#include "../lib/precompileBLL.h"
#include "../lib/balance.h"

// Helper function to check if a string is a valid number
bool isValidNumber(const std::string& str) {
    bool decimalPoint = false;
    bool hasDigits = false;

    // Check if the string is empty
    if (str.empty()) return false;

    // Check for a leading sign
    size_t startIndex = 0;
    if (str[0] == '-' || str[0] == '+') {
        startIndex = 1;
    }

    // Iterate over each character in the string
    for (size_t i = startIndex; i < str.size(); ++i) {
        char c = str[i];

        // Check for digits
        if (c >= '0' && c <= '9') {
            hasDigits = true;  // Found at least one digit
            continue;
        }

        // Check for decimal point
        if (c == '.' && !decimalPoint) {
            decimalPoint = true;
            continue;
        }

        // If we reach here, it's invalid
        return false;
    }

    // A valid number must have at least one digit
    return hasDigits;
}


void calculateBalance(float& totalIncome, float& totalExpense, float& totalBalance, std::string& balance) {
    try {
        totalBalance = totalIncome - totalExpense;

        // Check if balance is valid and update totalBalance if needed
        if (isValidNumber(balance)) {
            try {
                float parsedBalance = std::stof(balance);
                totalBalance += parsedBalance;
            }
            catch (const std::invalid_argument&) {
                std::cerr << "Conversion error: Non-numeric input for balance." << std::endl;
            }
            catch (const std::out_of_range&) {
                std::cerr << "Input number for balance is out of range." << std::endl;
            }
        }
        else {
            std::cerr << "Invalid input: Non-numeric balance." << std::endl;
        }

        // Format the total balance string to two decimal places
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << totalBalance;
        balance = oss.str();
    }
    catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }
}

void calculateIncome(std::string& entIncome, std::string income, float& enteredIncome, float& totalIncome) {
    try {
        if (isValidNumber(entIncome)) {
            enteredIncome = std::stof(entIncome);
        }
        else {
            throw std::invalid_argument("Non-numeric input.");
        }

        totalIncome += enteredIncome;

        std::ostringstream oss;
        oss.str(""); 
        oss << totalIncome;
        income = oss.str();
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid input: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Input number is out of range." << std::endl;
    }
}

void calculateExpenses(std::string& entExpense,std::string expense, float& enteredExpense, float& totalExpense) {
    try {
        if (isValidNumber(entExpense)) {
            enteredExpense = std::stof(entExpense);
        }
        else {
            throw std::invalid_argument("Non-numeric input.");
        }

        totalExpense += enteredExpense;

        std::ostringstream oss;
        oss.str("");
        oss << totalExpense;
        expense = oss.str();
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid input: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Input number is out of range." << std::endl;
    }
}

void saveIncomeExpense(const std::string& firstName, const std::string& lastName, float& income, float& expense) {
    std::fstream dataFile;
    dataFile.open("../files/data.txt", std::ios::in | std::ios::out | std::ios::app);
    if (!dataFile) {
        std::cout << "data.txt failed to load!" << std::endl;
        return;
    }

    // Write data in a specific format
    dataFile << firstName << " " << lastName << ": "
        << "Income=" << std::fixed << std::setprecision(2) << income << " "
        << "Expense=" << std::fixed << std::setprecision(2) << expense << std::endl;

    dataFile.close();
}

bool retrieveIncomeExpense(const std::string& firstName, const std::string& lastName, std::string& income, std::string& expenses, float& totalIncome, float& totalExpense) {
    std::ifstream dataFile("../files/data.txt", std::ios::in);
    if (!dataFile) {
        std::cout << "data.txt failed to load!" << std::endl;
        return false;
    }

    std::string line;
    std::string fullName = firstName + " " + lastName + ":";
    while (std::getline(dataFile, line)) {
        if (line.find(fullName) != std::string::npos) {
            size_t incomePos = line.find("Income=");
            size_t expensePos = line.find("Expense=");

            if (incomePos != std::string::npos && expensePos != std::string::npos) {
                try {
                    totalIncome = std::stof(line.substr(incomePos + 7, expensePos - (incomePos + 7)));
                    totalExpense = std::stof(line.substr(expensePos + 8));

                    // Turn the float into string
                    std::ostringstream ossIncome, ossExpenses;
                    ossIncome << std::fixed << std::setprecision(2) << totalIncome;
                    ossExpenses << std::fixed << std::setprecision(2) << totalExpense;
                    income = ossIncome.str();
                    expenses = ossExpenses.str();

                    return true;  // Successfully retrieved data
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "Invalid data in file: " << e.what() << std::endl;
                    return false;
                }
                catch (const std::out_of_range& e) {
                    std::cout << "Data out of range: " << e.what() << std::endl;
                    return false;
                }
            }
        }
    }
    dataFile.close();
    return false;
}