
void send_work_example(void)

{
  undefined auStack_240 [140];
  undefined auStack_1b4 [2];
  byte local_1b2;
  undefined local_1b1;
  undefined auStack_1b0 [144];
  undefined auStack_120 [280];
  
  memcpy(auStack_120,
         "040000005a0995c5fe39ee678b290a2636ec3c32e26bfafb5711ee687ad3750e00000000bbd08c45cf29d96c4f1e5b9d136f2f0ffc22d6be511e204773afee519a2478db00000000000000000000000000000000000000000000000000000000000000008dc7205ab0f0131c0000000000000000aaaaaaaa27c5d2a66bda09d1000000000000000000000000"
         ,0x118);
  local_1b2 = local_1b2 & 0xee;
  local_1b1 = 0;
  memset(auStack_240,0,0x8c);
  hex2bin(auStack_240,auStack_120,0x8c);
  memcpy(auStack_1b0,auStack_240,0x8c);
  memcpy(g_test_header,auStack_240,0x8c);
  midd_send_work_to_hardware(g_chain._0_4_,auStack_1b4,0x92);
  return;
}

