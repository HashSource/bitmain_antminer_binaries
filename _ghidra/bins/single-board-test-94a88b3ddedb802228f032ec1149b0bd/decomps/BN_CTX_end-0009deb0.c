
void BN_CTX_end(BN_CTX *ctx)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(int *)(ctx + 0x24) == 0) {
    iVar1 = *(int *)(ctx + 0x18);
    *(int *)(ctx + 0x18) = iVar1 + -1;
    uVar3 = *(uint *)(*(int *)(ctx + 0x14) + (iVar1 + -1) * 4);
    if (uVar3 < *(uint *)(ctx + 0x20)) {
      iVar1 = *(uint *)(ctx + 0x20) - uVar3;
      uVar2 = *(int *)(ctx + 0xc) - 1U & 0xf;
      *(int *)(ctx + 0xc) = *(int *)(ctx + 0xc) - iVar1;
      while (iVar1 != 0) {
        while (iVar1 = iVar1 + -1, uVar2 == 0) {
          uVar2 = 0xf;
          *(undefined4 *)(ctx + 4) = *(undefined4 *)(*(int *)(ctx + 4) + 0x140);
          if (iVar1 == 0) goto LAB_0009def2;
        }
        uVar2 = uVar2 - 1;
      }
    }
LAB_0009def2:
    *(uint *)(ctx + 0x20) = uVar3;
    *(undefined4 *)(ctx + 0x28) = 0;
  }
  else {
    *(int *)(ctx + 0x24) = *(int *)(ctx + 0x24) + -1;
  }
  return;
}

