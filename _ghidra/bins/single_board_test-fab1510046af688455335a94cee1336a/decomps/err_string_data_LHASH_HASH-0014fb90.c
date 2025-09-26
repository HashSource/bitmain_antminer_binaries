
uint err_string_data_LHASH_HASH(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  uVar1 = (uVar1 << 8) >> 0x14 ^ uVar1 ^ uVar1 >> 0x18;
  return uVar1 ^ (uVar1 % 0x13) * 0xd;
}

