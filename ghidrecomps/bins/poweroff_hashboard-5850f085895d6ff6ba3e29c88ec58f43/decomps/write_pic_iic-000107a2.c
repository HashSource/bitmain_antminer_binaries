
undefined4 write_pic_iic(byte param_1,undefined param_2)

{
  undefined4 uVar1;
  byte local_11;
  
  if (param_1 == 1) {
    local_11 = 2;
  }
  else {
    local_11 = param_1;
    if (param_1 == 2) {
      local_11 = 1;
    }
  }
  uVar1 = zynq_set_iic(local_11 & 7 | 0x20,0,0,0,0,param_2);
  return uVar1;
}

