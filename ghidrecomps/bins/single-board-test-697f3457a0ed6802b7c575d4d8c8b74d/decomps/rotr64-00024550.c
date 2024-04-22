
uint64_t rotr64(uint64_t w,uint c)

{
  uint in_r1;
  uint in_r2;
  uint uVar1;
  uint c_local;
  uint64_t w_local;
  
  uVar1 = -in_r2 & 0x3f;
  return CONCAT44(in_r1 << uVar1 | c << (uVar1 - 0x20 & 0xff) | c >> (0x20 - uVar1 & 0xff) |
                  in_r1 >> (in_r2 & 0xff),
                  c << uVar1 |
                  c >> (in_r2 & 0xff) | in_r1 << (0x20 - in_r2 & 0xff) |
                  in_r1 >> (in_r2 - 0x20 & 0xff));
}

