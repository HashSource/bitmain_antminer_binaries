
undefined4 uint32_i2c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  bool bVar4;
  
  iVar1 = *(int *)*param_1;
  if (((int)(*(uint *)(param_4 + 0x14) << 0x1f) < 0) && (iVar1 == 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar3 = *(uint *)(param_4 + 0x14) & 2;
    if (uVar3 != 0) {
      bVar4 = iVar1 < 0;
      if (bVar4) {
        iVar1 = -iVar1;
      }
      uVar3 = (uint)bVar4;
    }
    uVar2 = i2c_uint64_int(param_2,param_2,iVar1,0,uVar3);
  }
  return uVar2;
}

