
void gost_init(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = 0;
  if (param_2 == 0) {
    param_2 = DAT_00114388;
  }
  do {
    iVar4 = (int)uVar2 >> 4;
    iVar1 = param_2 + (uVar2 & 0xf);
    iVar3 = param_2 + iVar4;
    uVar2 = uVar2 + 1;
    *(uint *)(param_1 + 0x20) =
         ((uint)*(byte *)(iVar1 + 0x10) | (uint)*(byte *)(param_2 + iVar4) << 4) << 0x18;
    *(uint *)(param_1 + 0x420) =
         ((uint)*(byte *)(iVar1 + 0x30) | (uint)*(byte *)(iVar3 + 0x20) << 4) << 0x10;
    *(uint *)(param_1 + 0x820) =
         ((uint)*(byte *)(iVar1 + 0x50) | (uint)*(byte *)(iVar3 + 0x40) << 4) << 8;
    *(uint *)(param_1 + 0xc20) = (uint)*(byte *)(iVar1 + 0x70) | (uint)*(byte *)(iVar3 + 0x60) << 4;
    param_1 = param_1 + 4;
  } while (uVar2 != 0x100);
  return;
}

