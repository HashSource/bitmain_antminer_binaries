
/* WARNING: Unknown calling convention */

void write_pic1704(uchar which_i2c,uchar which_chain,uchar data)

{
  i2c_write(data | 0xa00000 | (uint)which_chain << 0x10 | (uint)which_i2c << 0x1a);
  return;
}

