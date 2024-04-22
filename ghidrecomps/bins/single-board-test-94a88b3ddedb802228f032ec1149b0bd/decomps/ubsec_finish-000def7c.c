
undefined4 ubsec_finish(void)

{
  void **ppvVar1;
  DSO *dso;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  ppvVar1 = DAT_000deffc;
  if (*DAT_000deffc != (void *)0x0) {
    CRYPTO_free(*DAT_000deffc);
  }
  dso = (DSO *)ppvVar1[2];
  *ppvVar1 = (void *)0x0;
  ppvVar1 = DAT_000deffc;
  if (dso == (DSO *)0x0) {
    pvVar4 = DAT_000deffc[1];
    if (pvVar4 == (void *)0x0) {
      pvVar4 = (void *)ERR_get_next_error_library();
      ppvVar1[1] = pvVar4;
    }
    ERR_put_error((int)pvVar4,0x68,0x69,DAT_000df000,0x203);
    uVar3 = 0;
  }
  else {
    iVar2 = DSO_free(dso);
    if (iVar2 == 0) {
      pvVar4 = ppvVar1[1];
      if (pvVar4 == (void *)0x0) {
        pvVar4 = (void *)ERR_get_next_error_library();
        ppvVar1[1] = pvVar4;
      }
      ERR_put_error((int)pvVar4,0x68,0x67,DAT_000df000,0x207);
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
      ppvVar1[2] = (void *)0x0;
      ppvVar1[3] = (void *)0x0;
      ppvVar1[4] = (void *)0x0;
      ppvVar1[5] = (void *)0x0;
      ppvVar1[6] = (void *)0x0;
      ppvVar1[7] = (void *)0x0;
      ppvVar1[8] = (void *)0x0;
      ppvVar1[9] = (void *)0x0;
      ppvVar1[10] = (void *)0x0;
      ppvVar1[0xb] = (void *)0x0;
      ppvVar1[0xc] = (void *)0x0;
      ppvVar1[0xd] = (void *)0x0;
      ppvVar1[0xe] = (void *)0x0;
      ppvVar1[0xf] = (void *)0x0;
    }
  }
  return uVar3;
}

