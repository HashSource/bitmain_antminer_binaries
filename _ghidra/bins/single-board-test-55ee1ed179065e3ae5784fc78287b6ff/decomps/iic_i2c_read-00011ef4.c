
undefined4 iic_i2c_read(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = iic_read(i2c_fd,param_1,param_2);
  return uVar1;
}

