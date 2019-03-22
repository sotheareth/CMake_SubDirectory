#include <iostream>
#include "MM/Message.h"
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main(int argc, char **argv) {

	MM::Message message;
	message.say("Hello World");

	cout << endl;
	cout << "Running 'SELECT 'Hello World!AS _message'..." << endl;

	try {
	  sql::Driver *driver;
	  sql::Connection *con;
	 

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
