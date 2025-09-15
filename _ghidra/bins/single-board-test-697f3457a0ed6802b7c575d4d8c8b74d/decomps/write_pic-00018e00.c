
void write_pic(uchar which_i2c,uchar which_chain,uchar data)

{
  uchar data_local;
  uchar which_chain_local;
  uchar which_i2c_local;
  uint config_data;
  
  i2c_write((uint)data | (uint)which_i2c << 0x1a | 0xa00000 | (uint)which_chain << 0x10);
  return;
}

