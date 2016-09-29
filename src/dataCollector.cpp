#include "dataCollector.h"

DataCollector::DataCollector(){

}

void DataCollector::getVisionState(){
    interface->createSocketReceiveState(&global_state);
    global_state.origin();
    for(int i = 0; i < global_state.balls_size(); i++){
        
    }
    
    while(1){
        interface->receiveState();
    }
}