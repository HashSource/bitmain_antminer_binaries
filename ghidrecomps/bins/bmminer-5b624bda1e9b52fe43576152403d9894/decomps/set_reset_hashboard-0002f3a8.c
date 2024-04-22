
/* WARNING: Unknown calling convention */

void set_reset_hashboard(int chainIndex,int resetBit)

{
  int iVar1;
  uint uVar2;
  uint resetFlag;
  uint uVar3;
  uint ret;
  char logstr [256];
  
  iVar1 = DAT_0002f3e0;
  uVar2 = 1 << (chainIndex & 0xffU);
  uVar3 = *(uint *)(*(int *)(DAT_0002f3e0 + 0x8d4) + 0x34);
  if (resetBit < 1) {
    uVar2 = uVar3 & ~uVar2;
  }
  else {
    uVar2 = uVar2 | uVar3;
  }
  sprintf(logstr,DAT_0002f3e4,uVar2);
  writeInitLogFile(logstr);
  *(uint *)(*(int *)(iVar1 + 0x8d4) + 0x34) = uVar2;
  return;
}

