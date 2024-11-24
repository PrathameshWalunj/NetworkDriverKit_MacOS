//
//  MyNetworkDriver.cpp
//  MyNetworkDriver
//
//  Created by Prathamesh Walunj on 11/23/24.
//

#include <os/log.h>
#include <DriverKit/IOUserServer.h>
#include <DriverKit/IOLib.h>
#include <NetworkingDriverKit/IOUserNetworkEthernet.h>
#include "MyNetworkDriver.h"

#define super IOUserNetworkEthernet
OSDefineMetaClassAndStructors(MyNetworkDriver, IOUserNetworkEthernet);


/*
 *Instance Variable Structure
 *Structure holds driver's private data
 *Using separate structure to keep main class clean and organized
 */

struct MyNetworkDriver_IVars {
    // Main queue for dispatching driver operations
    // ### to ensure thread safety in driver
    IODispatchQueue*                dispatchQueue;
    
    // Pool for network packet allocation
    // This is where we get memory for network packets
    IOUserNetworkPacketBufferPool*  packetPool;
    
    // Queue for packets waiting to be transmitted
    // Outgoing packets go here before being sent
    IOUserNetworkPacketQueue*       txQueue;
    
    // Queue for received packets
    // Incoming packets are stored here to be processed
    IOUserNetworkPacketQueue*       rxQueue;
    
    // Current state of interface
    // true = enabled, false = disbaled
    bool                            enabled;
};




/*
 *Initialization Method
 *Called when driver object is first created
 *Return true if initialization successfull, false otherwise
 */

bool MyNetworkDriver::init()
{
    // Always call superclass init first
    // ensures proper initialization of inherited features
    if (!super::init()) {
        return false;
    }
    
    // Allocate instance variables structure
    // IONewZero both allocates & zeros the memory
    ivars = IONewZero(MyNetworkDriver_IVars, 1);
    if (ivars == nullptr) {
        os_log(OS_LOG_DEFAULT, "MyNetworkDriver: Initialization failed! out of memory");
        return false;
    }
    
    os_log(OS_LOG_DEFAULT, "MyNetworkDriver: Initialized");
    return true;
    
