[![DOI](https://zenodo.org/badge/397504015.svg)](https://zenodo.org/badge/latestdoi/397504015)
# UdpTraceBasedApp
OMNeT++ Trace-Based Data Traffic Application extends the INET's `UdpBasicApp` by using a trace file to trigger the packet transmission. The file is a plain text file, where every line describes the trigger time of one packet, e.g., 

- t<sub>1</sub>      
- t<sub>2</sub> 
- ...
- t<sub>last</sub> 

The `UdpTraceBasedApp` application send the first packet at **t<sub>1</sub>** and the last packet at **t<sub>last</sub>**. 
## Getting Started
1. Please download [inet-4.2.5](https://github.com/inet-framework/inet/tree/v4.2.5) for OMNeT++ 5.6.2 and import it into the simulator.
2. Please clone this repo `UdpTraceBasedApp` and import it into OMNet++. To build it you need to do the following steps:
    1. `inet` must be set as a project reference. This is done by right-clicking on the `UdpTraceBasedApp` project in the Project Explorer and navigate to `Properties-> Project References -> Select inet -> Apply and Close`
    2. Ensure the build modes of this project and `inet` are identical (both `release` or both `debug`): This is done by right-clicking on each project in the Project Explorer and navigating to `Build Configuration -> Set Active -> <mode>`
    3. The `include paths` from INET must be added to this project such that you can write classes in your project which inherit `inet` classes. For that, you need to right-click on the `UdpTraceBasedApp` in the Project Explorer and navigate to `Properties -> OMNeT++ -> Makemake`, select the `src` folder in the list and then click "Options" in the right panel. 
    4. Go to the `Target` tab and make sure that `Shared library ...` is checked.
    5. Now go to the `Compile` tab and make sure all checkboxes are checked. 
    6. Move to the `Link` tab and make sure that the `Link with libraries exported from...` checkbox is checked. 
    7. Finally, `Apply and Close` and you should be able to `build` the `UdpTraceBasedApp` project without errors as a project that reference the INET project.

