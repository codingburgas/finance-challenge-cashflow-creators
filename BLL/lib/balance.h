#pragma once
#include "precompileBLL.h"

bool isValidNumber(const std::string& str);

void calculateBalance(float& totalIncome, float& totalExpense, float& tBalance, std::string balance);

void calculateIncome(std::string& enterIncome, std::string income, float& enteredIncome, float& totalIncome);

void calculateExpenses(std::string& enterExpense, std::string expense, float& enteredExpense, float& totalExpense);

void saveIncomeExpense(const std::string& firstName, const std::string& lastName, float& income, float& expense);

bool retrieveIncomeExpense(const std::string& firstName, const std::string& lastName, std::string& income, std::string& expenses, float& totalIncome, float& totalExpense);