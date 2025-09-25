
uint32_t bswap_32(uint32_t in)

{
  uint32_t in_local;
  
  return in << 0x18 | in >> 0x18 | in >> 8 & 0xff00 | (in & 0xff00) << 8;
}

