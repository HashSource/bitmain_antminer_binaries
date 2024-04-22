
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509_PURPOSE_cleanup(void)

{
  _STACK **pp_Var1;
  void *pvVar2;
  void *pvVar3;
  
  pvVar2 = DAT_000cbd54;
  pp_Var1 = DAT_000cbd50;
  sk_pop_free(*DAT_000cbd50,DAT_000cbd58);
  if (*(int *)((int)pvVar2 + 8) << 0x1f < 0) {
    if (*(int *)((int)pvVar2 + 8) << 0x1e < 0) {
      CRYPTO_free(*(void **)((int)pvVar2 + 0x10));
      CRYPTO_free(*(void **)((int)pvVar2 + 0x14));
    }
    CRYPTO_free(DAT_000cbd54);
  }
  pvVar3 = DAT_000cbd54;
  if (*(int *)((int)pvVar2 + 0x24) << 0x1f < 0) {
    if (*(int *)((int)pvVar2 + 0x24) << 0x1e < 0) {
      CRYPTO_free(*(void **)((int)DAT_000cbd54 + 0x2c));
      CRYPTO_free(*(void **)((int)pvVar3 + 0x30));
    }
    CRYPTO_free(DAT_000cbd5c);
  }
  pvVar3 = DAT_000cbd54;
  if (*(int *)((int)pvVar2 + 0x40) << 0x1f < 0) {
    if (*(int *)((int)pvVar2 + 0x40) << 0x1e < 0) {
      CRYPTO_free(*(void **)((int)DAT_000cbd54 + 0x48));
      CRYPTO_free(*(void **)((int)pvVar3 + 0x4c));
    }
    CRYPTO_free(DAT_000cbd60);
  }
  pvVar3 = DAT_000cbd54;
  if (*(int *)((int)pvVar2 + 0x5c) << 0x1f < 0) {
    if (*(int *)((int)pvVar2 + 0x5c) << 0x1e < 0) {
      CRYPTO_free(*(void **)((int)DAT_000cbd54 + 100));
      CRYPTO_free(*(void **)((int)pvVar3 + 0x68));
    }
    CRYPTO_free(DAT_000cbd64);
  }
  pvVar3 = DAT_000cbd54;
  if (*(int *)((int)pvVar2 + 0x78) << 0x1f < 0) {
    if (*(int *)((int)pvVar2 + 0x78) << 0x1e < 0) {
      CRYPTO_free(*(void **)((int)DAT_000cbd54 + 0x80));
      CRYPTO_free(*(void **)((int)pvVar3 + 0x84));
    }
    CRYPTO_free(DAT_000cbd68);
  }
  pvVar3 = DAT_000cbd54;
  if (*(int *)((int)pvVar2 + 0x94) << 0x1f < 0) {
    if (*(int *)((int)pvVar2 + 0x94) << 0x1e < 0) {
      CRYPTO_free(*(void **)((int)DAT_000cbd54 + 0x9c));
      CRYPTO_free(*(void **)((int)pvVar3 + 0xa0));
    }
    CRYPTO_free(DAT_000cbd6c);
  }
  pvVar3 = DAT_000cbd54;
  if (*(int *)((int)pvVar2 + 0xb0) << 0x1f < 0) {
    if (*(int *)((int)pvVar2 + 0xb0) << 0x1e < 0) {
      CRYPTO_free(*(void **)((int)DAT_000cbd54 + 0xb8));
      CRYPTO_free(*(void **)((int)pvVar3 + 0xbc));
    }
    CRYPTO_free(DAT_000cbd70);
  }
  pvVar3 = DAT_000cbd54;
  if (*(int *)((int)pvVar2 + 0xcc) << 0x1f < 0) {
    if (*(int *)((int)pvVar2 + 0xcc) << 0x1e < 0) {
      CRYPTO_free(*(void **)((int)DAT_000cbd54 + 0xd4));
      CRYPTO_free(*(void **)((int)pvVar3 + 0xd8));
    }
    CRYPTO_free(DAT_000cbd74);
  }
  pvVar3 = DAT_000cbd54;
  if (*(int *)((int)pvVar2 + 0xe8) << 0x1f < 0) {
    if (*(int *)((int)pvVar2 + 0xe8) << 0x1e < 0) {
      CRYPTO_free(*(void **)((int)DAT_000cbd54 + 0xf0));
      CRYPTO_free(*(void **)((int)pvVar3 + 0xf4));
    }
    CRYPTO_free(DAT_000cbd78);
  }
  *pp_Var1 = (_STACK *)0x0;
  return;
}

