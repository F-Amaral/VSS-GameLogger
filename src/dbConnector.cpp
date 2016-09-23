#include "dbConnector.h"

using namespace std;

dbConnector::dbConnector(){
	char* command="echo $(date | tr \" \" \"-\" | rev | cut -d \"-\" -f3- | rev).db";
	dbName = (char*)system(command);
	//cout << dbName << endl;
}

void dbConnector::connect(){
	rc=sqlite3_open((const char*)dbName, &db);
	if(!checkConnection()){
		cout << "Database Error! Data will not be stored!" << endl;
		exit(0);
	}
}

bool dbConnector::checkConnection(){
	if (rc){
		return false;
	}else{
		return true;
	}
}

void dbConnector::closeConnection(){
	sqlite3_close(db);
}

void dbConnector::generateDB(){
	stringstream commandString;
	cout << "go to sleep" << endl;
	commandString << "$(cat src/default/defaultDBModel.dump | sqlite3 databases/" << dbName << ")";
	string tmp = commandString.str();
	cout << "------------------" << tmp << endl;
	const char* command = tmp.c_str();
	int i = system(command);
	cout << "name" << dbName << endl;
}

void dbConnector::resolve(){
	generateDB();
	connect();
	closeConnection();
}
