//
// Created by Egri Zoltán on 2019. 02. 06..
//

#include "device.h"

Device::Device(std::string id)
{
    _id = id;
}
std::string Device::getID()
{
    return _id;
}
