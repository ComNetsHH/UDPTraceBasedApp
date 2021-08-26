#include "UdpTraceBasedApp.h"

#include "inet/common/ModuleAccess.h"
#include "inet/common/lifecycle/NodeStatus.h"

Define_Module(UdpTraceBasedApp);

void UdpTraceBasedApp::initialize(int stage)
{
    // initialize with UdpBasicApp
    UdpBasicApp::initialize(stage);
    if (stage == INITSTAGE_LOCAL) {
        const char *traceFile = par("traceFile");
        // read the timeStamp vector and in case it it empty or the file does not exist the module will not be started,
        // as specified in handleStartOperation method.
        parseTraceFile2Vector(traceFile,timeStamp);
        //////////////////////////////////////////////////////////////////////////
        // Emit application packet sent Signal (Musab)
        //////////////////////////////////////////////////////////////////////////
        appPacketSentSignal = registerSignal("appPacketSent");
    }
}

void UdpTraceBasedApp::parseTraceFile2Vector(const char* filename, std::vector<double>& vecOfDoubles)
{
    std::vector<std::string> vecOfStrs;
    std::ifstream in(filename, std::ios::in);
    // Check if the file is opened (we modified the error message here to just  return in order to enable scripting the application)
    if (in.fail())
            return;
    std::string str;
    // Read the file line by line until the end.
    while (std::getline(in, str))
    {
        // Append the contents of a non-empty line to the vector of strings
        if (str.size() > 0)
            vecOfStrs.push_back(str);
    }
    // Close The File
    in.close();
    // Assign the elements of vecOfStrs to vecOfDoubles after converting it from string to double
    vecOfDoubles.resize(vecOfStrs.size());
    std::transform(vecOfStrs.begin(), vecOfStrs.end(), vecOfDoubles.begin(),
        [](std::string const& val) {return stod(val); });
}

void UdpTraceBasedApp::handleStartOperation(LifecycleOperation *operation)
{
    if (timeStamp.empty()){
        return;
    }
    startTime = timeStamp.at(0);
    simtime_t start = std::max(startTime, simTime());
    if ((stopTime < SIMTIME_ZERO) || (start < stopTime) || (start == stopTime && startTime == stopTime)) {
        selfMsg->setKind(START);
        scheduleAt(start, selfMsg);
    }
}

void UdpTraceBasedApp::processStart(){
    // a counter for the index of the timeStamp vector
    timeIndex = 0;
    UdpBasicApp::processStart();
}

void UdpTraceBasedApp::processSend()
{
    sendPacket();
    //////////////////////////////////////////////////////////////////////////
    // Emit application packet sent Signal (Musab) (Musab)
    //////////////////////////////////////////////////////////////////////////
    emit(appPacketSentSignal, simTime());
    // Calculate the next packet transmission time from the timeStamp vector
    timeIndex = timeIndex + 1;
    // to ensure that the if statement will be checked if and only if the timeStamp has at least 2 elements.
    if (timeIndex < timeStamp.size()){
        simtime_t nextSendTime = simTime() + (timeStamp.at(timeIndex)  -timeStamp.at(timeIndex-1));
        selfMsg->setKind(SEND);
        scheduleAt(nextSendTime, selfMsg);
    } else {
        selfMsg->setKind(STOP);
        scheduleAt(simTime(), selfMsg);
    }
}
