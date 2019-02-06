//
// Created by Egri Zoltán on 2019. 02. 06..
//

#ifndef WIRELESS_ADAPTER_WIRELESSADAPTER_H
#define WIRELESS_ADAPTER_WIRELESSADAPTER_H

#include <iostream>
#include "usbDevice.h"
#include "networkDevice.h"

class WirelessAdapter : public USBDevice, public NetworkDevice
{
 public:
    WirelessAdapter(std::string id, USBType usbType, int bandwidth);
    void info();

};

#endif //WIRELESS_ADAPTER_WIRELESSADAPTER_H
