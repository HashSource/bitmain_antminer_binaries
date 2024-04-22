
/* WARNING: Unknown calling convention */

uchar read_pic1704(uchar which_i2c,uchar which_chain)

{
  uchar uVar1;
  
  uVar1 = i2c_read((uint)which_chain << 0x10 | 0xa00000 | (uint)which_i2c << 0x1a);
  return uVar1;
}

