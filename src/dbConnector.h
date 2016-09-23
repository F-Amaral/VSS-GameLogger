#include <iostream>
#include <sqlite3.h>
#include <sstream>
#include <string>

class dbConnector
{
public:
	dbConnector();
	void connect();
	void close();
	bool checkConnection();
	void closeConnection();
	void generateDB();
	void resolve();

private:
	char *dbName;
	char *sqlErrorMessage;
	sqlite3 *db;
	int rc;
};
