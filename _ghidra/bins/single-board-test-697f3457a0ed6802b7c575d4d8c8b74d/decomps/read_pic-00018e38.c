
uchar read_pic(uchar which_i2c,uchar which_chain)

{
  uchar uVar1;
  uchar which_chain_local;
  uchar which_i2c_local;
  uint config_data;
  
  uVar1 = i2c_read((uint)which_chain << 0x10 | (uint)which_i2c << 0x1a | 0xa00000);
  return uVar1;
}

