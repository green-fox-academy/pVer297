//
// Created by Egri Zoltán on 2019. 02. 06..
//

#ifndef WIRELESS_ADAPTER_NETWORKDEVICE_H
#define WIRELESS_ADAPTER_NETWORKDEVICE_H

#include "device.h"

class NetworkDevice : virtual public Device
{
 protected:
    int _bandwidth;
 public:
    NetworkDevice(std::string id, int bandwidth);
};

#endif //WIRELESS_ADAPTER_NETWORKDEVICE_H
