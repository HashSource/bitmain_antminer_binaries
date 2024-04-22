
void engine_list_cleanup(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = DAT_000a6528;
  iVar5 = *DAT_000a6528;
  while (iVar5 != 0) {
    CRYPTO_lock(9,0x1e,DAT_000a652c,0x119);
    iVar3 = *piVar1;
    iVar4 = iVar3;
    if (iVar3 != iVar5 && iVar3 != 0) {
      do {
        iVar4 = *(int *)(iVar4 + 0x6c);
      } while (iVar4 != iVar5 && iVar4 != 0);
    }
    if (iVar4 == 0) {
      ERR_put_error(0x26,0x79,0x69,DAT_000a652c,0xa6);
      ERR_put_error(0x26,0x7b,0x6e,DAT_000a652c,0x11b);
    }
    else {
      iVar4 = *(int *)(iVar5 + 0x6c);
      if (iVar4 != 0) {
        *(undefined4 *)(iVar4 + 0x68) = *(undefined4 *)(iVar5 + 0x68);
      }
      iVar2 = *(int *)(iVar5 + 0x68);
      if (iVar2 != 0) {
        *(int *)(iVar2 + 0x6c) = iVar4;
      }
      if (iVar5 == iVar3) {
        *piVar1 = *(int *)(iVar5 + 0x6c);
      }
      if (iVar5 == piVar1[1]) {
        piVar1[1] = iVar2;
      }
      engine_free_util(iVar5,0);
    }
    CRYPTO_lock(10,0x1e,DAT_000a652c,0x11e);
    iVar5 = *piVar1;
  }
  return;
}

