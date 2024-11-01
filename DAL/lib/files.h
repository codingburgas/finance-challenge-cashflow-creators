#pragma once

std::string getLine(std::fstream& file);

int getFileSize(std::fstream& file);

void writeInFile(std::fstream& file, std::string& line);

bool checkIfInFile(std::fstream& file, std::string& line);

bool checkIfInFileLine(std::fstream& file, std::string& username);