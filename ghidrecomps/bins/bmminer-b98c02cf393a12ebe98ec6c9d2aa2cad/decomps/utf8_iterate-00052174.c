
byte * utf8_iterate(byte *param_1,int param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  uint local_14;
  
  if (param_2 == 0) {
    return param_1;
  }
  uVar3 = (uint)*param_1;
  uVar4 = utf8_check_first(uVar3);
  uVar1 = (uint)uVar4;
  if ((uVar1 != 0) &&
     ((uVar1 == 1 ||
      ((uVar1 <= (uint)((ulonglong)uVar4 >> 0x20) &&
       (iVar2 = utf8_check_full(param_1,uVar1,&local_14), uVar3 = local_14, iVar2 != 0)))))) {
    local_14 = uVar3;
    if (param_3 != (uint *)0x0) {
      *param_3 = local_14;
    }
    return param_1 + uVar1;
  }
  return (byte *)0x0;
}

