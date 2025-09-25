
undefined4 uint64_i2c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  iVar1 = *(int *)*param_1;
  iVar3 = ((int *)*param_1)[1];
  if (((int)(*(uint *)(param_4 + 0x14) << 0x1f) < 0) && (iVar1 == 0 && iVar3 == 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar4 = *(uint *)(param_4 + 0x14) & 2;
    iVar5 = iVar3;
    if (uVar4 != 0) {
      if (iVar3 < 0) {
        bVar6 = iVar1 != 0;
        iVar1 = -iVar1;
        uVar4 = 1;
        iVar5 = -iVar3 - (uint)bVar6;
      }
      else {
        uVar4 = 0;
      }
    }
    uVar2 = i2c_uint64_int(param_2,iVar3,iVar1,iVar5,uVar4);
  }
  return uVar2;
}

