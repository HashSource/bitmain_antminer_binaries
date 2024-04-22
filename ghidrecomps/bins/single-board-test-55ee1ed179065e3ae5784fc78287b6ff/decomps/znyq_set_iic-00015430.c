
byte znyq_set_iic(undefined4 param_1,undefined4 param_2,char param_3,undefined4 param_4,
                 undefined param_5)

{
  byte local_9;
  
  if (param_3 == '\0') {
    local_9 = iic_i2c_write_reg(param_5,&stack0x00000004,1);
  }
  else {
    iic_i2c_read_reg(param_5,&local_9,1);
  }
  return local_9;
}

