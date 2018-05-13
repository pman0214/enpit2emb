#include <kernel.h>
#include "mbed.h"

#include "MQTTmbed.h"
#include "MQTTBP3595.h"

/*----------------------------------------------------------------------*/
MQTTBP3595::MQTTBP3595(void): m_external_wlan(false)
{
    m_wlan = new GR_PEACH_WlanBP3595();
}

/*----------------------------------------------------------------------*/
MQTTBP3595::MQTTBP3595(GR_PEACH_WlanBP3595 *wlan): m_wlan(wlan), m_external_wlan(true)
{
}

/*----------------------------------------------------------------------*/
MQTTBP3595::~MQTTBP3595(void)
{
    /* disconnect */
    m_wlan->disconnect();

    if (!m_external_wlan)
    {
        delete m_wlan;
    }
}

/*----------------------------------------------------------------------*/
int MQTTBP3595::Connect(char *ssid, char *psk)
{
    int ret;

    ret = m_wlan->init();
    if (ret != 0)
    {
        return ret;
    }

    ret = m_wlan->connect(ssid, psk, NSAPI_SECURITY_WPA2, 15000);
    if (ret != 0)
    {
        return ret;
    }

    return 0;
}

/*----------------------------------------------------------------------*/
int MQTTBP3595::Connect(char *ssid, char *psk, nsapi_security_t security)
{
    int ret;

    ret = m_wlan->init();
    if (ret != 0)
    {
        return ret;
    }

    ret = m_wlan->connect(ssid, psk, security, 15000);
    if (ret != 0)
    {
        return ret;
    }

    return 0;
}

/*----------------------------------------------------------------------*/
GR_PEACH_WlanBP3595 *MQTTBP3595::GetWlan(void)
{
    return m_wlan;
}
