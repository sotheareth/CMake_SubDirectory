#include <iostream>
#include "MM/Message.h"
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;

int main(int argc, char **argv) {

	MM::Message message;
	message.say("Hello World");

	cout << endl;
	cout << "Running 'SELECT 'Hello World!AS _message'..." << endl;

	try {
		sql::Driver *driver;
		sql::Connection *con;

		// Initializing Date object with 21st March 2016
		boost::gregorian::date dateObj1 { 2016, 3, 21 };

		// Initializing Date object with 1st October 2016
		boost::gregorian::date dateObj2 { 2016, 10, 1 };

		// Get the Duration between 2 Dates
		boost::gregorian::date_duration dur = dateObj2 - dateObj1;

		std::cout << "Date 1 : " << dateObj1 << std::endl;
		std::cout << "Date 2 : " << dateObj2 << std::endl;

		// Fetch Days from date_duration object
		std::cout << "Difference b/w 2 Dates in days : " << dur.days() << std::endl;

		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "root");

		delete con;

	} catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	return 0;
}
