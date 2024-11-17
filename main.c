#define DEBUG_MODE
#include "gost_3412_2015_calc.h"
#include "test.h"
#include "hexdump.h"

int main(int argc, char *argv[]) {
  vect cipher_blk;
  vect decipher_blk;
  GOST_Kuz_Expand_Key(test_key);
  printf("PLAIN\n");
  hexDump((unsigned char *)encrypt_test_string, 16);
  GOST_Kuz_Encrypt((unsigned char *)encrypt_test_string, cipher_blk);
  printf("CIPHER\n");
  hexDump((unsigned char *)cipher_blk, 16);
  GOST_Kuz_Decrypt(cipher_blk, decipher_blk);
  printf("DECIPHERED\n");
  hexDump((unsigned char *)decipher_blk, 16);
  if(memcmp(decipher_blk, encrypt_test_string, 16) == 0)
    printf("    [√] Output is correct!\n\n");
  else
    printf("    [x] Output is incorrect!\n\n");
  return 0;
}
