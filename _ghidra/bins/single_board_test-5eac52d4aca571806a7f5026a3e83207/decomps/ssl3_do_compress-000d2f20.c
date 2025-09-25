
bool ssl3_do_compress(int param_1,int param_2)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 uVar2;
  bool bVar3;
  
  iVar1 = COMP_compress_block(*(COMP_CTX **)(param_1 + 0x3e4),*(uchar **)(param_2 + 0x14),
                              *(int *)(param_2 + 8) + 0x400,*(uchar **)(param_2 + 0x18),
                              *(int *)(param_2 + 8));
  bVar3 = -1 < iVar1;
  uVar2 = extraout_r2;
  if (bVar3) {
    uVar2 = *(undefined4 *)(param_2 + 0x14);
  }
  if (bVar3) {
    *(int *)(param_2 + 8) = iVar1;
  }
  if (bVar3) {
    *(undefined4 *)(param_2 + 0x18) = uVar2;
  }
  return bVar3;
}

