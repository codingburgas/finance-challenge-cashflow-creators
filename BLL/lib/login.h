#pragma once
#define LOGIN_PAGE_H

#include <string>
#include <MySQL\MySQL Connector C++ 9.1\include\jdbc\cppconn\statement.h>
#include <MySQL\MySQL Connector C++ 9.1\include\jdbc\cppconn\prepared_statement.h>
#include <MySQL\MySQL Connector C++ 9.1\include\jdbc\mysql_driver.h>
#include <MySQL\MySQL Connector C++ 9.1\include\jdbc\mysql_connection.h>
#include <MySQL\MySQL Connector C++ 9.1\include\jdbc\cppconn\resultset.h>

class LoginPage {
public:
    LoginPage(const std::string& db_host, const std::string& db_user, const std::string& db_password, const std::string& db_name);
    ~LoginPage();

    /**
     * Tries to log the user in with the provided email and password.
     * @param email The user's email address.
     * @param password The user's password.
     * @return int status code:
     *         1  - Login successful.
     *         0  - Account not found.
     *        -2  - Incorrect password.
     *        -1  - Connection or SQL error.
     */
    int login(const std::string& email, const std::string& password);

private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
};