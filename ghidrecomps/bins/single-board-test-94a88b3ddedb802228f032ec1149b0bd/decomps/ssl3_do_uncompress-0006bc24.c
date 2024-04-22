
int ssl3_do_uncompress(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  bool bVar5;
  
  iVar4 = *(int *)(param_1 + 0x58);
  uVar3 = 0x4000;
  iVar1 = COMP_expand_block(*(COMP_CTX **)(param_1 + 0x88),*(uchar **)(iVar4 + 0x120),0x4000,
                            *(uchar **)(iVar4 + 0x118),*(int *)(iVar4 + 0x110));
  bVar5 = -1 < iVar1;
  iVar2 = iVar1;
  if (bVar5) {
    uVar3 = *(undefined4 *)(iVar4 + 0x120);
    iVar2 = 1;
  }
  if (bVar5) {
    *(int *)(iVar4 + 0x110) = iVar1;
  }
  else {
    iVar2 = 0;
  }
  if (bVar5) {
    *(undefined4 *)(iVar4 + 0x118) = uVar3;
  }
  return iVar2;
}

