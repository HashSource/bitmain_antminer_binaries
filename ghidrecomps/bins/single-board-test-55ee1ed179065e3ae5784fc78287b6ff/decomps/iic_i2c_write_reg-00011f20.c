
undefined4 iic_i2c_write_reg(undefined param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined local_9;
  
  local_9 = param_1;
  uVar1 = iic_write_reg(power_fd,&local_9,1,param_2,param_3);
  return uVar1;
}

