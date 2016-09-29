#include "dbConnector.h"
#include "time.h"

dbConnector::dbConnector(){

	string command="echo -n $(date | tr \" \" \"-\" | rev | cut -d \"-\" -f3- | rev).db";
	dbName = cmdTerminal(command);
	//cout << dbName << endl;
}

void dbConnector::connect(){
	rc=sqlite3_open(dbName.c_str(), &db);
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
	cout << "Tmp " << tmp << endl;
	const char* command = tmp.c_str();
	int i = system(command);
}

void dbConnector::resolve(){
	generateDB();
	connect();
	//closeConnection();
}


string dbConnector::cmdTerminal(string s){
        char buffer[1024];
        std::string result = "";

        FILE* pipe = popen(s.c_str(), "r");
        if (!pipe) return "ERROR";
        
        while(!feof(pipe)) {
            if(fgets(buffer, 1024, pipe) != NULL)

                result += buffer;
        }
        pclose(pipe);
        return result;
    }