#include "iostream"
#include "dbConnector.h"

using namespace std;

int main(){
    dbConnector *connector = new dbConnector();
    connector->resolve();

    return 0;
}
