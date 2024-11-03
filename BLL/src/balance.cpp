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


void calculateBalance(float& totalIncome, float& totalExpense, float& tBalance, std::string balance) {
   
        tBalance = totalIncome - totalExpense;

        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2);

        oss.str("");
        oss << tBalance;
        balance = oss.str();

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
        oss.str("");  // Clear the stream
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
        oss.str("");  // Clear the stream
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
        << "Income = " << std::fixed << std::setprecision(2) << income << " "
        << "Expense = " << std::fixed << std::setprecision(2) << expense << std::endl;

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
            // Parse the income and expense from the line
            size_t incomePos = line.find("Income=");
            size_t expensePos = line.find("Expense=");

            if (incomePos != std::string::npos && expensePos != std::string::npos) {
                try {
                    totalIncome = std::stof(line.substr(incomePos + 7, expensePos - (incomePos + 7)));
                    totalExpense = std::stof(line.substr(expensePos + 8));

                    // Turn the float into string
                    std::ostringstream ossIncome, ossExpenses;
                    ossIncome << std::fixed << std::setprecision(2) << totalIncome; // Format income
                    ossExpenses << std::fixed << std::setprecision(2) << totalExpense; // Format expenses
                    income = ossIncome.str(); // Retrieve formatted string for income
                    expenses = ossExpenses.str();

                    return true;  // Successfully retrieved data
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "Invalid data in file: " << e.what() << std::endl;
                    return false; // Return false if conversion fails
                }
                catch (const std::out_of_range& e) {
                    std::cout << "Data out of range: " << e.what() << std::endl;
                    return false; // Return false if conversion fails
                }
            }
        }
    }
    dataFile.close();
    return false;  // Entry not found
}