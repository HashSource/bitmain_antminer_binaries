
undefined8 sph_bswap64(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (DAT_000160e0 & param_2) >> 0x10 | (DAT_000160e4 & param_1) << 0x10 | param_2 << 0x10;
  uVar2 = (DAT_000160e4 & param_1) >> 0x10 | param_1 << 0x10;
  return CONCAT44((uVar2 & 0xff00ff) << 8 | (uVar2 & 0xff00ff00) >> 8,
                  (uVar1 & 0xff00ff) << 8 | (uVar1 & 0xff00ff00) >> 8);
}

