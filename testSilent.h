#ifndef TEST_H
#define TEST_H

static const unsigned char test_key[32] = {
  0xef, 0xcd, 0xab, 0x89, 0x67, 0x45, 0x23, 0x01,
  0x10, 0x32, 0x54, 0x76, 0x98, 0xba, 0xdc, 0xfe,
  0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x00,
  0xff, 0xee, 0xdd, 0xcc, 0xbb, 0xaa, 0x99, 0x88
};

static const unsigned char encrypt_test_string[] = {
  0xaa, 0x70, 0xcc, 0x93, 0xa8, 0xbd, 0x6d, 0x0b, 0xc2, 0xd5, 0x8d, 0x05, 0x5c, 0xba, 0xdb, 0x51, 
  0x04, 0x52, 0x7d, 0x2e, 0x79, 0x59, 0x51, 0x2d, 0x13, 0x40, 0x0f, 0x06, 0xd3, 0x5f, 0x55, 0x08, 
  0xf0, 0x9f, 0x45, 0xb1, 0x61, 0xe1, 0x4b, 0x5d, 0x16, 0xda, 0x78, 0x9f, 0xfb, 0x13, 0x3a, 0x1e, 
  0x89, 0x8f, 0x1b, 0x15, 0xc1, 0x46, 0x8d, 0xbe, 0x8e, 0xb6, 0x6a, 0x2d, 0xca, 0xac, 0x00, 0xe0, 
  0xc4, 0x73, 0x04, 0xa8, 0x27, 0x39, 0xae, 0x16, 0xec, 0x93, 0x6d, 0xbc, 0x16, 0x80, 0x7d, 0xd9, 
  0x1e, 0xa5, 0x1f, 0x60, 0xd8, 0xc4, 0x0a, 0x2f, 0x9a, 0x3c, 0xc1, 0x5b, 0xe7, 0xb2, 0x19, 0xd0, 
  0xb6, 0x08, 0xd1, 0x1d, 0xa1, 0x01, 0x29, 0xd3, 0x7d, 0x2c, 0x6c, 0x4d, 0xb8, 0xb8, 0xeb, 0x42, 
  0x7c, 0x9e, 0x56, 0xe2, 0xc5, 0x54, 0x3b, 0xfc, 0xfa, 0xa1, 0x08, 0xb9, 0xcc, 0x8b, 0xf7, 0xd3, 
  0x6a, 0x94, 0x30, 0xc3, 0xd7, 0xa3, 0x43, 0xb2, 0x10, 0xa2, 0x33, 0x1b, 0x53, 0xb1, 0xe0, 0xc7, 
  0x1e, 0xbc, 0x6d, 0xa5, 0x76, 0xb8, 0x44, 0x09, 0xd6, 0x37, 0x28, 0x83, 0x51, 0x65, 0x78, 0x1e, 
  0x7d, 0x14, 0xa2, 0x9c, 0x9d, 0x51, 0x2c, 0x48, 0x3a, 0xe8, 0x6a, 0x40, 0xab, 0xe6, 0xb6, 0x73, 
  0xf7, 0x4b, 0x5a, 0x6c, 0x1c, 0xac, 0x2e, 0xa4, 0x07, 0x23, 0xd3, 0xef, 0x64, 0x84, 0x24, 0xbe, 
  0xd2, 0x74, 0x51, 0xa3, 0x63, 0x59, 0xd7, 0x1e, 0x05, 0x82, 0x85, 0x52, 0x50, 0x95, 0xe4, 0xb8, 
  0x91, 0xc8, 0x8c, 0xcf, 0x5a, 0x4e, 0xfc, 0xdc, 0xe8, 0x35, 0x0a, 0x21, 0x21, 0x44, 0xfa, 0x96, 
  0xcf, 0x2d, 0xf3, 0xa4, 0xab, 0xdc, 0xa1, 0x55, 0x51, 0xa9, 0x6b, 0xaa, 0x4b, 0xd2, 0x8b, 0x4a, 
  0x40, 0xcf, 0xe0, 0x9d, 0xc2, 0x1b, 0x8e, 0x8d, 0x9a, 0x2d, 0x12, 0xfa, 0x9c, 0xd6, 0x45, 0x89, 
  0xe1, 0x46, 0xfd, 0x4c, 0x83, 0x1e, 0x0b, 0x79, 0x4f, 0x88, 0x43, 0x2a, 0x15, 0xc9, 0x22, 0x01, 
  0x76, 0xee, 0x54, 0x4f, 0x0b, 0x27, 0x96, 0xeb, 0xae, 0xa7, 0x65, 0x3a, 0xbf, 0x10, 0x66, 0xf1, 
  0x92, 0x6c, 0x7f, 0x7b, 0xdb, 0xcb, 0xc6, 0x2b, 0xba, 0x45, 0x61, 0x5e, 0x1b, 0xf4, 0x6b, 0xba, 
  0x4c, 0x92, 0x64, 0x01, 0x37, 0x09, 0xab, 0x95, 0xdf, 0x1d, 0x73, 0x17, 0x49, 0xd4, 0x99, 0xcb, 
  0x2d, 0x56, 0x08, 0x0b, 0xa4, 0x8b, 0xcd, 0xc5, 0x55, 0x5d, 0x7a, 0x60, 0x27, 0x30, 0x76, 0xb7, 
  0xd1, 0xbb, 0xe4, 0x20, 0xdb, 0x03, 0xff, 0x98, 0x07, 0x5c, 0x70, 0x2a, 0x85, 0x4c, 0x9c, 0x41, 
  0xde, 0x8d, 0xc0, 0x7c, 0xeb, 0x58, 0xa6, 0x74, 0xed, 0x7a, 0xeb, 0x0f, 0x59, 0x50, 0x8c, 0x83, 
  0x6d, 0xc9, 0xcc, 0xdb, 0xbc, 0x3a, 0x82, 0xd2, 0xde, 0x29, 0x93, 0x11, 0xef, 0xc6, 0x63, 0xb7, 
};

