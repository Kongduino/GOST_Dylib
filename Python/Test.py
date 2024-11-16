#!/usr/bin/python3
from ctypes import *
import platform, os, sys, random
from hexdump import hexDump

pl = platform.system()
if pl == 'Darwin':
  GOST = CDLL('../kuznechik.dylib')
elif pl == 'Linux':
  GOST = CDLL('../kuznechik.so')

cipher_blk = bytes(16)
decipher_blk = bytes(16)
cipher_blkB = cast(cipher_blk, POINTER(c_char))
test_key = b'\xef\xcd\xab\x89\x67\x45\x23\x01\x10\x32\x54\x76\x98\xba\xdc\xfe\x77\x66\x55\x44\x33\x22\x11\x00\xff\xee\xdd\xcc\xbb\xaa\x99\x88'
keyB = cast(test_key, POINTER(c_char))
encrypt_test_string = b'\x88\x99\xaa\xbb\xcc\xdd\xee\xff\x00\x77\x66\x55\x44\x33\x22\x11'
encrypt_test_result = b'\xcd\xed\xd4\xb9\x42\x8d\x46\x5a\x30\x24\xbc\xbe\x90\x9d\x67\x7f'

print("Init")
GOST.GOST_Kuz_Expand_Key(keyB)
hexDump(encrypt_test_string)
print("Encrypt")
GOST.GOST_Kuz_Encrypt(encrypt_test_string, cipher_blk)
hexDump(cipher_blk)
if cipher_blk != encrypt_test_result:
  print("    Error! Output is incorrect.")
  sys.exit()
else:
  print("    Output is correct!")
print("Decrypt")
GOST.GOST_Kuz_Decrypt(cipher_blk, decipher_blk)
hexDump(decipher_blk)
if decipher_blk != encrypt_test_string:
  print("    Error! Output is incorrect.")
  sys.exit()
else:
  print("    Output is correct!")

