
/* WARNING: Unknown calling convention */

uint32_t swab32(uint32_t v)

{
  return v << 0x18 | (v >> 8 & 0xff) << 0x10 | (v >> 0x10 & 0xff) << 8 | v >> 0x18;
}

