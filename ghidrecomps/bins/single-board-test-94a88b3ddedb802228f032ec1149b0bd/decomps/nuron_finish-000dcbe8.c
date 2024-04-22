
undefined4 nuron_finish(void)

{
  void **ppvVar1;
  DSO *dso;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  ppvVar1 = DAT_000dcc48;
  if (*DAT_000dcc48 != (void *)0x0) {
    CRYPTO_free(*DAT_000dcc48);
  }
  dso = (DSO *)ppvVar1[2];
  *ppvVar1 = (void *)0x0;
  ppvVar1 = DAT_000dcc48;
  if (dso == (DSO *)0x0) {
    pvVar4 = DAT_000dcc48[1];
    if (pvVar4 == (void *)0x0) {
      pvVar4 = (void *)ERR_get_next_error_library();
      ppvVar1[1] = pvVar4;
    }
    ERR_put_error((int)pvVar4,0x65,0x69,DAT_000dcc4c,0x9c);
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
      ERR_put_error((int)pvVar4,0x65,0x66,DAT_000dcc4c,0xa0);
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
      ppvVar1[2] = (void *)0x0;
      ppvVar1[3] = (void *)0x0;
    }
  }
  return uVar3;
}

