
undefined4 read_pic_iic(byte param_1)

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
  uVar1 = zynq_set_iic(local_11 & 7 | 0x20,0,1,0,0,0);
  return uVar1;
}

