
uint sph_bswap32(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 >> 0x10 | param_1 << 0x10;
  return (uVar1 & 0xff00ff) << 8 | (uVar1 & 0xff00ff00) >> 8;
}

