//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

import inet.node.ethernet.Eth10M;
import inet.node.ethernet.EtherSwitch;
import inet.node.inet.Router;
import inet.node.inet.StandardHost;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;

package data_traffic_applications.simulations;

//
// TODO auto-generated type
//
network Network
{
    submodules:
    	configurator: Ipv4NetworkConfigurator {
            @display("is=s;p=100,100");
        }
    	sender: StandardHost {}
    	receiver: StandardHost {}
    connections:
        sender.ethg++ <--> Eth10M <--> receiver.ethg++;
}
