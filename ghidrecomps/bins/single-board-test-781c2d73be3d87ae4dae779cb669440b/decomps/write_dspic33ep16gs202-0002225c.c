
/* WARNING: Unknown calling convention */

void write_dspic33ep16gs202(uchar which_i2c,uchar which_chain,uchar data)

{
  i2c_write(data | 0x400000 | (uint)which_chain << 0x10 | (uint)which_i2c << 0x1a);
  return;
}

