
uint __bswap_32(uint __bsx)

{
  uint __bsx_local;
  
  return __bsx << 0x18 | (__bsx >> 8 & 0xff) << 0x10 | (__bsx >> 0x10 & 0xff) << 8 | __bsx >> 0x18;
}

