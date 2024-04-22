
undefined4 dump_indent(uint param_1,int param_2,int param_3,code *param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  
  if ((param_1 & 0x1f) == 0) {
    if ((param_3 != 0) && ((param_1 & 0x20) == 0)) {
      uVar2 = (*param_4)(&DAT_0002ce04,1,param_5);
      return uVar2;
    }
  }
  else {
    iVar1 = (*param_4)(&DAT_0002ce00,1,param_5);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    for (local_c = 0; local_c < param_2; local_c = local_c + 1) {
      iVar1 = (*param_4)("                                ",param_1 & 0x1f,param_5);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
    }
  }
  return 0;
}

