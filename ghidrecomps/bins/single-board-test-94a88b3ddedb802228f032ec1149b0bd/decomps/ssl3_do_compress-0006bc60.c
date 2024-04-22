
int ssl3_do_compress(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  bool bVar5;
  
  iVar4 = *(int *)(param_1 + 0x58);
  uVar3 = 0x4400;
  iVar1 = COMP_compress_block(*(COMP_CTX **)(param_1 + 0x94),*(uchar **)(iVar4 + 0x13c),0x4400,
                              *(uchar **)(iVar4 + 0x140),*(int *)(iVar4 + 0x134));
  bVar5 = -1 < iVar1;
  iVar2 = iVar1;
  if (bVar5) {
    uVar3 = *(undefined4 *)(iVar4 + 0x13c);
    iVar2 = 1;
  }
  if (bVar5) {
    *(int *)(iVar4 + 0x134) = iVar1;
  }
  else {
    iVar2 = 0;
  }
  if (bVar5) {
    *(undefined4 *)(iVar4 + 0x140) = uVar3;
  }
  return iVar2;
}

