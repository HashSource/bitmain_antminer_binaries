
uint32_t swab32(uint32_t v)

{
  uint32_t v_local;
  
  return v << 0x18 | (v >> 8 & 0xff) << 0x10 | (v >> 0x10 & 0xff) << 8 | v >> 0x18;
}

