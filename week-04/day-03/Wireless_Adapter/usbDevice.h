//
// Created by Egri Zoltán on 2019. 02. 06..
//

#ifndef WIRELESS_ADAPTER_USBDEVICE_H
#define WIRELESS_ADAPTER_USBDEVICE_H

#include <iostream>
#include "device.h"

enum USBType{
    USB_TYPE_2,
    USB_TYPE_3
};

class USBDevice : virtual public Device
{
 protected:
    USBType _usbType;
 public:
    USBDevice(std::string id, USBType usbType);
    std::string typeToString(USBType usbType);

};

#endif //WIRELESS_ADAPTER_USBDEVICE_H
