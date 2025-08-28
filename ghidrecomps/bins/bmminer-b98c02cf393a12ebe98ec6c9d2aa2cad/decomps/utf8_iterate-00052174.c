
undefined1 * utf8_iterate(undefined1 *param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_r2;
  undefined8 uVar4;
  undefined4 local_14;
  
  if (param_2 == 0) {
    return param_1;
  }
  uVar4 = utf8_check_first(*param_1);
  uVar2 = (uint)uVar4;
  if ((uVar2 != 0) &&
     ((uVar1 = extraout_r2, uVar2 == 1 ||
      ((uVar2 <= (uint)((ulonglong)uVar4 >> 0x20) &&
       (iVar3 = utf8_check_full(param_1,uVar2,&local_14), uVar1 = local_14, iVar3 != 0)))))) {
    local_14 = uVar1;
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = local_14;
    }
    return param_1 + uVar2;
  }
  return (undefined1 *)0x0;
}

