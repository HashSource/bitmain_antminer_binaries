
undefined4 hwcrhk_finish(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar1 = DAT_000dc2a8;
  if ((void *)DAT_000dc2a8[6] != (void *)0x0) {
    CRYPTO_free((void *)DAT_000dc2a8[6]);
  }
  puVar1[6] = 0;
  puVar2 = DAT_000dc2a8;
  if (puVar1[8] == 0) {
    iVar3 = DAT_000dc2a8[7];
    if (iVar3 == 0) {
      iVar3 = ERR_get_next_error_library();
      puVar2[7] = iVar3;
    }
    uVar4 = 0;
    ERR_put_error(iVar3,0x65,0x6b,DAT_000dc2ac,0x288);
  }
  else {
    (*(code *)DAT_000dc2a8[9])(DAT_000dc2a8[5]);
    iVar3 = DSO_free((DSO *)puVar2[8]);
    if (iVar3 == 0) {
      iVar3 = puVar2[7];
      if (iVar3 == 0) {
        iVar3 = ERR_get_next_error_library();
        puVar2[7] = iVar3;
      }
      uVar4 = 0;
      ERR_put_error(iVar3,0x65,0x68,DAT_000dc2ac,0x28e);
    }
    else {
      uVar4 = 1;
    }
  }
  if ((BIO *)puVar1[0x11] != (BIO *)0x0) {
    BIO_free((BIO *)puVar1[0x11]);
  }
  puVar1[8] = 0;
  puVar1[1] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  *puVar1 = 0;
  puVar1[0xf] = 0;
  puVar1[0xe] = 0;
  return uVar4;
}

