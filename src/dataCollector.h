#include "VSS-Interface/interface.h"
#include "common.h"

using namespace std;

class DataCollector{
private:
    Interface *interface;
    vss_state::Global_State global_state;
public:
    DataCollector();
    void getVisionState();


};