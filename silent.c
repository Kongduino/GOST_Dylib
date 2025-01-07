#include "gost_3412_2015_calc.h"
#include "test.h"

int main(int argc, char *argv[]) {
  vect cipher_blk;
  vect decipher_blk;
  GOST_Kuz_Expand_Key(test_key);
  for(int i = 0; i < 1000; i++) {
    GOST_Kuz_Encrypt((unsigned char *)encrypt_test_string, cipher_blk);
    GOST_Kuz_Decrypt(cipher_blk, decipher_blk);
  }
  return 0;
}

