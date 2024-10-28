#include "register.h"

void registerUser(const std::string& name, const std::string& surname, const std::string& email, const std::string& phone) {
	try {
		// Initialize the MySQL driver
		sql::mysql::MySQL_Driver* driver;
		sql::Connection* con;

		// Create a connection to the database
		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "your_username", "your_password");

		// Select the database
		con->setSchema("UserDatabase");

		// Create a prepared statement to prevent SQL injection
		sql::PreparedStatement* prep_stmt;
		prep_stmt = con->prepareStatement("INSERT INTO users (name, surname, email, phone_number) VALUES (?, ?, ?, ?)");

		// Bind the parameters
		prep_stmt->setString(1, name);
		prep_stmt->setString(2, surname);
		prep_stmt->setString(3, email);
		prep_stmt->setString(4, phone);
		prep_stmt->execute();

		//Clean Up
		delete prep_stmt;
		delete con;
	}
	catch (sql::SQLException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}