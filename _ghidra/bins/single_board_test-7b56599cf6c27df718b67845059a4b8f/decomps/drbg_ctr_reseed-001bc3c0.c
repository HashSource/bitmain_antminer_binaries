
int drbg_ctr_reseed(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_2 != 0) {
    uVar3 = *(byte *)(param_1 + 0xab) + 1;
    *(char *)(param_1 + 0xab) = (char)uVar3;
    uVar2 = (uint)*(byte *)(param_1 + 0xaa) + (uVar3 >> 8);
    uVar3 = (uint)*(byte *)(param_1 + 0xa9) + (uVar2 >> 8);
    *(char *)(param_1 + 0xaa) = (char)uVar2;
    uVar2 = (uint)*(byte *)(param_1 + 0xa8) + (uVar3 >> 8);
    *(char *)(param_1 + 0xa9) = (char)uVar3;
    uVar3 = (uint)*(byte *)(param_1 + 0xa7) + (uVar2 >> 8);
    *(char *)(param_1 + 0xa8) = (char)uVar2;
    uVar2 = (uint)*(byte *)(param_1 + 0xa6) + (uVar3 >> 8);
    *(char *)(param_1 + 0xa7) = (char)uVar3;
    uVar3 = (uint)*(byte *)(param_1 + 0xa5) + (uVar2 >> 8);
    *(char *)(param_1 + 0xa6) = (char)uVar2;
    uVar2 = (uint)*(byte *)(param_1 + 0xa4) + (uVar3 >> 8);
    *(char *)(param_1 + 0xa5) = (char)uVar3;
    uVar3 = (uint)*(byte *)(param_1 + 0xa3) + (uVar2 >> 8);
    *(char *)(param_1 + 0xa4) = (char)uVar2;
    uVar2 = (uint)*(byte *)(param_1 + 0xa2) + (uVar3 >> 8);
    *(char *)(param_1 + 0xa3) = (char)uVar3;
    uVar3 = (uint)*(byte *)(param_1 + 0xa1) + (uVar2 >> 8);
    *(char *)(param_1 + 0xa2) = (char)uVar2;
    uVar4 = (uint)*(byte *)(param_1 + 0xa0) + (uVar3 >> 8);
    *(char *)(param_1 + 0xa1) = (char)uVar3;
    uVar2 = (uint)*(byte *)(param_1 + 0x9f) + (uVar4 >> 8);
    *(char *)(param_1 + 0xa0) = (char)uVar4;
    uVar3 = (uint)*(byte *)(param_1 + 0x9e) + (uVar2 >> 8);
    *(char *)(param_1 + 0x9f) = (char)uVar2;
    iVar1 = (uint)*(byte *)(param_1 + 0x9d) + (uVar3 >> 8);
    *(char *)(param_1 + 0x9e) = (char)uVar3;
    *(char *)(param_1 + 0x9d) = (char)iVar1;
    *(char *)(param_1 + 0x9c) = *(char *)(param_1 + 0x9c) + (char)((uint)iVar1 >> 8);
    iVar1 = ctr_update();
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  return 0;
}

