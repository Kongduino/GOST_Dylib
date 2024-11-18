# GOST_Dylib

A ГОСТ 34.12 - 2015 cipher dynamic library for use with Python, Xojo, etc... like my [Chacha20_Dylib](https://github.com/Kongduino/Chacha20_Dylib), [Blowfish_Dylib](https://github.com/Kongduino/Blowfish_Dylib) and [SHA3_Dylib](https://github.com/Kongduino/SHA3_Dylib). It's based on [kuznechik](https://github.com/drobotun/kuznechik).

There are three examples: a regular [C example](main.c), a [Python example](./Python/) and 2 Arduino examples: [Kuznechik_Test](./Arduino/Kuznechik_Test/) and [Kuznechik_OLED](./Arduino/Kuznechik_OLED) (which is specific to the RAK19260).

The library currently encrypts only a block, I'll have to add padding and `GOST_Kuz_Encrypt_Buffer` / `GOST_Kuz_Decrypt_Buffer`.

```
$ make
gcc -Ofast -g -c -o gost_3412_2015_calc.o gost_3412_2015_calc.c
gcc -Ofast -g -c -o main.o main.c
gcc -Ofast -g *.c
gcc -dynamiclib gost_3412_2015_calc.o -o kuznechik.dylib
gcc *.o -o kuznechik_test
rm *.o *.out
./kuznechik_test
PLAIN
   +------------------------------------------------+ +----------------+
   |.0 .1 .2 .3 .4 .5 .6 .7 .8 .9 .a .b .c .d .e .f | |      ASCII     |
   +------------------------------------------------+ +----------------+
 0.|88 99 aa bb cc dd ee ff 00 77 66 55 44 33 22 11 | |.........wfUD3".|
   +------------------------------------------------+ +----------------+
CIPHER
   +------------------------------------------------+ +----------------+
   |.0 .1 .2 .3 .4 .5 .6 .7 .8 .9 .a .b .c .d .e .f | |      ASCII     |
   +------------------------------------------------+ +----------------+
 0.|cd ed d4 b9 42 8d 46 5a 30 24 bc be 90 9d 67 7f | |....B.FZ0$....g|
   +------------------------------------------------+ +----------------+
DECIPHERED
   +------------------------------------------------+ +----------------+
   |.0 .1 .2 .3 .4 .5 .6 .7 .8 .9 .a .b .c .d .e .f | |      ASCII     |
   +------------------------------------------------+ +----------------+
 0.|88 99 aa bb cc dd ee ff 00 77 66 55 44 33 22 11 | |.........wfUD3".|
   +------------------------------------------------+ +----------------+
    [√] Output is correct!

cd Python ; ./Test.py
Init
   +------------------------------------------------+ +----------------+
   |.0 .1 .2 .3 .4 .5 .6 .7 .8 .9 .a .b .c .d .e .f | |      ASCII     |
   +------------------------------------------------+ +----------------+
00.|88 99 aa bb cc dd ee ff 00 77 66 55 44 33 22 11 | |.........wfUD3".|
   +------------------------------------------------+ +----------------+
Encrypt
   +------------------------------------------------+ +----------------+
   |.0 .1 .2 .3 .4 .5 .6 .7 .8 .9 .a .b .c .d .e .f | |      ASCII     |
   +------------------------------------------------+ +----------------+
00.|cd ed d4 b9 42 8d 46 5a 30 24 bc be 90 9d 67 7f | |....B.FZ0$....g.|
   +------------------------------------------------+ +----------------+
    Output is correct!
Decrypt
   +------------------------------------------------+ +----------------+
   |.0 .1 .2 .3 .4 .5 .6 .7 .8 .9 .a .b .c .d .e .f | |      ASCII     |
   +------------------------------------------------+ +----------------+
00.|88 99 aa bb cc dd ee ff 00 77 66 55 44 33 22 11 | |.........wfUD3".|
   +------------------------------------------------+ +----------------+
    Output is correct!
```
