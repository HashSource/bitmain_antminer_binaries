
uint real_mask(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  uVar4 = 0;
  uVar3 = 0;
  do {
    uVar2 = uVar4 & 0xff;
    uVar1 = uVar4 & 0xff;
    uVar4 = uVar4 + 1;
    if ((param_1 >> uVar2 & 1) != 0) {
      iVar5 = iVar5 + 1;
      uVar3 = uVar3 | 1 << uVar1;
      if (iVar5 == param_2) {
        return uVar3;
      }
    }
  } while (uVar4 != 0x20);
  return uVar3;
}

