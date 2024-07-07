#ifndef __W5500ETH_H__
#define __W5500ETH_H__


// #include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Ethernet.h>
#define SPI SPI5
#define SPI4 SPI5
#undef SPI
#undef SPI4

#undef SPI_ETHERNET_SETTINGS
#define SPI_ETHERNET_SETTINGS SPISettings(10000000, MSBFIRST, SPI_MODE3)

// extern SPIClass SPI5;
//extern SPIClass SPI __attribute__((alias("SPI5")));
// extern SPIClass SPI __attribute__((alias("SPI5")));
// extern SPIClass SPI0__attribute__((alias("SPI4")));
// extern SPIClass SPI = SPIClass(5);

//-----------------------------------------
static uint8_t DEF_RST = (21);//21(SJ1=1-2, EMMC_DATA3) or 26(SJ1=2-3, I2S_BCK)
static uint8_t DEF_CS  = (19);//19(SJ2=1-2, I2S_DIN)    or 24(SJ2=2-3, SPI5_CS_X)

//-----------------------------------------
void W5500ETH_setup();
void W5500ETH_setup(uint8_t cs);
void W5500ETH_mac(byte*);

#endif
