
int mem_LHASH_HASH(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  return uVar1 * 0x45bb + (uVar1 >> 0xe) * 7 + (uVar1 >> 4) * 0xfb;
}

