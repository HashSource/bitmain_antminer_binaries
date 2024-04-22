
undefined4 ssl_get_sign_pkey(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_2 + 0x10);
  iVar2 = *(int *)(param_1 + 0x98);
  if ((iVar1 << 0x1e < 0) && (*(int *)(iVar2 + 0x78) != 0)) {
    iVar1 = 2;
  }
  else if (iVar1 << 0x1f < 0) {
    if (*(int *)(iVar2 + 0x5c) == 0) {
      iVar1 = 0;
      if (*(int *)(iVar2 + 0x40) == 0) goto LAB_0007bcb6;
    }
    else {
      iVar1 = 1;
    }
  }
  else {
    if ((-1 < iVar1 << 0x19) || (*(int *)(iVar2 + 0xcc) == 0)) {
LAB_0007bcb6:
      ERR_put_error(0x14,0xb7,0x44,DAT_0007bccc,0xa12);
      return 0;
    }
    iVar1 = 5;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(iVar2 + iVar1 * 0x1c + 0x44);
  }
  return *(undefined4 *)(iVar2 + iVar1 * 0x1c + 0x40);
}

