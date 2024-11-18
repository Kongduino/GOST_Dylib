#include <Adafruit_TinyUSB.h>  // For nRF52840
#include "Arduino.h"
#include "Wire.h"
#include "SSD1306Ascii.h"
// Click here to get the library: http://librarymanager/All#SSD1306Ascii
#include "SSD1306AsciiWire.h"
#include "gost_3412_2015_calc.c"
#include "test.h"
#include "hexdump.h"

#define I2C_ADDRESS 0x3C
#define RST_PIN -1
#define OLED_FORMAT &Adafruit128x64
SSD1306AsciiWire oled;
char buff[256];

void hexDumpOLED(unsigned char* myBuff, int ln) {
  uint8_t ix, iy;
  for (ix = 0; ix < ln; ix += 8) {
    oled.print("  ");
    for (iy = 0; iy < 8; iy++) {
      sprintf(buff + (iy * 2), "%02x", myBuff[ix + iy]);
    }
    oled.println(buff);
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("\n\n\n    ------------------------------------------------------");
  Serial.println("                 RUI3 Kuznechik Example");
  Serial.println("    ------------------------------------------------------");
  Wire.begin();
  //Wire.setClock(1000000);
  oled.begin(OLED_FORMAT, I2C_ADDRESS);
  oled.setFont(System5x7);
  oled.setScrollMode(SCROLL_MODE_AUTO);
  strcpy(buff, "  RAK19260 Kuznechik\n");
  oled.print(buff);

  delay(2000);
  vect cipher_blk;
  vect decipher_blk;
  GOST_Kuz_Expand_Key(test_key);
  Serial.print("PLAIN\n");
  oled.print("PLAIN\n");
  oled.print("  ");
  oled.println(encrypt_test_string);
  Serial.println(encrypt_test_string);
  GOST_Kuz_Encrypt((unsigned char *)encrypt_test_string, cipher_blk);
  Serial.print("CIPHER\n");
  oled.print("CIPHER\n");
  hexDumpOLED((unsigned char *)cipher_blk, 16);
  hexDump((unsigned char *)cipher_blk, 16);
  GOST_Kuz_Decrypt(cipher_blk, decipher_blk);
  Serial.print("DECIPHERED\n");
  oled.print("DECIPHERED\n");
  oled.print("  ");
  oled.print((char *)decipher_blk);
  Serial.println((char *)decipher_blk);
  if (memcmp((unsigned char *)decipher_blk, (unsigned char *)encrypt_test_string, 16) == 0) {
    Serial.print("Success!\n");
  } else {
    Serial.println("Decryption failed!\n");
  }
}

void loop() {
}
