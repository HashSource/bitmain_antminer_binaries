
undefined4 tls12_get_psigalgs(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x98);
  uVar2 = *(uint *)(iVar1 + 0x38) & 0x30000;
  if (uVar2 == 0x20000) {
    *param_2 = DAT_00070cf8;
    return 2;
  }
  if (uVar2 == 0x30000) {
    *param_2 = DAT_00070cf4;
    return 4;
  }
  if (uVar2 == 0x10000) {
    *param_2 = DAT_00070cf4;
    return 2;
  }
  if ((*(int *)(param_1 + 0x24) != 0) && (*(int *)(iVar1 + 0x134) != 0)) {
    *param_2 = *(int *)(iVar1 + 0x134);
    return *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x138);
  }
  if (*(int *)(iVar1 + 300) != 0) {
    *param_2 = *(int *)(iVar1 + 300);
    return *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x130);
  }
  *param_2 = DAT_00070cfc;
  return 0x1e;
}

