//
// Copyright (C) 2000 Institut fuer Telematik, Universitaet Karlsruhe
// Copyright (C) 2004,2011 Andras Varga
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

#ifndef __INET_UDPTRACEBASEDAPP_H
#define __INET_UDPTRACEBASEDAPP_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "inet/applications/udpapp/UdpBasicApp.h"
#include "inet/common/ModuleAccess.h"
#include "inet/common/lifecycle/NodeStatus.h"
#include "inet/common/lifecycle/ModuleOperations.h"


using namespace inet;

class UdpTraceBasedApp : public UdpBasicApp
{

protected:
    virtual void processSend();
    virtual void initialize(int stage);
    virtual void parseTraceFile2Vector(const char* fileName, std::vector<double>& vecOfDoubles);
    void processStart();
    void handleStartOperation(LifecycleOperation *operation);
    int timeIndex;
    std::vector<double> timeStamp;
    //////////////////////////////////////////////////////////////////////////
    // Emit application packet sent Signal (Musab)
    //////////////////////////////////////////////////////////////////////////
    simsignal_t appPacketSentSignal;
};

#endif // ifndef __INET_UDPTRACEBASEDAPP_H

