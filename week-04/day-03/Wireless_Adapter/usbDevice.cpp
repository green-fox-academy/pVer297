//
// Created by Egri Zoltán on 2019. 02. 06..
//

#include "usbDevice.h"
USBDevice::USBDevice(std::string id, USBType usbType) : Device(id)
{
    _usbType = usbType;
}

std::string USBDevice::typeToString(USBType usbType){
    switch (usbType){
        case USBType::USB_TYPE_2: return "Type 2";
        case USBType::USB_TYPE_3: return "Type 3";
        default: return "unknown type";
    }
}