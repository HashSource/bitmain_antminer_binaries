
undefined4 ibm_4758_cca_finish(void)

{
  undefined4 *puVar1;
  DSO *dso;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_000d8df0;
  if ((void *)DAT_000d8df0[4] != (void *)0x0) {
    CRYPTO_free((void *)DAT_000d8df0[4]);
  }
  dso = (DSO *)puVar1[5];
  puVar1[4] = 0;
  puVar1 = DAT_000d8df0;
  if (dso == (DSO *)0x0) {
    iVar2 = DAT_000d8df0[3];
    if (iVar2 == 0) {
      iVar2 = ERR_get_next_error_library();
      puVar1[3] = iVar2;
    }
    ERR_put_error(iVar2,0x65,0x6a,DAT_000d8df4,0x15b);
    uVar3 = 0;
  }
  else {
    iVar2 = DSO_free(dso);
    if (iVar2 == 0) {
      iVar2 = puVar1[3];
      if (iVar2 == 0) {
        iVar2 = ERR_get_next_error_library();
        puVar1[3] = iVar2;
      }
      ERR_put_error(iVar2,0x65,0x6c,DAT_000d8df4,0x15f);
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
      puVar1[5] = 0;
      puVar1[6] = 0;
      *puVar1 = 0;
      puVar1[7] = 0;
      puVar1[8] = 0;
      puVar1[9] = 0;
      puVar1[2] = 0;
      puVar1[1] = 0;
    }
  }
  return uVar3;
}

