
undefined write_pic_iic(char param_1,char param_2,byte param_3,byte param_4,byte param_5)

{
  undefined uVar1;
  uint local_14;
  
  local_14 = 0;
  if (param_1 != '\0') {
    local_14 = 0x2000000;
  }
  if (param_2 != '\0') {
    local_14 = local_14 | 0x1000000 | (uint)param_3 << 8;
  }
  uVar1 = set_pic_iic((uint)param_5 | local_14 | 0x400000 | (param_4 & 0xf) << 0x10);
  return uVar1;
}

