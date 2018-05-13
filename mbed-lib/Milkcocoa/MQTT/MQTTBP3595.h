#if !defined(MQTTBP3595_H)
#define MQTTBP3595_H

#include "MQTTmbed.h"
#include "MQTTSocket.h"
#include "GR_PEACH_WlanBP3595.h"
#include "EthernetInterface.h"

class MQTTBP3595 : public MQTTSocket
{
public:
    MQTTBP3595(void);
    MQTTBP3595(GR_PEACH_WlanBP3595 *wlan);
    ~MQTTBP3595(void);

    int Connect(char *ssid, char *psk);
    int Connect(char *ssid, char *psk, nsapi_security_t security);

    GR_PEACH_WlanBP3595 *GetWlan(void);

private:
    bool m_external_wlan;
    GR_PEACH_WlanBP3595 *m_wlan;

};
#endif
