
void write_pic(byte param_1,byte param_2,byte param_3)

{
  i2c_write((uint)param_3 | (uint)param_1 << 0x1a | 0xa00000 | (uint)param_2 << 0x10);
  return;
}

