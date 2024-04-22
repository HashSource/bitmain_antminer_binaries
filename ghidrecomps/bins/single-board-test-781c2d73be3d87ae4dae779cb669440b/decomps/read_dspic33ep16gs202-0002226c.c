
/* WARNING: Unknown calling convention */

uchar read_dspic33ep16gs202(uchar which_i2c,uchar which_chain)

{
  uchar uVar1;
  
  uVar1 = i2c_read((uint)which_chain << 0x10 | 0x400000 | (uint)which_i2c << 0x1a);
  return uVar1;
}

