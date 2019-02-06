#include <iostream>
#include "device.h"
#include "usbDevice.h"
#include "networkDevice.h"
#include "wirelessAdapter.h"

int main(int argc, char* args[])
{
    WirelessAdapter adapter("da4c32fb21", USBType::USB_TYPE_2, 100);
    adapter.info();
}