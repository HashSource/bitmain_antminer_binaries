
undefined4 read_pic(byte param_1,byte param_2)

{
  undefined4 uVar1;
  
  uVar1 = i2c_read((uint)param_2 << 0x10 | (uint)param_1 << 0x1a | 0xa00000);
  return uVar1;
}

