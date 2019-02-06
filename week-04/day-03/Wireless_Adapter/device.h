//
// Created by Egri Zoltán on 2019. 02. 06..
//

#ifndef WIRELESS_ADAPTER_DEVICE_H
#define WIRELESS_ADAPTER_DEVICE_H

#include <iostream>

class Device
{
 protected:
    std::string _id;
 public:
    Device(std::string id);
    std::string getID();

};

#endif //WIRELESS_ADAPTER_DEVICE_H
