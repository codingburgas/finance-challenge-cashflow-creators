#pragma once
#include <C:\Program Files\MySQL\MySQL Connector C++ 9.1\include\jdbc\cppconn\statement.h>
#include <C:\Program Files\MySQL\MySQL Connector C++ 9.1\include\jdbc\cppconn\prepared_statement.h>
#include <C:\Program Files\MySQL\MySQL Connector C++ 9.1\include\jdbc\mysql_driver.h>
#include <C:\Program Files\MySQL\MySQL Connector C++ 9.1\include\jdbc\mysql_connection.h>
#include <iostream>
#include <string>

void registerUser(const std::string& name, const std::string& surname, const std::string& email, const std::string& phone);