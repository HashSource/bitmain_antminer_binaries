
/* WARNING: Unknown calling convention */

void set_reset_allhashboard(int resetBit)

{
  int iVar1;
  uint uVar2;
  uint ret;
  char logstr [256];
  
  iVar1 = DAT_0002f3a0;
  uVar2 = *(uint *)(*(int *)(DAT_0002f3a0 + 0x8d4) + 0x34);
  if (resetBit < 1) {
    uVar2 = uVar2 >> 0x10;
  }
  else {
    uVar2 = ~(uVar2 >> 0x10);
  }
  if (resetBit < 1) {
    uVar2 = uVar2 << 0x10;
  }
  else {
    uVar2 = ~(uVar2 << 0x10);
  }
  sprintf(logstr,DAT_0002f3a4,uVar2);
  writeInitLogFile(logstr);
  *(uint *)(*(int *)(iVar1 + 0x8d4) + 0x34) = uVar2;
  return;
}

