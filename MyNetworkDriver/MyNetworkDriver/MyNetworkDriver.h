#ifndef MyNetworkDriver_h
#define MyNetworkDriver_h

#include <DriverKit/IOService.h>
#include <NetworkingDriverKit/IOUserNetworkEthernet.h>

class MyNetworkDriver: public IOUserNetworkEthernet
{
public:
    virtual bool init(void) override;
    virtual kern_return_t Start(IOService* provider) override;
    virtual kern_return_t Stop(IOService* provider) override;
    virtual kern_return_t SetInterfaceEnable(bool enabled) override;
    virtual void HandlePacketAvailable(void) override;
    
protected:
    void setInterfaceProperties(void);
    
private:
    struct MyNetworkDriver_IVars* ivars;
};

#endif /* MyNetworkDriver_h */