static const unsigned char decrypt_test_string[384] = {
  0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 
  0xfc, 0xee, 0xdd, 0x11, 0xcf, 0x6e, 0x31, 0x16, 0xfb, 0xc4, 0xfa, 0xda, 0x23, 0xc5, 0x04, 0x4d, 
  0xe9, 0x77, 0xf0, 0xdb, 0x93, 0x2e, 0x99, 0xba, 0x17, 0x36, 0xf1, 0xbb, 0x14, 0xcd, 0x5f, 0xc1, 
  0xf9, 0x18, 0x65, 0x5a, 0xe2, 0x5c, 0xef, 0x21, 0x81, 0x1c, 0x3c, 0x42, 0x8b, 0x01, 0x8e, 0x4f, 
  0x05, 0x84, 0x02, 0xae, 0xe3, 0x6a, 0x8f, 0xa0, 0x06, 0x0b, 0xed, 0x98, 0x7f, 0xd4, 0xd3, 0x1f, 
  0xeb, 0x34, 0x2c, 0x51, 0xea, 0xc8, 0x48, 0xab, 0xf2, 0x2a, 0x68, 0xa2, 0xfd, 0x3a, 0xce, 0xcc, 
  0xb5, 0x70, 0x0e, 0x56, 0x08, 0x0c, 0x76, 0x12, 0xbf, 0x72, 0x13, 0x47, 0x9c, 0xb7, 0x5d, 0x87, 
  0x15, 0xa1, 0x96, 0x29, 0x10, 0x7b, 0x9a, 0xc7, 0xf3, 0x91, 0x78, 0x6f, 0x9d, 0x9e, 0xb2, 0xb1, 
  0x32, 0x75, 0x19, 0x3d, 0xff, 0x35, 0x8a, 0x7e, 0x6d, 0x54, 0xc6, 0x80, 0xc3, 0xbd, 0x0d, 0x57, 
  0xdf, 0xf5, 0x24, 0xa9, 0x3e, 0xa8, 0x43, 0xc9, 0xd7, 0x79, 0xd6, 0xf6, 0x7c, 0x22, 0xb9, 0x03, 
  0xe0, 0x0f, 0xec, 0xde, 0x7a, 0x94, 0xb0, 0xbc, 0xdc, 0xe8, 0x28, 0x50, 0x4e, 0x33, 0x0a, 0x4a, 
  0xa7, 0x97, 0x60, 0x73, 0x1e, 0x00, 0x62, 0x44, 0x1a, 0xb8, 0x38, 0x82, 0x64, 0x9f, 0x26, 0x41, 
  0xad, 0x45, 0x46, 0x92, 0x27, 0x5e, 0x55, 0x2f, 0x8c, 0xa3, 0xa5, 0x7d, 0x69, 0xd5, 0x95, 0x3b, 
  0x07, 0x58, 0xb3, 0x40, 0x86, 0xac, 0x1d, 0xf7, 0x30, 0x37, 0x6b, 0xe4, 0x88, 0xd9, 0xe7, 0x89, 
  0xe1, 0x1b, 0x83, 0x49, 0x4c, 0x3f, 0xf8, 0xfe, 0x8d, 0x53, 0xaa, 0x90, 0xca, 0xd8, 0x85, 0x61, 
  0x20, 0x71, 0x67, 0xa4, 0x2d, 0x2b, 0x09, 0x5b, 0xcb, 0x9b, 0x25, 0xd0, 0xbe, 0xe5, 0x6c, 0x52, 
  0x59, 0xa6, 0x74, 0xd2, 0xe6, 0xf4, 0xb4, 0xc0, 0xd1, 0x66, 0xaf, 0xc2, 0x39, 0x4b, 0x63, 0xb6, 
  0xa5, 0x2d, 0x32, 0x8f, 0x0e, 0x30, 0x38, 0xc0, 0x54, 0xe6, 0x9e, 0x39, 0x55, 0x7e, 0x52, 0x91, 
  0x64, 0x03, 0x57, 0x5a, 0x1c, 0x60, 0x07, 0x18, 0x21, 0x72, 0xa8, 0xd1, 0x29, 0xc6, 0xa4, 0x3f, 
  0xe0, 0x27, 0x8d, 0x0c, 0x82, 0xea, 0xae, 0xb4, 0x9a, 0x63, 0x49, 0xe5, 0x42, 0xe4, 0x15, 0xb7, 
  0xc8, 0x06, 0x70, 0x9d, 0x41, 0x75, 0x19, 0xc9, 0xaa, 0xfc, 0x4d, 0xbf, 0x2a, 0x73, 0x84, 0xd5, 
  0xc3, 0xaf, 0x2b, 0x86, 0xa7, 0xb1, 0xb2, 0x5b, 0x46, 0xd3, 0x9f, 0xfd, 0xd4, 0x0f, 0x9c, 0x2f, 
  0x9b, 0x43, 0xef, 0xd9, 0x79, 0xb6, 0x53, 0x7f, 0xc1, 0xf0, 0x23, 0xe7, 0x25, 0x5e, 0xb5, 0x1e, 
  0xa2, 0xdf, 0xa6, 0xfe, 0xac, 0x22, 0xf9, 0xe2, 0x4a, 0xbc, 0x35, 0xca, 0xee, 0x78, 0x05, 0x6b, 
}
#endif  // TEST_H

