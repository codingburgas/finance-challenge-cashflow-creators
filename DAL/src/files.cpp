#include "../lib/precompileDAL.h"

std::string getLine(std::fstream& file)
{
	std::string line;
	if (!file.eof())
		std::getline(file, line);
	return line;
}

int getFileSize(std::fstream& file)
{
	int fileSize = 0;
	while (!file.eof())
	{
		fileSize++;
	}
	return fileSize;
}

void writeInFile(std::fstream& file, std::string& line)
{
	file << line << std::endl;
}

bool checkIfInFile(std::fstream& file, std::string& line)
{
	std::string fileLine;
	while (!file.eof())
	{
		std::getline(file, fileLine);
		if (fileLine == line)
		{
			return true;
		}
	}
	return false;
}

bool checkIfInFileLine(std::fstream& file, std::string& firstName, std::string lastName)
{
	std::string fileLine;
	while (!file.eof())
	{
		std::getline(file, fileLine);
		if (fileLine.find(firstName) != std::string::npos && fileLine.find(lastName) != std::string::npos)
		{
			return true;
		}
	}
	return false;
}