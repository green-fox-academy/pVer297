//
// Created by Egri Zoltán on 2019. 02. 06..
//

#include "networkDevice.h"
NetworkDevice::NetworkDevice(std::string id, int bandwidth) : Device(id)
{
    _bandwidth = bandwidth;
}
