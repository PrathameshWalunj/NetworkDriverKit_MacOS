//
//  MyNetworkDriver.cpp
//  MyNetworkDriver
//
//  Created by Prathamesh Walunj on 11/23/24.
//

#include <os/log.h>

#include <DriverKit/IOUserServer.h>
#include <DriverKit/IOLib.h>

#include "MyNetworkDriver.h"

kern_return_t
IMPL(MyNetworkDriver, Start)
{
    kern_return_t ret;
    ret = Start(provider, SUPERDISPATCH);
    os_log(OS_LOG_DEFAULT, "Hello World");
    return ret;
}
