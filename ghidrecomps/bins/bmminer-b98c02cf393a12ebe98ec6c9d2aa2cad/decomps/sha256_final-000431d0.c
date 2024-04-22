
void sha256_final(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  bool bVar10;
  
  uVar2 = param_1[1];
  piVar4 = param_1 + 2;
  bVar10 = (uVar2 & 0x3f) < 0x38;
  if (bVar10) {
    iVar1 = 0x40;
  }
  else {
    iVar1 = 0x80;
  }
  if (bVar10) {
    iVar3 = 0x3c;
    iVar6 = 0x3d;
    iVar7 = 0x3e;
    iVar8 = 0x3f;
    uVar9 = 1;
  }
  else {
    iVar3 = 0x7c;
    iVar6 = 0x7d;
    iVar7 = 0x7e;
    iVar8 = 0x7f;
    uVar9 = 2;
  }
  iVar5 = (*param_1 + uVar2) * 8;
  memset((void *)((int)piVar4 + uVar2),0,iVar1 - uVar2);
  *(undefined *)((int)param_1 + param_1[1] + 8) = 0x80;
  *(char *)((int)piVar4 + iVar8) = (char)iVar5;
  *(char *)((int)piVar4 + iVar7) = (char)((uint)iVar5 >> 8);
  *(char *)((int)piVar4 + iVar6) = (char)((uint)iVar5 >> 0x10);
  *(char *)((int)piVar4 + iVar3) = (char)((uint)iVar5 >> 0x18);
  sha256_transf(param_1,piVar4,uVar9);
  iVar1 = 0;
  piVar4 = param_1 + 0x22;
  do {
    iVar8 = param_2 + iVar1 * 4;
    *(char *)(iVar8 + 3) = (char)*piVar4;
    *(char *)(iVar8 + 2) = (char)((uint)*piVar4 >> 8);
    *(char *)(iVar8 + 1) = (char)((uint)*piVar4 >> 0x10);
    *(undefined *)(param_2 + iVar1 * 4) = *(undefined *)((int)piVar4 + 3);
    iVar1 = iVar1 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar1 != 8);
  return;
}

