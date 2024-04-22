
undefined4
zynq_set_iic(byte param_1,byte param_2,char param_3,char param_4,byte param_5,byte param_6)

{
  undefined4 uVar1;
  uint local_14;
  
  local_14 = 0;
  if (param_3 != '\0') {
    local_14 = 0x2000000;
  }
  if (param_4 != '\0') {
    local_14 = local_14 | (uint)param_5 << 8 | 0x1000000;
  }
  uVar1 = set_iic((uint)param_6 |
                  (param_1 & 7) << 0x10 |
                  (param_1 >> 3 & 0xf) << 0x14 | (param_2 & 3) << 0x1a | local_14);
  return uVar1;
}

