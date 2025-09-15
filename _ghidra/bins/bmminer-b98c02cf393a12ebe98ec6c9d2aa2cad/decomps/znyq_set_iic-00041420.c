
void znyq_set_iic(uint param_1,uint param_2,int param_3,int param_4,byte param_5,byte param_6)

{
  uint uVar1;
  
  if (param_3 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x2000000;
  }
  if (param_4 != 0) {
    uVar1 = uVar1 | (uint)param_5 << 8 | 0x1000000;
  }
  set_iic((uint)param_6 | (param_1 & 7) << 0x10 | (param_2 & 3) << 0x1a |
          ((param_1 << 0x19) >> 0x1c) << 0x14 | uVar1);
  return;
}

