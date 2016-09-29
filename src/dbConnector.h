#include <iostream>
#include <sqlite3.h>
#include <sstream>
#include <string>

using namespace std;

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
	string cmdTerminal(string s);
private:
	string dbName;
	char *sqlErrorMessage;
	sqlite3 *db;
	int rc;
};
