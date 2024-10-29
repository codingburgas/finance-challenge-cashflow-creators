#include "../lib/login.h"
#include <iostream>

LoginPage::LoginPage(const std::string& db_host, const std::string& db_user, const std::string& db_password, const std::string& db_name) {
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(db_host, db_user, db_password);
        con->setSchema(db_name);
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error connecting to database: " << e.what() << std::endl;
        con = nullptr;
    }
}

LoginPage::~LoginPage() {
    delete con;
}

int LoginPage::login(const std::string& email, const std::string& password) {
    if (con == nullptr) {
        std::cerr << "No database connection." << std::endl;
        return -1;  // Connection error
    }

    try {
        // First, check if the email exists in the database
        sql::PreparedStatement* checkEmailStmt = con->prepareStatement("SELECT password FROM users WHERE email = ?");
        checkEmailStmt->setString(1, email);
        sql::ResultSet* res = checkEmailStmt->executeQuery();

        if (!res->next()) {
            // No account with this email found
            std::cout << "Account not found." << std::endl;
            delete res;
            delete checkEmailStmt;
            return 0;  // Account not found
        }

        // Account exists, now check if the password matches
        std::string storedPassword = res->getString("password");
        delete res;
        delete checkEmailStmt;

        if (storedPassword == password) {
            // Password matches
            std::cout << "Login successful!" << std::endl;
            return 1;  // Login successful
        }
        else {
            // Password does not match
            std::cout << "Incorrect password." << std::endl;
            return -2;  // Incorrect password
        }

    }
    catch (sql::SQLException& e) {
        std::cerr << "Error during login: " << e.what() << std::endl;
        return -1;  // SQL error
    }
}