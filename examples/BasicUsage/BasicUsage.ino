#include <W5500ETH.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  
byte ip[] = { 192, 168, 100, 222 };
EthernetServer server(80);

void setup()
{
    pinMode(LED_BUILTIN3, OUTPUT);
    Serial.begin(115200);
    
    Serial.print("SPI : ");
    Serial.println((unsigned long)(&SPI));
    Serial.print("SPI3: ");
    Serial.println((unsigned long)(&SPI3));
    Serial.print("SPI4: ");
    Serial.println((unsigned long)(&SPI4));
    Serial.print("SPI5: ");
    Serial.println((unsigned long)(&SPI5));
    // -----------------------------------------------------------
    // W5500-Ether を使うには、通常のEthernetライブラリの操作の前に以下の
    // 関数を1回呼び出します。
    // ボード上のSJ2ジャンパー設定によって初期化方法が異なります。
    
    // W5500ETH_setup(19);// SJ2が1-2ショート時
    // W5500ETH_setup(24);// SJ2が2-3ショート時(not working...?)
    W5500ETH_setup(19);// SJ2が2-3ショート時


    // -----------------------------------------------------------
    // W5500-Ether 内蔵のEEPROMからMACアドレスを取得するには以下の関数を
    // 呼び出します。引数は、6byte(もしくはそれ以上)のbyte型配列変数の
    // ポインタを指定します。
    // また、この関数は内部でWire()関数を呼び出してI2C通信行います。
    W5500ETH_mac(mac);

    // -----------------------------------------------------------
    // 以下、Arduino Ethernetシールドボードとそのライブラリを同様の操作が行えます。
    Ethernet.begin(mac, ip);
    if (Ethernet.hardwareStatus() == EthernetNoHardware)
    {
        Serial.println("W5500-Ether was not found.");
        while (1) {;};
    }

    // Print the read MAC address
    for(int i=0;i<6;i++)
    {
        Serial.print(mac[i],HEX);
        Serial.print(" ");
    }
    Serial.println();
}

void loop ()
{
    auto link_stat = Ethernet.linkStatus();

    switch (link_stat)
    {
        case LinkON:
            Serial.println("LINK: ON");
            break;
        case LinkOFF:
            Serial.println("LINK: OFF");
            break;
        case Unknown:
        default:
            break;
    }

    digitalWrite(LED_BUILTIN3, !digitalRead(LED_BUILTIN3));
    delay(3000);

}
