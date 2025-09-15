
undefined4
dump_indent(uint param_1,int param_2,int param_3,code *UNRECOVERED_JUMPTABLE,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_1 & 0x1f) == 0) {
    if ((param_3 != 0) && (-1 < (int)(param_1 << 0x1a))) {
                    /* WARNING: Could not recover jumptable at 0x0004ee64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(" ",1,param_5);
      return uVar2;
    }
  }
  else {
    uVar3 = (param_1 & 0x1f) * param_2;
    iVar1 = (*UNRECOVERED_JUMPTABLE)(&DAT_00065a34,1,param_5);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    for (; uVar3 != 0; uVar3 = uVar3 - uVar4) {
      uVar4 = uVar3;
      if (0x1f < uVar3) {
        uVar4 = 0x20;
      }
      iVar1 = (*UNRECOVERED_JUMPTABLE)("                                ",uVar4,param_5);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
    }
  }
  return 0;
}

