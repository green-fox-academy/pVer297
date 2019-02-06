//
// Created by Egri Zoltán on 2019. 02. 06..
//

#include "wirelessAdapter.h"
WirelessAdapter::WirelessAdapter(std::string id, USBType usbType, int bandwidth) :
    Device(id), USBDevice(id, usbType), NetworkDevice(id, bandwidth) {}

void WirelessAdapter::info()
{
    std::cout << "ID: " << _id
              << "\nUSB Type: " << typeToString(_usbType)
              << "\nBandwidth: " << _bandwidth << " Mbit/s" << std::endl;
}
