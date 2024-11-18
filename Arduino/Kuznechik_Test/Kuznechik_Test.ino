//#include <Adafruit_TinyUSB.h> // For nRF52840
#include "gost_3412_2015_calc.c"
#include "test.h"
#include "hexdump.h"

void setup() {
  Serial.begin(115200);
  Serial.println("\n\n\n    ------------------------------------------------------");
  Serial.println("                 RUI3 Kuznechik Example");
  Serial.println("    ------------------------------------------------------");
  delay(2000);
  vect cipher_blk;
  vect decipher_blk;
  GOST_Kuz_Expand_Key(test_key);
  Serial.print("PLAIN\n");
  hexDump((unsigned char *)encrypt_test_string, 16);
  GOST_Kuz_Encrypt((unsigned char *)encrypt_test_string, cipher_blk);
  Serial.print("CIPHER\n");
  hexDump((unsigned char *)cipher_blk, 16);
  GOST_Kuz_Decrypt(cipher_blk, decipher_blk);
  Serial.print("DECIPHERED\n");
  hexDump((unsigned char *)decipher_blk, 16);
  if (memcmp((unsigned char *)decipher_blk, (unsigned char *)encrypt_test_string, 16) == 0) {
    Serial.print("Success!\n");
  } else {
    Serial.println("Decryption failed!\n");
  }

  Serial.print("\n\nPLAIN\n");
  memcpy((unsigned char *)encrypt_test_string, (unsigned char *)"Yellow Submarine", 16);
  hexDump((unsigned char *)encrypt_test_string, 16);
  GOST_Kuz_Encrypt((unsigned char *)encrypt_test_string, cipher_blk);
  Serial.print("CIPHER\n");
  hexDump((unsigned char *)cipher_blk, 16);
  GOST_Kuz_Decrypt(cipher_blk, decipher_blk);
  Serial.print("DECIPHERED\n");
  hexDump((unsigned char *)decipher_blk, 16);
  if (memcmp((unsigned char *)decipher_blk, (unsigned char *)encrypt_test_string, 16) == 0) {
    Serial.print("Success!\n");
  } else {
    Serial.println("Decryption failed!\n");
  }
}

void loop() {
}
