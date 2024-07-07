#include "W5500ETH.h"

void W5500ETH_setup()
{
    // reset W5500
    pinMode(DEF_RST, OUTPUT);
    digitalWrite(DEF_RST, LOW);
    delay(50);
    digitalWrite(DEF_RST, HIGH);

    return;
}

void W5500ETH_setup(uint8_t cs)
{
    W5500ETH_setup();
    Ethernet.init(cs);// set SPI_CS port

    return;
}

void W5500ETH_mac(byte *mac)
{
    // Read MAC address from onboard I2C EEPROM.
    Wire.begin();
    // NOTE: MACアドレス読み込みをここに書く
    // NOTE:
    // NOTE:
    *(mac+0) = 0xDE;
    *(mac+1) = 0xAD;
    *(mac+2) = 0xBE;
    *(mac+3) = 0xEF;
    *(mac+4) = 0x98;
    *(mac+5) = 0x21;
    return;
}